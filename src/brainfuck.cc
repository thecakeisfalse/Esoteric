#include <iostream>
#include <vector>
#include "esoteric.hpp"

using namespace std;

void brainfuck(istream &input, ostream &output) {
    string commands = get_input(input).c_str();

    brainfuck(commands, output);
}

void brainfuck(string commands, ostream &output) {
    char * p = (char *)commands.c_str();
    int buffer[30000] = {0};
    int pointer = 0;
    int counter;

    do {
        if (*p == '[') {
            if (buffer[pointer] == 0) {
                counter = 1;
                while (counter > 0) {
                    p++;
                    if (*p == '[') counter++;
                    if (*p == ']') counter--;
                }
            }
        }
        if (*p == ']') {
            if (buffer[pointer] != 0) {
                counter = 1;
                while (counter > 0) {
                    p--;
                    if (*p == '[') counter--;
                    if (*p == ']') counter++;
                }
            }
        }
        if (*p == '+')
            buffer[pointer]++;
        if (*p == '-')
            buffer[pointer]--;
        if (*p == '<')
            pointer--;
        if (*p == '>')
            pointer++;
        if (*p == '.')
            output << (char)buffer[pointer];
        if (*p == ',') {
            cin >> buffer[pointer];
            buffer[pointer] += 48;
        }
    } while (*(p++));
}
