/* DOESN'T WORK NOW */

#include <lib/args.h>
#include <esoteric.h>

int main(int argc, char* argv[]) {
char** arguments = args(argc, argv);
	char* buf = (char*)malloc(1024), *tmp = (char*)malloc(512);
	memset(buf, 0, 1024);
	if (strcmp(arguments[1], "") == 0) {
		printf("lang> ");
		scanf("%s", tmp);
		arguments[1] = tmp;
	}
	if (strcmp(arguments[0], "") == 0) {
		printf("%s> ", arguments[1]);
		scanf("%s", buf);
	} else {
		FILE* file;
		char c;
		file = fopen(arguments[0], "r");
		int pointer = 0;
		while ((c = fgetc(file)) != EOF)
			buf[pointer++] = c;
		fclose(file);
	}
	printf("%s\n", buf);
	exec(arguments[1], buf);
	free(tmp);
	free(buf);
	return 0;
}
