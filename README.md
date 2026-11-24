# AGI

An experimental software project exploring components that may contribute to an artificial general intelligence system.

## Status

**Early-stage research and implementation.** The repository contains a C-oriented codebase with modules for input/output, language, knowledge representation, reasoning, vision, audio, speech, data, and application orchestration. The presence of a module does not by itself imply production readiness or human-level general intelligence.

## Repository map

- `main.c`, `main.h` — application entry point and coordination
- `agi.*`, `ai.*` — top-level interfaces
- `reasoning.*`, `knowledge.*`, `knowledge_graph.*` — reasoning and knowledge experiments
- `language.*`, `text.*` — language and text handling
- `vision.*`, `audio.*`, `speech.*`, `speech2text.*`, `text2speech.*` — perception and speech-related modules
- `input.*`, `output.*`, `io.*` — interaction and I/O
- `data.*`, `model.*`, `module.*` — data, model, and module infrastructure
- `cmake/`, `make/`, `src/`, `source/`, `lib/`, `libraries/` — build and implementation support

This map is descriptive; interfaces and implementation status must be confirmed against source and tests.

## Development principles

1. Prefer small, testable modules with documented interfaces.
2. Separate experimental capabilities from verified behavior.
3. Avoid claiming general intelligence, autonomy, safety, or reliability without reproducible evidence.
4. Document dependencies, build steps, platform support, and known limitations.
5. Keep data handling, model execution, and external-device access explicit and reviewable.

## Getting started

Build instructions are not yet documented consistently. Before publishing a release, establish one supported build path, list required dependencies, and add a clean-checkout build/test workflow. Do not assume that a successful compile proves an AGI capability.

## Roadmap

See [ROADMAP.md](ROADMAP.md) for proposed milestones.

## License

See [LICENSE](LICENSE) for the repository's license and applicable notices.
