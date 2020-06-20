#ifndef LIB_UTILS_H
#define LIB_UTILS_H 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void brainfuck(char*);
extern void hq9(char*);
extern void malbolge(char*);
extern void ook(char*);
extern void spoon(char*);

char** split(char* line);
char* upper(char* str);
void exec(char* func, char* commands);
void error(char* msg, ...);

#ifdef __cplusplus
}
#endif

#endif