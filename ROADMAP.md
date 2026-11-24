# AGI Roadmap

This roadmap is provisional. It describes engineering milestones, not a promise that the system will achieve artificial general intelligence.

## Stage 0 — Establish a reproducible baseline
- [ ] Identify the canonical build system and supported compiler versions.
- [ ] Document dependencies and platform support.
- [ ] Build from a clean checkout.
- [ ] Record current warnings, failures, and known limitations.
- [ ] Add automated formatting, static analysis, and test workflows where practical.

## Stage 1 — Stabilize module contracts
- [ ] Document public headers and ownership of shared data.
- [ ] Define error handling and memory ownership conventions.
- [ ] Separate interfaces from experimental implementations.
- [ ] Add focused unit tests for each module.

## Stage 2 — Establish a reliable core
- [ ] Define application lifecycle and configuration.
- [ ] Add structured logging and diagnostic output.
- [ ] Define explicit interfaces for model and external-service adapters.
- [ ] Add deterministic test fixtures and sample inputs.

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
