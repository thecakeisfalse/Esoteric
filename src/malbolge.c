/*
 * Malbolge module
 */

#include "esoteric.h"

int TABLE_CRAZY[3][3] = {
	{1, 0, 0},
	{1, 0, 2},
	{2, 2, 1}
};

int ENCRYPT[94] = {53, 122, 93, 38, 103, 113, 116, 121, 102, 114, 36, 40, 119, 101, 52, 123, 87, 80, 41, 72, 45, 90, 110, 44, 91, 37, 92, 51, 100, 76, 43, 81, 59, 62, 85, 33, 112, 74, 83, 55, 50, 70, 104, 79, 65, 49, 67, 66, 54, 118, 94, 61, 73, 95, 48, 47, 56, 124, 106, 115, 98, 57, 109, 60, 46, 84, 86, 97, 99, 96, 117, 89, 42, 77, 75, 39, 88, 126, 120, 68, 108, 125, 82, 69, 111, 107, 78, 58, 35, 63, 71, 34, 105, 64};
int OPCODES_VALID[] = {4, 5, 23, 39, 40, 62, 68, 81};

long mem[59049];

long rotate(long n) {
	return 19683*(n%3) + n/3;
}

long crazy(long a, long b) {
	long result = 0;
	long d = 1;
	for (int i = 0; i < 10; i++) {
		result += TABLE_CRAZY[(int)((b/d)%3)][(int)((a/d)%3)] * d;
		d *= 3;
	}
	return result;
}

bool is_valid_opcode(char c, int pointer) {
	for (int i = 0; i < 8; i++) {
		if (((int)c + pointer) % 94 == OPCODES_VALID[i])
			return true;
	}
	return false;
}

void malbolge(char* commands) {
	long pointer = 0;
	for (int i = 0; i < strlen(commands); i++) {
		if (commands[i] == ' ' || commands[i] == '\n')
			continue;
		if (!is_valid_opcode(commands[i], pointer)) {
			printf("[ERROR] Invalid character! i=%d commands[%i]=%d='%c'", i, i, commands[i], commands[i]);
		}
		if (pointer == 59049) {
			printf("[ERROR] Source is too long!");
		}
		mem[pointer] = (int)commands[i];
		pointer++;
	}

	while (pointer < 59049) {
		mem[pointer] = crazy(mem[pointer-1], mem[pointer-2]);
		pointer++;
	}

	long a = 0, c = 0, d = 0;
	while (1) {
		if (mem[c] < 33 || mem[c] > 126)
			return;
		long v = (mem[c] + c) % 94;
		if (v == 4)
			c = mem[d];
		else if (v == 5)
			printf("%c", (int)(a % 256));
		else if (v == 23)
			scanf("%ld", &a);
		else if (v == 39)
			a = mem[d] = rotate(mem[d]);
		else if (v == 40)
			d = mem[d];
		else if (v == 62)
			a = mem[d] = crazy(a, mem[d]);
		else if (v == 81)
			break;

		if (mem[c] >= 33 && mem[c] <= 126)
			mem[c] = ENCRYPT[mem[c] - 33];

		if (c == 59049-1)
			c = 0;
		else
			c++;

		if (d == 59049-1)
			d = 0;
		else
			d++;
	}
	putchar('\n');
}
