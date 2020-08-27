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

char *spoon2bf(char *commands) {
	size_t length = 59049;
	char *buf = malloc(sizeof(char)*length);
	size_t i, j;
	for (i = 0, j = 0; i < length; i++) {
		if (strncmp(commands+i, "1", 1) == 0) {
			buf[j++] = '+';
		} else if (strncmp(commands+i, "000", 3) == 0) {
			buf[j++] = '-';
			i += 2;
		} else if (strncmp(commands+i, "010", 3) == 0) {
			buf[j++] = '>';
			i += 2;
		} else if (strncmp(commands+i, "011", 3) == 0) {
			buf[j++] = '<';
			i += 2;
		} else if (strncmp(commands+i, "00100", 5) == 0) {
			buf[j++] = '[';
			i += 4;
		} else if (strncmp(commands+i, "0011", 4) == 0) {
			buf[j++] = ']';
			i += 3;
		} else if (strncmp(commands+i, "0010110", 7) == 0) {
			buf[j++] = ',';
			i += 6;
		} else if (strncmp(commands+i, "001010", 6) == 0) {
			buf[j++] = '.';
			i += 5;
		}
	}
	printf("%s\n", buf);
	return buf;
}

void spoon(char* commands) {
	char* buf = spoon2bf(commands);
	brainfuck(buf);
}
