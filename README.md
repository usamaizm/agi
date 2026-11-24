# AGI

An experimental software project exploring components that may contribute to an artificial general intelligence system.

## Status

**Early-stage research and implementation.** The supported build is currently a small C prototype that stores simple subject-predicate-object triples and runs a basic reasoning step over recorded input. It is not an artificial general intelligence system.

The repository contains additional experiments for input/output, language, knowledge representation, reasoning, vision, audio, speech, data, and module orchestration. The presence of a source file does not imply that it is part of the supported build or is production-ready.

## Build and test

Requires a C11 compiler, Make, and a POSIX environment for the current getline-based persistence implementation. CI currently verifies the Ubuntu runner's default GCC toolchain.

```sh
make
make test
./agi
make clean
```

The executable runs a bounded demonstration and writes its simple knowledge-graph state to state.kb. Pass a different state-file path as the first argument to use another file. Existing plain-TSV state files remain readable; new writes use the `# AGI-KG 1` escaped format so tabs, newlines, carriage returns, and backslashes in values round-trip safely. Missing state files initialize a new graph, while malformed or unreadable existing state files stop the run instead of being silently overwritten.

## Supported prototype components

- main.c — bounded application loop.
- knowledge_graph.c / knowledge_graph.h — in-memory triples with versioned escaped persistence, legacy plain-TSV loading, malformed-file rollback, and atomic replacement on save.
- reasoning.c / reasoning.h — basic text reflection over the knowledge graph.
- tests/test_knowledge_graph.c — knowledge-graph and persistence tests.

Other modules remain experiments until they have documented interfaces, explicit ownership/lifecycle rules, tests, and inclusion in the supported build.

## Development principles

1. Prefer small, testable modules with documented interfaces.
2. Separate experimental capabilities from verified behavior.
3. Avoid claiming general intelligence, autonomy, safety, or reliability without reproducible evidence.
4. Document dependencies, build steps, platform support, and known limitations.
5. Keep data handling, model execution, and external-device access explicit and reviewable.

## Roadmap

See [ROADMAP.md](ROADMAP.md) for proposed milestones.

## Ecosystem

See the [ecosystem integration contract](https://github.com/usamaizm/AIDB/blob/main/docs/ECOSYSTEM_INTEGRATION.md) for the role of AGI and the boundaries between the related projects.

## License

See [LICENSE](LICENSE) for the repository's license and applicable notices.
