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
	char *buf = malloc(sizeof(char)*strlen(commands));
	size_t i = 0, j = 0;
	while (i < strlen(commands)) {
		if (commands[i] == '1') {
			buf[j++] = '+';
		} else if (commands[i] == '0') {
			i++;
			if (commands[i] == '0') {
				i++;
				if (commands[i] == '0') {
					buf[j++] = '-';
				} else if (commands[i] == '1') {
					i++;
					if (commands[i] == '0') {
						i++;
						if (commands[i] == '0') {
							buf[j++] = '[';
						} else if (commands[i] == '1') {
							i++;
							if (commands[i] == '0') {
								buf[j++] = '.';
							} else if (commands[i] == '1') {
								buf[j++] = ',';
							}
						}
					} else if (commands[i] == '1') {
						buf[j++] = ']';
					}
				}
			} else if (commands[i] == '1') {
				i++;
				if (commands[i] == '0') {
					buf[j++] = '>';
				} else if (commands[i] == '1') {
					buf[j++] = '<';
				}
			}
		}
		i++;
	}
	return buf;
}

void spoon(char* commands) {
	char* buf = spoon2bf(commands);
	brainfuck(buf);
}
