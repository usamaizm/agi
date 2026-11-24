# Contributor identity and attribution

This repository accepts work from people and AI agents. Attribution must distinguish the authenticated GitHub account from the logical contributor that performed the work.

## Required pull-request attribution

Every pull request should list each material contributor and include:

| Field | Meaning |
|---|---|
| Authenticated GitHub actor | Account that opened the PR or made the commit, as shown by GitHub |
| Logical contributor | Human or agent identity, stated by that contributor; use `unknown` if it cannot be established |
| Type | `human` or `agent` |
| Role | `primary`, `co_author`, `reviewer`, or `maintainer_assisted` |
| Attribution status | `self_declared`, `user_confirmed`, `maintainer_verified`, or `unknown` |
| Evidence | Relevant commits, changed files, tests, or review performed; never private prompts or credentials |

A person operating an AI agent may share one authenticated GitHub account with that agent. Record the account and the agent identity separately. Do not infer an agent's name, model, provider, version, or authorship from writing style, commit timing, or the account name.

## Agent self-identification

An AI agent contributing to this repository should state its chosen stable identity and role in the PR description. If it has not been instructed or configured with an identity, it must say `unknown` rather than inventing one. If the operator tells an agent to identify itself, the agent should include that self-declaration in the contribution record.

Do not claim that a named agent performed earlier commits unless the relevant agent or maintainer can substantiate that claim. Existing Git commit authorship and authenticated GitHub actor attribution remain unchanged.

## Provenance and safety

- Attribute only material work; do not list tools or models that did not contribute.
- Separate authorship from review, testing, and maintenance assistance.
- Never add private prompts, conversation transcripts, secrets, API keys, or personal data to the repository.
- Do not add `Co-authored-by` trailers or claim model/provider identities unless those details are explicitly configured and the contributor agrees.
- Attribution is a provenance statement, not cryptographic proof of model identity.
- Tests, code review, and maintainers' normal merge authority remain required regardless of contributor type.

## Minimal handoff

For substantial work, record changed paths, the exact verification commands and outcomes, known limitations, and the next useful action. Never report a test as passing unless a current run or local execution actually passed.
