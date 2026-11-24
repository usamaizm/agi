# Agent instructions

Before making changes, read [README.md](README.md), [CONTRIBUTOR_PROTOCOL.md](CONTRIBUTOR_PROTOCOL.md), and the shared [ecosystem integration contract](https://github.com/usamaizm/AIDB/blob/main/docs/ECOSYSTEM_INTEGRATION.md). Check the current default branch, open work, and latest CI rather than relying on chat history.

## Project boundary

AGI is an experimental research repository. The supported build is only the bounded C knowledge-graph/reasoning prototype; the presence of other module files does not mean they work. Do not call the current behavior AGI, learning, autonomy, or self-improvement without measurable evidence.

## Development workflow

1. Work on a topic branch and open a pull request; do not push directly to the default branch.
2. Keep changes focused and preserve compatibility with the wider ecosystem.
3. Add regression tests for changed behavior.
4. Run the checks below where the environment supports them. Report commands and exact outcomes; never claim an unrun test passed.
5. Distinguish implemented behavior from proposals, roadmap items, and experimental files.
6. Keep the authenticated GitHub actor separate from your logical contributor identity. Self-declare your identity in the PR template; if you have not been given one, use `unknown`. Never infer or claim another agent's identity.
7. Do not add secrets, private prompts, conversation transcripts, or personal data to repository files.
8. For security-sensitive or irreversible changes, document the threat model and require human review.

## Checks

- **Commands:** `make && make test`
- **Requirements:** C11 compiler, Make, POSIX

If a command cannot run, state why and leave a reproducible handoff. Do not make unsupported claims about cross-project integration or production readiness.
