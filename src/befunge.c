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

#include "esoteric.h"

void befunge(char __attribute__((unused)) *commands) {
  size_t i, y = 0, x = 0;
  int a, b, result;
  char ch;
  int vector = 2;
	char *display[25];
  int stack[1024];
  int symbol_mode = 0;
  int stack_pointer = 0;
  memset(stack, 0, sizeof(int)*1024);
  for (i = 0; i < 25; i++) {
    display[i] = (char *)malloc(sizeof(char)*80);
    memset(display[i], 0, sizeof(char)*80);
    if (i == 0) {
      display[i] = strtok(commands, "\n");
    } else {
      display[i] = strtok(NULL, "\n");
    }
  }
  while (display[y][x] != '@') {
    if (display[y][x] == '"') {
      symbol_mode ^= 1;
    } else if (symbol_mode) {
      stack[stack_pointer++] = (int)display[y][x];
    } else if (isdigit(display[y][x]) && !symbol_mode) {
      stack[stack_pointer++] = display[y][x] - '0';
    } else if ((display[y][x] == '+' || display[y][x] == '-' || display[y][x] == '*'  || display[y][x] == '/' || display[y][x] == '%') && !symbol_mode) {
      b = stack[--stack_pointer];
      a = stack[--stack_pointer];
      if (display[y][x] == '+') {
        result = a + b;
      } else if (display[y][x] == '-') {
        result = a - b;
      } else if (display[y][x] == '*') {
        result = a * b;
      } else if (display[y][x] == '/') {
        if (b == 0) {
          result = 0;
        } else {
          result = a / b;
        }
      } else if (display[y][x] == '%') {
        result = a % b;
      }
      stack[stack_pointer++] = result;
    } else if (display[y][x] == '!' && !symbol_mode) {
      a = stack[--stack_pointer];
      a = !a;
      stack[stack_pointer++] = a;
    } else if (display[y][x] == '`' && !symbol_mode) {
      a = stack[--stack_pointer];
      b = stack[--stack_pointer];
      result = b > a;
      stack[stack_pointer++] = result;
    } else if (display[y][x] == '?' && !symbol_mode) {
      a = rand() % 4 + 1;
      vector = a;
    } else if (display[y][x] == ':' && !symbol_mode) {
      a = stack[--stack_pointer];
      stack[stack_pointer++] = a;
      stack[stack_pointer++] = a;
    } else if (display[y][x] == '\\' && !symbol_mode) {
      a = stack[--stack_pointer];
      b = stack[--stack_pointer];
      stack[stack_pointer++] = a;
      stack[stack_pointer++] = b;
    } else if (display[y][x] == '#' && !symbol_mode) {
      if (vector == 1) {
        y -= 1;
      } else if (vector == 2) {
        x += 1;
      } else if (vector == 3) {
        y += 1;
      } else if (vector == 4) {
        x -= 1;
      }
    } else if (display[y][x] == ',' && !symbol_mode) {
      a = stack[--stack_pointer];
      printf("%c", a);
    } else if (display[y][x] == '.' && !symbol_mode) {
      a = stack[--stack_pointer];
      printf("%d", a);
    } else if (display[y][x] == '_' && !symbol_mode) {
      a = stack[--stack_pointer];
      vector = (!a) ? 2 : 4;
    } else if (display[y][x] == '|' && !symbol_mode) {
      a = stack[--stack_pointer];
      vector = (!a) ? 3 : 1;
    } else if (display[y][x] == '$' && !symbol_mode) {
      stack[--stack_pointer] = 0;
    } else if (display[y][x] == '~' && !symbol_mode) {
      scanf("%c", &ch);
      stack[stack_pointer++] = (int)ch;
    } else if (display[y][x] == '&' && !symbol_mode) {
      scanf("%d", &a);
      stack[stack_pointer++] = a;
    } else if (display[y][x] == 'p' && !symbol_mode) {
      a = stack[--stack_pointer];
      b = stack[--stack_pointer];
      result = stack[--stack_pointer];
      display[a][b] = (char)result;
    } else if (display[y][x] == 'g' && !symbol_mode) {
      a = stack[--stack_pointer];
      b = stack[--stack_pointer];
      result = display[a][b];
      stack[stack_pointer++] = (int)result;
    } else if (display[y][x] == '>' && !symbol_mode) {
      vector = 2;
    } else if (display[y][x] == '<' && !symbol_mode) {
      vector = 4;
    } else if (display[y][x] == '^' && !symbol_mode) {
      vector = 1;
    } else if (display[y][x] == 'v' && !symbol_mode) {
      vector = 3;
    }
    if (vector == 1) {
      y -= 1;
    } else if (vector == 2) {
      x += 1;
    } else if (vector == 3) {
      y += 1;
    } else if (vector == 4) {
      x -= 1;
    }
    /*printf("Iteration = %lu\n\n", x);
    for (i = 0; i < (size_t)stack_pointer; i++) {
      printf("stack[%lu] = %d\n", i, stack[i]);
    }
    printf("\n");*/
  }
}
