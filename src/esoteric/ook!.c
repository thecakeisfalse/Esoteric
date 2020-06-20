#include <esoteric/ook!.h>

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
