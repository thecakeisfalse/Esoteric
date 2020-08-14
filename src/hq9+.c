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
 * Interpreters HQ9+ commands.
 *
 * @param commands Contain HQ9+ commands.
 */
void hq9(char *commands) {
	int accumulator = 0;
	size_t i = 0;
	int j = 0;
	while (i < strlen(commands)) {
		if (commands[i] == 'H') {
			printf("Hello, world!\n");
		} else if (commands[i] == 'Q') {
			printf("%s\n", commands);
		} else if (commands[i] == '9') {
			j = 99;
			while (j > 1) {
				printf("%d bottles of beer on the wall,\n", j);
				printf("%d bottles of beer.\n", j);
				printf("Take one down, pass it around,\n");
				printf("%d bottles of beer on the wall.\n\n", j - 1);
				j--;
			}
			printf("1 bottle of beer on the wall,\n1 bottle of beer.\nTake one down, pass it around,\nno more bottles of beer on the wall.\n");
		} else if (commands[i] == '+') {
			accumulator++;
		}
		i++;
	}
}
