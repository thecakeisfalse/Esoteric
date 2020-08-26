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

/*
 * Interpreters brainfuck commands.
 *
 * @param commands Contain brainfuck commands.
 */
void brainfuck(char *commands) {
  const char *p = commands;
  int buffer[30000];
  int pointer = 0;
  int counter;
  memset(buffer, 0, sizeof(buffer));
  do {
    if (*p == '[') {
      if (buffer[pointer] == 0) {
        counter = 1;
        while (counter > 0) {
          p++;
          if (*p == '[') counter++;
          if (*p == ']') counter--;
        }
      }
    }
    if (*p == ']') {
      if (buffer[pointer] != 0) {
        counter = 1;
        while (counter > 0) {
          p--;
          if (*p == '[') counter--;
          if (*p == ']') counter++;
        }
      }
    }
    if (*p == '+')
      buffer[pointer]++;
    if (*p == '-')
      buffer[pointer]--;
    if (*p == '<')
      pointer--;
    if (*p == '>')
      pointer++;
    if (*p == '.') {
      putchar(buffer[pointer]);
    }
    if (*p == ',') {
      if (pointer < 30000) {
        scanf("%d", &buffer[pointer]);
        buffer[pointer] += 48;
      }
    }
  } while (*(p++));
}

/*
 * Converts brainfuck commands to C code.
 *
 * @param commands Contain brainfuck commands.
 * @param file Contain file pointer for output file.
 */
 void brainfuck_to_c(char *commands, FILE *file) {
   const char *p = commands;
   char previous = 0;
   int count = 0;
   fprintf(file, "#include <stdio.h>\n");
   fprintf(file, "int main() {\n");
   fprintf(file, "\tint buffer[30000];\n");
   fprintf(file, "\tint pointer = 0;\n");
   do {
     if (*p == '<' || *p == '>' || *p == '-' || *p == '+') {
       do {
         count++;
         previous = *p;
         p++;
       } while (*p == previous);
       p--;
     }
     previous = *p;
     if (previous == '+') {
       if (count == 1) {
         fprintf(file, "\tbuffer[pointer]++;\n");
       } else {
         fprintf(file, "\tbuffer[pointer]+=%d;\n", count);
       }
     }
     if (previous == '-') {
       if (count == 1) {
         fprintf(file, "\tbuffer[pointer]--;\n");
       } else {
         fprintf(file, "\tbuffer[pointer]-=%d;\n", count);
       }
     }
     if (previous == '>') {
       if (count == 1) {
         fprintf(file, "\tpointer++;\n");
       } else {
         fprintf(file, "\tpointer+=%d;\n", count);
       }
     }
     if (previous == '<') {
       if (count == 1) {
         fprintf(file, "\tpointer--;\n");
       } else {
         fprintf(file, "\tpointer-=%d;\n", count);
       }
     }
     if (previous == '.')
       fprintf(file, "\tputchar(buffer[pointer]);\n");
     if (previous == ',')
       fprintf(file, "\tscanf(\"%%d\", &buffer[pointer]);\n");
     if (previous == '[')
       fprintf(file, "\twhile(buffer[pointer]) {\n");
     if (previous == ']')
       fprintf(file, "\t}\n");
     count = 0;
   } while (*(p++));
   fprintf(file, "}");
 }
