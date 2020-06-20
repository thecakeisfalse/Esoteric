#ifndef ESOTERIC_OOK_H
#define ESOTERIC_OOK_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esoteric/brainfuck.h>

#ifdef __cplusplus
extern "C" {
#endif

char* ook2bf(char* commands);
void ook(char* commands);

#ifdef __cplusplus
}
#endif

#endif