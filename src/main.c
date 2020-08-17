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

int main(int argc, char *argv[]) {
	char *expansion = get_file_expansion(argv[argc-1]);
	char *content = read_file(argv[argc-1]);
	FILE *file = fopen("output.c", "w");
	if (strcmp(expansion, "mal") == 0 || strcmp(expansion, "mb") == 0) {
		malbolge(content);
	} else if (strcmp(expansion, "bf") == 0 || strcmp(expansion, "b") == 0) {
		brainfuck_to_c(content, file);
	} else if (strcmp(expansion, "ook") == 0 || strcmp(expansion, "ok") == 0) {
		ook(content);
	} else if (strcmp(expansion, "sp") == 0) {
		spoon(content);
	} else {
		hq9(content);
	}
	fclose(file);
	return 0;
}

/*
 * Get file extension.
 *
 * @param commands Name of the file.
 * @returh File extension.
 */
char *get_file_expansion(char *filename) {
	unsigned int start = 0, stop;
	for (stop = 0; filename[stop]; stop++) {
		if (filename[stop] == '.') {
			start = stop + 1;
		}
	}
	return filename+start;
}

/*
 * Get file content.
 *
 * @param commands Name of the file.
 * @returh File content.
 */
char *read_file(char *filename) {
	int size;
	char *buffer;
	FILE *file;
	file = fopen(filename, "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	buffer = (char*)malloc(sizeof(char)*size);
	fread(buffer, size, sizeof(char), file);
	fclose(file);
	return buffer;
}
