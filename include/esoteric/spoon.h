#ifndef ESOTERIC_SPOON_H
#define ESOTERIC_SPOON_H 1

#include <esoteric/brainfuck.h>

#ifdef __cplusplus
extern "C" {
#endif

char* spoon2bf(char* commands);
void spoon(char* commands);

#ifdef __cplusplus
}
#endif

#endif