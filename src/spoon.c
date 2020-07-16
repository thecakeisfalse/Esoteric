#include "esoteric.h"

char* spoon2bf(char* commands) {
	char* buf = malloc(sizeof(char)*strlen(commands));
	for (int j = 0, i = 0; i < strlen(commands); i++) {
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
	}
	return buf;
}

void spoon(char* commands) {
	char* buf = spoon2bf(commands);
	brainfuck(buf);
}
