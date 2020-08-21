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
	char *expansion;
	char *filename;
	char *content;
	if (argc < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 0;
	}
	if (!file_exists(argv[1])) {
		perror(argv[1]);
		return 1;
	}
	content = read_file(argv[1]);
	expansion = get_file_expansion(argv[1]);
	filename = get_file_name(argv[1]);
	if (strcmp(expansion, "mal") == 0 || strcmp(expansion, "mb") == 0) {
		malbolge(content);
	} else if (strcmp(expansion, "bf") == 0 || strcmp(expansion, "b") == 0) {
		FILE *file = fopen(filename, "w+");
		brainfuck_to_c(content, file);
		fclose(file);
	} else if (strcmp(expansion, "ook") == 0 || strcmp(expansion, "ok") == 0) {
		FILE *file = fopen(filename, "w+");
		brainfuck_to_c(ook2bf(content), file);
		fclose(file);
	} else if (strcmp(expansion, "sp") == 0) {
		FILE *file = fopen(filename, "w+");
		brainfuck_to_c(spoon2bf(content), file);
		fclose(file);
	} else {
		hq9(content);
	}
	return 0;
}

/*
 * Check if a file exists
 *
 * @param filename Name of the file.
 * @return 1 if the file exists otherwise return 0.
 */
int file_exists(char *filename) {
	struct stat st;
	return stat(filename, &st) == 0;
}

/*
 * Get file name.
 *
 * @param filename Name of the file.
 * @return File name.
 */
char *get_file_name(char *filename) {
	unsigned int start = 0, stop;
	char *temp = (char *)malloc(sizeof(char)*1024);
	strcpy(temp, filename);
	for (stop = 0; temp[stop]; stop++) {
		if (temp[stop] == '.') {
			start = stop;
		}
	}
	temp[start] = 0;
	start = 0;
	for (stop = 0; temp[stop]; stop++) {
		if (temp[stop] == '/') {
			start = stop+1;
		}
	}
	strcat(temp, ".c");
	return temp+start;
}

/*
 * Get file extension.
 *
 * @param filename Name of the file.
 * @return File extension.
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
