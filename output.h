#ifndef OUTPUT_H
#define OUTPUT_H

void output_init(void);               // optional setup
void output_print(const char* text);  // main output function (console for now)
void output_log(const char* text);    // to file or persistent log
void output_cleanup(void);

#endif