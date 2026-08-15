# Making the `interview` skill generic

Goal: let others fork/reuse this skill for their own language and repo, with
solutions that stay submittable on LeetCode as-is (or with minimal edits).

The interviewer logic itself — hint ladder, clarifying-questions phase,
never-solve-it rules, tone, wrap-up flow — is already language/repo-agnostic.
Everything below is what's currently hardcoded to this repo and C#/.NET.

## 1. Per-repo config file

Add `.interview.json` at the target repo root (not inside `.claude/skills/`,
so it travels with a fork rather than staying bound to this skill's copy).
The skill reads this instead of assuming C#/.NET. Fields:

- `language` — e.g. `csharp`, `python`
- `scaffoldCommand` — script/command to create solution + test files for a
  new problem (e.g. `./create_problem.sh`, or a Python equivalent)
- `testCommand` — template for running tests for one problem
  (e.g. `dotnet test --filter "{ProblemName}Tests"`)
- `solutionPath` / `testPath` — path templates for the generated files
- `snippetField` — which field to pull from the LeetCode GraphQL response
  for the starter snippet (`csharpSnippet`, `pythonSnippet`, etc.)
- `planPath` — path to the problem plan file (see §3)
- `gitWorkflow` — `"branch-per-problem"` | `"none"` (see §4)

## 2. Language scaffolding

`create_problem.sh` is C#/.NET-specific. Each supported language needs its
own scaffold script/template:

- Python: `uv init`-based, `pytest` test stub, `Solution` class matching
  LeetCode's Python method signature
- Others as requested

`fetch_leetcode_problem.sh` already gets multiple language snippets back
from LeetCode's GraphQL response (we only extract `csharpSnippet` today) —
extracting the right one per `snippetField` is a small change, not a rewrite.

**LeetCode-submittable constraint:** each language's solution template must
keep the LeetCode class/method shape close enough to paste back in one edit
(e.g. avoid repo-specific namespace/module wrapping that can't be stripped
trivially). Worth writing this as an explicit rule per language template,
the way `CLAUDE.md` documents it for C# today.

## 3. Plan source — init flow + companion "plan" skill

Replace the hardcoded `INTERVIEW_PLAN.md` assumption with an init procedure:

1. Ask what the candidate is preparing for.
2. Ask: do they already have a plan (point to its path — becomes
   `planPath` in `.interview.json`), or do they need one generated?
3. If generating, hand off to a new companion skill (e.g. `interview-plan`)
   that builds a plan file in the same checked-off-row format this repo's
   `INTERVIEW_PLAN.md` uses.
4. Detect whether a solutions repo already exists; if not, offer to
   scaffold one for the chosen language (dirs, test runner, gitignore).

## 4. Git/PR workflow — make optional

The wrap-up section assumes branch-per-problem + PR-to-master via `gh`.
That's a personal convention, not universal. Gate it behind
`gitWorkflow` in the config:

- `"branch-per-problem"` — current behavior (branch, push, PR, wait for CI,
  confirm, merge)
- `"none"` — just leave the files as committed/uncommitted locally, skip
  branch/PR/merge steps entirely

## 5. Rewrite SKILL.md against the config

Once the above exists, `SKILL.md` steps 2–4, code verification, and wrap-up
get rewritten to read from `.interview.json` instead of hardcoding
`dotnet test`, `create_problem.sh`, and the branch/PR flow. The interviewer
rules (§ "Your interviewer rules", clarifying questions, hint ladder, tone)
stay untouched.

## Suggested order

1. Define `.interview.json` schema and add one for this repo (C#/.NET,
   `branch-per-problem`), so the skill has one working example to develop
   against without behavior changes.
2. Rewrite `SKILL.md` to read from the config instead of hardcoding C#.
   Verify this repo's interview flow still works identically.
3. Add a second language (Python via `uv`/`pytest`) as the real test of
   genericity.
4. Split out the plan-generation flow into its own skill.
5. Write a short init flow / README for first-time setup in a new repo.
