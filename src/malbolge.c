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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
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

long rotate(long n)
{
	return 19683*(n%3) + n/3;
}

long crazy(long a, long b)
{
	long result = 0, d = 1;
	int i = 0;
	while (i < 10)
	{
		result += TABLE_CRAZY[(int)((b/d)%3)][(int)((a/d)%3)] * d;
		d *= 3;
		i++;
	}
	return result;
}

int is_valid_opcode(char c, int pointer)
{
	int i = 0;
	while (i < 8)
	{
		if (((int)c + pointer) % 94 == OPCODES_VALID[i])
			return 1;
		i++;
	}
	return 0;
}

/*
 * Interpreters Malbolge commands.
 *
 * @param commands Contain malbolge commands.
 */
void malbolge(char *commands)
{
	size_t i = 0;
	long pointer = 0;
	long a = 0, c = 0, d = 0;
	size_t length = 59049;
	if (commands[length])
	{
		printf("[ERROR] Souce is too long!\n");
		return;
	}
	for (i = 0, pointer = 0; i < length && commands[i] != '\0'; i++, pointer++)
	{
		if (commands[i] == ' ' || commands[i] == '\n')
		{
			continue;
		}
		if (!is_valid_opcode(commands[i], pointer))
		{
			printf("[ERROR] Invalid character! i=%ld commands[%ld]=%d='%c'\n", (long)i, (long)i, commands[i], commands[i]);
			return;
		}
		mem[pointer] = (int)commands[i];
	}

	while (pointer < 59049)
	{
		mem[pointer] = crazy(mem[pointer-1], mem[pointer-2]);
		pointer++;
	}

	while (1)
	{
		if (mem[c] < 33 || mem[c] > 126)
			return;
		if ((mem[c] + c) % 94 == 4)
			c = mem[d];
		else if ((mem[c] + c) % 94 == 5)
			printf("%c", (int)(a % 256));
		else if ((mem[c] + c) % 94 == 23)
			scanf("%ld", &a);
		else if ((mem[c] + c) % 94 == 39)
			a = mem[d] = rotate(mem[d]);
		else if ((mem[c] + c) % 94 == 40)
			d = mem[d];
		else if ((mem[c] + c) % 94 == 62)
			a = mem[d] = crazy(a, mem[d]);
		else if ((mem[c] + c) % 94 == 81)
			break;

		if (mem[c] >= 33 && mem[c] <= 126)
			mem[c] = ENCRYPT[mem[c] - 33];

		if (c == 59048)
			c = 0;
		else
			c++;

		if (d == 59048)
			d = 0;
		else
			d++;
	}
	putchar('\n');
}
