#include "esoteric.h"

char* get_file_expansion(char *filename) {
    unsigned int start = 0, stop;
    for (stop = 0; filename[stop]; stop++) {
        if (filename[stop] == '.') {
            start = stop + 1;
        }
    }
		return filename+start;
}

char* read_file(char *filename) {
	FILE* file = fopen(filename, "r");
	int pointer = 0;
	char* content = (char*)malloc(4096*sizeof(char));
	char ch;
	while ((ch = fgetc(file)) != EOF) {
		content[pointer++] = ch;
	}
	return content;
}

int main(int argc, char* argv[]) {
	char *expansion = get_file_expansion(argv[argc-1]);
	char *content = read_file(argv[argc-1]);
	if (strcmp(expansion, "mal") == 0 || strcmp(expansion, "mb") == 0) {
		malbolge(content);
	} else if (strcmp(expansion, "bf") == 0 || strcmp(expansion, "b") == 0) {
		brainfuck(content);
	} else if (strcmp(expansion, "ook") == 0 || strcmp(expansion, "ok") == 0) {
		ook(content);
	} else if (strcmp(expansion, "sp") == 0) {
		spoon(content);
	} else {
		hq9(content);
	}
	return 0;
}
