#include "esoteric.hpp"
#include <iostream>

using namespace std;

void ook(istream &input, ostream &output) {
    string commands = get_input(input);

    ook(commands, output);
}

void ook(string commands, ostream &output) {
    string only_special_commands = "";
    string brainfuck_commands = "";
    string command = "";

    for (auto el : commands) {
        if (el == '!' || el == '.' || el == '?') {
            only_special_commands += el;
        }
    }

    for (size_t i = 0; i < only_special_commands.length(); i += 2) {
        command = only_special_commands.substr(i, 2);
        if (command == "..") {
            brainfuck_commands += "+";
        } else if (command == ".?") {
            brainfuck_commands += ">";
        } else if (command == ".!") {
            brainfuck_commands += ",";
        } else if (command == "?.") {
            brainfuck_commands += "<";
        } else if (command == "?!") {
            brainfuck_commands += "]";
        } else if (command == "!.") {
            brainfuck_commands += ".";
        } else if (command == "!?") {
            brainfuck_commands += "[";
        } else if (command == "!!") {
            brainfuck_commands += "-";
        }
    }

    brainfuck(brainfuck_commands, output);
}
