#include "knowledge_graph.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    assert(kg_init() == 0);
    assert(kg_add("agent", "status", "ready") == 0);
    char *value = kg_query("agent", "status", NULL);
    assert(value != NULL);
    assert(strcmp(value, "ready") == 0);
    free(value);

    assert(kg_query("missing", NULL, NULL) == NULL);
    assert(kg_query(NULL, NULL, NULL) == NULL);
    assert(kg_add(NULL, "status", "invalid") != 0);

    for (int i = 0; i < 2000; ++i) {
        assert(kg_add("node", "index", "present") == 0);
    }
    value = kg_query("node", "index", "present");
    assert(value != NULL);
    free(value);

    char state_path[] = "/tmp/agi-kg-test-XXXXXX";
    int state_fd = mkstemp(state_path);
    assert(state_fd >= 0);
    assert(close(state_fd) == 0);
    assert(kg_save(state_path) == 0);

    kg_cleanup();
    kg_cleanup();
    assert(kg_load(state_path));
    value = kg_query("agent", "status", NULL);
    assert(value != NULL && strcmp(value, "ready") == 0);
    free(value);
    char malformed_path[] = "/tmp/agi-kg-bad-XXXXXX";
    int malformed_fd = mkstemp(malformed_path);
    assert(malformed_fd >= 0);
    FILE *malformed = fdopen(malformed_fd, "w");
    assert(malformed != NULL);
    assert(fputs("new\tpredicate\tvalue\nmalformed\n", malformed) >= 0);
    assert(fclose(malformed) == 0);
    assert(!kg_load(malformed_path));
    assert(kg_query("new", NULL, NULL) == NULL);
    assert(unlink(malformed_path) == 0);

    kg_cleanup();
    assert(unlink(state_path) == 0);

    assert(kg_init() == 0);
    kg_cleanup();
    return 0;
}
