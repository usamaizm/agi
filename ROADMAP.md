# AGI Roadmap

This roadmap is provisional. It describes engineering milestones, not a promise that the system will achieve artificial general intelligence.

## Stage 0 — Establish a reproducible baseline
- [x] Establish a canonical Makefile build path targeting C11.
- [ ] Publish an exact supported compiler-version and platform matrix.
- [x] Document the initial compiler, Make, and POSIX build requirements.
- [x] Build from a clean checkout in GitHub Actions.
- [x] Record the supported prototype's limitations in the README.
- [x] Add automated CI and focused knowledge-graph tests.

## Stage 1 — Stabilize module contracts
- [x] Document ownership of strings returned by the supported knowledge-graph and reasoning APIs.
- [ ] Standardize error handling across all modules; the current core still uses mixed return conventions.
- [ ] Separate interfaces from experimental implementations.
- [ ] Add focused unit tests for every module before it enters the supported build.

## Stage 2 — Establish a reliable core
- [x] Define a bounded application lifecycle and cleanup path for the current prototype.
- [x] Add explicit persistence error reporting and malformed-state rollback for the knowledge graph.
- [ ] Add structured logging and diagnostic output.
- [ ] Define explicit interfaces for model and external-service adapters.
- [ ] Expand deterministic test fixtures beyond the knowledge graph.

## Stage 3 — Integrate capabilities incrementally
- [ ] Integrate language, knowledge, reasoning, vision, and audio components behind tested interfaces.
- [ ] Measure capability-specific performance and limitations.
- [ ] Add end-to-end tests for supported workflows.
- [ ] Document safety boundaries and human oversight requirements.

## Stage 4 — Research and evaluation
- [ ] Publish reproducible evaluation tasks and baselines.
- [ ] Track regressions and failure modes.
- [ ] Distinguish demonstrated capabilities from research hypotheses.
- [ ] Review security, privacy, and misuse risks before broader deployment.

## Release criteria

A milestone is complete only when its implementation, tests, documentation, and limitations are present in the repository. No milestone should be described as achieving AGI without a clear, independently reviewable evaluation standard.
