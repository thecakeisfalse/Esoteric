#include "esoteric.hpp"
#include <fstream>
#include <vector>

void brainfuck(std::istream &input, std::ostream &output) {
    std::string commands = get_input(input);
    brainfuck(commands, output);
}

void brainfuck(std::string commands, std::ostream &output) {
    int commands_size = commands.length();
    std::vector<int> stack;
    int instructions_size = 0;
    std::vector<Instruction> instructions(commands_size, Instruction());
    int index = 0;
    char command;
    char previous_command = 0;
    int count = 0;
    int opened_bracket = 0;
    int buffer[30000];
    int pointer = 0;

    while (index < commands_size) {
        command = commands[index++];
        if (command != previous_command) {
            if (previous_command != 0) {
                instructions[instructions_size].opcode = previous_command;
                instructions[instructions_size].operand = count;
                ++instructions_size;
            }

            if (command == '+' || command == '-' || command == '<' || command == '>') {
                previous_command = command;
                count = 1;
                continue;
            } else {
                previous_command = 0;
                count = 0;
            }
        } else {
            ++count;
        }

        if (command == '[') {
            instructions[instructions_size].opcode = command;
            stack.push_back(instructions_size);
            ++instructions_size;
        } else if (command == ']') {
            opened_bracket = stack.back();
            instructions[instructions_size].opcode = command;
            instructions[instructions_size].operand = opened_bracket;
            instructions[opened_bracket].operand = instructions_size;
            stack.pop_back();
            ++instructions_size;
        } else if (command == '.' || command == ',') {
            instructions[instructions_size].opcode = command;
            instructions[instructions_size].operand = 0;
            ++instructions_size;
        }
    }
    instructions.resize(instructions_size);

    for (int i = 0; i < instructions_size; i++) {
        if (instructions[i].opcode == '[') {
            if (buffer[pointer] == 0) {
                i = instructions[i].operand;
            }
        } else if (instructions[i].opcode == ']') {
            if (buffer[pointer] != 0) {
                i = instructions[i].operand;
            }
        } else if (instructions[i].opcode == '.') {
            output << (char)buffer[pointer];
        } else if (instructions[i].opcode == ',') {
            buffer[pointer] = std::cin.get();
        } else if (instructions[i].opcode == '+') {
            buffer[pointer] += instructions[i].operand;
        } else if (instructions[i].opcode == '-') {
            buffer[pointer] -= instructions[i].operand;
        } else if (instructions[i].opcode == '>') {
            pointer += instructions[i].operand;
        } else if (instructions[i].opcode == '<') {
            pointer -= instructions[i].operand;
        }
    }
}
