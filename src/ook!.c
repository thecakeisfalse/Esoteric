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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "esoteric.h"

/*
 * Converts Ook! commands to brainfuck.
 *
 * @param commands Contain Ook! commands.
 */

char *ook2bf(char *commands)
{
	size_t i, j;

	size_t commands_length = 59049;
	size_t estimated_length = 1024;
	size_t real_buffer_length = 0;

	char *buffer = malloc(sizeof(char)*estimated_length);
	char *text = malloc(sizeof(char)*estimated_length);

	memset(buffer, 0, sizeof(char)*estimated_length);
	memset(text, 0, sizeof(char)*estimated_length);

	for (i = 0, j = 0; i < commands_length && commands[i] != '\0'; i++)
	{
		if (commands[i] == '!' || commands[i] == '.' || commands[i] == '?')
		{
			buffer[j++] = commands[i];
		}
		buffer[j] = 0;
	}

	real_buffer_length = j;
	for (i = 0, j = 0; i < real_buffer_length; i += 2)
	{
		if (strncmp(buffer+i, "..", 2) == 0)
		{
			text[j++] = '+';
		}
		else if (strncmp(buffer+i, ".?", 2) == 0)
		{
			text[j++] = '>';
		}
		else if (strncmp(buffer+i, ".!", 2) == 0)
		{
			text[j++] = ',';
		}
		else if (strncmp(buffer+i, "?.", 2) == 0)
		{
			text[j++] = '<';
		}
		else if (strncmp(buffer+i, "?!", 2) == 0)
		{
			text[j++] = ']';
		}
		else if (strncmp(buffer+i, "!.", 2) == 0)
		{
			text[j++] = '.';
		}
		else if (strncmp(buffer+i, "!?", 2) == 0)
		{
			text[j++] = '[';
		}
		else if (strncmp(buffer+i, "!!", 2) == 0)
		{
			text[j++] = '-';
		}
	}
	free(buffer);
	return text;
}

/*
 * Interpreters Ook! commands.
 *
 * @param commands Contain Ook! commands.
 */
void ook(char *commands)
{
	char *text = ook2bf(commands);
	brainfuck(text);
}
