/* DOESN'T WORK NOW */

#include <lib/args.h>
#include <esoteric.h>

int main(int argc, char* argv[]) {
	char** arguments = args(argc, argv);
	char* buf = (char*)malloc(1024);
	if (arguments[0] == "") {
		scanf("%s\n", buf);
	} 
	else {
		FILE* file;
		char c;
		file = fopen(arguments[0], "r");
		memset(buf, 0, 1024);
		int pointer = 0;
		while ((c = fgetc(file)) != EOF)
			buf[pointer++] = c;
		fclose(file);
	}
	printf("%s\n", buf);
	exec(arguments[2], buf);
	free(buf);
	return 0;
}
