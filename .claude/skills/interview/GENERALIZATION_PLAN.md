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

## 6. Timed interviews

Optional per-session timer, driven by `timeLimitMinutes` in `.interview.json`
(or asked at session start if unset — "Want to time this one? How many
minutes?"). No polling loop needed — Claude Code already has the pieces:

- **Countdown mechanism:** a small background script, started with
  `run_in_background: true` when the candidate begins coding (after step 7,
  "take your time... edit Solution.cs"). It sleeps to each checkpoint and
  echoes a line at each one (e.g. `5 minutes remaining`, `1 minute
  remaining`, `time is up`), plus a final line at the full deadline. Each
  echoed line surfaces back into the session as a notification — no manual
  polling, no repeated `sleep` calls from Claude itself.
- **In-session surfacing:** use `Monitor` on the backgrounded process so
  each checkpoint line lands in the transcript as it happens, and the
  interviewer can react appropriately (e.g. at `time is up`, ask the
  candidate to wrap up their current thought rather than cutting them off
  mid-sentence — matches the "professional, neutral" tone already defined).
- **Out-of-session surfacing:** call `PushNotification` at the same
  checkpoints so the candidate is pulled back even if they've stopped
  watching the terminal. Needs verification before relying on it: the tool
  is documented to skip sending when the user is actively at the terminal
  (to avoid duplicate/redundant pings), which is the opposite of what a
  timed interview wants for the 5-minute warning — confirm at
  implementation time whether that skip is a hard rule or a soft
  heuristic, and if hard, fall back to the in-transcript `Monitor` message
  as the only signal while the user is active.
- **Cleanup:** kill the background timer (`TaskStop` or equivalent) once
  the candidate signals "done" and tests are verified, so a stale timer
  doesn't keep firing checkpoints into an already-finished problem.
- **Config additions to `.interview.json`:** `timeLimitMinutes` (optional;
  omit for untimed sessions, the default today) and `timerCheckpoints`
  (optional list of minutes-remaining values to notify at; sensible default
  e.g. `[5, 1, 0]`).
- **SKILL.md changes:** add a step between "present the problem" and "wait
  for the candidate to write their thoughts" to start the timer if
  configured/requested, and a rule under "Your interviewer rules" for how
  to react at each checkpoint (warn, don't stop them; at `0` ask them to
  wrap up, but let them finish if they're mid-fix — a real interviewer
  doesn't yank the pen out of your hand).

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
6. Add timed interviews (§6): background timer + `Monitor` +
   `PushNotification`, gated behind `timeLimitMinutes` so untimed sessions
   are unaffected.
