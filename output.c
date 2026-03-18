#include "output.h"
#include <stdio.h>

static FILE* log_file = NULL;

void output_init(void) {
    log_file = fopen("agi_log.txt", "a");
    if (!log_file) {
        fprintf(stderr, "Failed to open log file\n");
    }
}

void output_print(const char* text) {
    if (text) {
        printf("%s\n", text);
        fflush(stdout);
    }
}

void output_log(const char* text) {
    if (log_file && text) {
        fprintf(log_file, "%s\n", text);
        fflush(log_file);
    }
}

void output_cleanup(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}