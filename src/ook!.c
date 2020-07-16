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

char* ook2bf(char* commands) {
	int length = (strlen(commands) + 1) / 10;
	char* buf = malloc(sizeof(char) * length * 2);
	for (int j = 0, i = 0; i < strlen(commands); i++) {
		if (commands[i] == '!' || commands[i] == '.' || commands[i] == '?')
			buf[j++] = commands[i];
	}
	char* text = malloc(sizeof(char)*length);
	for (int j = 0, i = 0; i < length*2; i++) {
		if(buf[i] == '.') {
			i++;
			if (buf[i] == '.') {
				text[j++] = '+';
			} else if (buf[i] == '?') {
				text[j++] = '>';
			} else if (buf[i] == '!') {
				text[j++] = ',';
			}
		} else if (buf[i] == '?') {
			i++;
			if (buf[i] == '.') {
				text[j++] = '<';
			} else if (buf[i] == '!') {
				text[j++] = ']';
			}
		} else if (buf[i] == '!') {
			i++;
			if (buf[i] == '.') {
				text[j++] = '.';
			} else if (buf[i] == '?') {
				text[j++] = '[';
			} else if (buf[i] == '!') {
				text[j++] = '-';
			}
		}
	}
	free(buf);
	return text;
}

void ook(char* commands) {
	char* text = ook2bf(commands);
	brainfuck(text);
}
