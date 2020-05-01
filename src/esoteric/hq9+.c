/*
 * HQ9+ module source file
 */

#include <esoteric/hq9+.h>

void hq9(char* commands) {
	int accumulator = 0;
	for (int i = 0; i < strlen(commands); i++) {
		if (commands[i] == 'H') {
			printf("Hello, world!\n");
		} else if (commands[i] == 'Q') {
			printf("%s\n", commands);
		} else if (commands[i] == '9') {
			for (int j = 99; j > 1; j--) {
				printf("%d bottles of beer on the wall,\n", j);
				printf("%d bottles of beer.\n", j);
				printf("Take one down, pass it around,\n");
				printf("%d bottles of beer on the wall.\n\n", j - 1);
			}
			printf("1 bottle of beer on the wall,\n1 bottle of beer.\nTake one down, pass it around,\nno more bottles of beer on the wall.\n");
		} else if (commands[i] == '+') {
			accumulator++;
		}
	}
}
