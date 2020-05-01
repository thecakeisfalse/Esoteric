#include <lib/utils.h>

char* languages_str[] = {
	"brainfuck",
	"hq9",
	"malbolge",
	"ook",
	"spoon"
};

void (*languages_func[])(char*) = {
	&brainfuck,
	&hq9,
	&malbolge,
	&ook,
	&spoon
};

char** split(char* line) {
	char* token = strtok(line, " \t\a\r\n");
	char** tokens = (char**)malloc(64 * sizeof(char*));
	int pointer = 0;
	while (token != NULL) {
		tokens[pointer] = token;
		pointer++;
		token = strtok(line, " \t\a\r\n");
	}
	return tokens;
}

char* upper(char* str) {
	int flag = 1;
	char* buf = (char*)malloc(sizeof(char)*strlen(str));
	for (int i = 0; i < strlen(str); i++) {
		if (flag && str[i] >= 'a' && str[i] <= 'z' && str[i-1] != '%' && str[i+1] != '=') {
			buf[i] = str[i] - 32;
		} else if (str[i] == '!') {
			flag = 0;
		} else {
			buf[i] = str[i];
		}
	}
	return buf;
}

void error(char* msg, ...) {
    va_list args;
    va_start(args, msg);
    msg = upper(msg);
    printf("ERROR!!! ");
    vprintf(msg, args);
    putchar('\n');
    va_end(args);
	exit(1);
}

void exec(char* func, char* commands) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(func, languages_str[i]) == 0) {
			return (*languages_func[i])(commands);
		}
	}
}