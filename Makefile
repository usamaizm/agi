CC ?= cc
CFLAGS ?= -std=c11 -D_POSIX_C_SOURCE=200809L -Wall -Wextra -Wpedantic -O2
CPPFLAGS ?= -I.
TARGET := agi
SOURCES := main.c knowledge_graph.c reasoning.c

.PHONY: all test clean
all: $(TARGET)

$(TARGET): $(SOURCES) knowledge_graph.h reasoning.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SOURCES) -o $@

test: tests/test_knowledge_graph
	./tests/test_knowledge_graph

tests/test_knowledge_graph: tests/test_knowledge_graph.c knowledge_graph.c knowledge_graph.h
	$(CC) $(CPPFLAGS) $(CFLAGS) tests/test_knowledge_graph.c knowledge_graph.c -o $@

clean:
	rm -f $(TARGET) tests/test_knowledge_graph state.kb
