/*
 * This file is part of Esoteric.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _ESOTERIC_H
#define _ESOTERIC_H 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void hq9(char *);
void ook(char *);
void brainfuck(char *);
void spoon(char *);
void malbolge(char *);

char *ook2bf(char *);
char *spoon2bf(char *);

void brainfuck_to_c(char *, FILE *);

char *get_file_expansion(char *);
char *read_file(char *);

#ifdef __cplusplus
}
#endif

#endif
