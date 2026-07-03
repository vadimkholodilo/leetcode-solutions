#!/usr/bin/env bash
# Fetch a LeetCode problem by its frontend problem number.
# Usage: ./fetch_leetcode_problem.sh <problem-number>
# Outputs JSON: { title, difficulty, content, exampleTestcases, topicTags }
# content is plain text (HTML stripped). Exits 1 on failure.

set -euo pipefail

PROBLEM_ID="${1:-}"
if [[ -z "$PROBLEM_ID" ]] || ! [[ "$PROBLEM_ID" =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <problem-number>" >&2
  exit 1
fi

MAX_RETRIES=3
RETRY_DELAY=2
GQL="https://leetcode.com/graphql"
UA="Mozilla/5.0"

# Step 1: resolve titleSlug from frontend problem number via questionList search
resolve_slug() {
  curl -s --fail -X POST "$GQL" \
    -H "Content-Type: application/json" \
    -H "User-Agent: $UA" \
    --max-time 10 \
    -d "{
      \"query\": \"query(\$cat:String!,\$limit:Int,\$skip:Int,\$filters:QuestionListFilterInput){ questionList(categorySlug:\$cat,limit:\$limit,skip:\$skip,filters:\$filters){ data{ questionFrontendId titleSlug } } }\",
      \"variables\": { \"cat\": \"\", \"limit\": 10, \"skip\": 0, \"filters\": { \"searchKeywords\": \"$PROBLEM_ID\" } }
    }"
}

# Step 2: fetch full problem details by slug
fetch_by_slug() {
  local slug="$1"
  curl -s --fail -X POST "$GQL" \
    -H "Content-Type: application/json" \
    -H "User-Agent: $UA" \
    --max-time 10 \
    -d "{
      \"query\": \"query(\$s:String!){ question(titleSlug:\$s){ title difficulty content exampleTestcases topicTags{ name } } }\",
      \"variables\": { \"s\": \"$slug\" }
    }"
}

extract_slug() {
  local json="$1" id="$2"
  echo "$json" | python3 -c "
import sys, json
data = json.load(sys.stdin)
items = (data.get('data') or {}).get('questionList', {}).get('data') or []
for item in items:
    if str(item.get('questionFrontendId', '')) == '$id':
        print(item['titleSlug'])
        sys.exit(0)
sys.exit(1)
"
}

format_problem() {
  local json="$1"
  echo "$json" | python3 -c "
import sys, json, re

def strip_html(s):
    s = re.sub(r'<[^>]+>', '', s or '')
    for ent, ch in [('&lt;','<'),('&gt;','>'),('&amp;','&'),('&nbsp;',' '),('&#39;',\"'\"),('&quot;','\"')]:
        s = s.replace(ent, ch)
    return re.sub(r'\n{3,}', '\n\n', s.strip())

data = json.load(sys.stdin)
q = (data.get('data') or {}).get('question')
if not q or not q.get('title'):
    sys.exit(1)

out = {
    'title':            q['title'],
    'difficulty':       q['difficulty'],
    'content':          strip_html(q.get('content', '')),
    'exampleTestcases': q.get('exampleTestcases', ''),
    'topicTags':        [t['name'] for t in q.get('topicTags') or []],
}
print(json.dumps(out, ensure_ascii=False, indent=2))
"
}

attempt=0
while (( attempt < MAX_RETRIES )); do
  attempt=$(( attempt + 1 ))

  slug_json=$(resolve_slug 2>/dev/null) || {
    echo "Attempt $attempt/$MAX_RETRIES: network error resolving slug." >&2
    sleep "$RETRY_DELAY"; continue
  }

  slug=$(extract_slug "$slug_json" "$PROBLEM_ID" 2>/dev/null) || {
    echo "Attempt $attempt/$MAX_RETRIES: problem #$PROBLEM_ID not found in search results." >&2
    sleep "$RETRY_DELAY"; continue
  }

  problem_json=$(fetch_by_slug "$slug" 2>/dev/null) || {
    echo "Attempt $attempt/$MAX_RETRIES: network error fetching problem details." >&2
    sleep "$RETRY_DELAY"; continue
  }

  result=$(format_problem "$problem_json" 2>/dev/null) || {
    echo "Attempt $attempt/$MAX_RETRIES: invalid or empty response." >&2
    sleep "$RETRY_DELAY"; continue
  }

  echo "$result"
  exit 0
done

echo "Failed to fetch problem #$PROBLEM_ID after $MAX_RETRIES attempts." >&2
exit 1
