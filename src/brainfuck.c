/*
 * Brainfuck module source file
 */

#include "esoteric.h"

void brainfuck(char* commands) {
	char buf[1024];
	int pointer = 0;
	memset(buf, 0, 1024*sizeof(char));
	for (int i = 0; i < strlen(commands); i++) {
		if (commands[i] == '>') {
			if (pointer < 1024)
				pointer++;
		} else if (commands[i] == '<') {
			if (pointer > 0)
				pointer--;
		} else if (commands[i] == '+') {
			if (buf[pointer] < 127)
				buf[pointer]++;
		} else if (commands[i] == '-') {
			if (buf[pointer] > 0)
				buf[pointer]--;
		} else if (commands[i] == '.') {
			printf("%c", buf[pointer]);
		} else if (commands[i] == ',') {
			scanf("%d", &buf[pointer]);
		} else if (commands[i] == '[') {
			if (buf[pointer] == 0) {
				int counter = 1;
				while (counter > 0) {
					i++;
					if (commands[i] == '[') counter++;
					if (commands[i] == ']') counter--;
				}
			}
		} else if (commands[i] == ']') {
			if (buf[pointer] != 0) {
				int counter = 1;
				while (counter > 0) {
					i--;
					if (commands[i] == '[') counter--;
					if (commands[i] == ']') counter++;
				}
			}
		}
	}
}
