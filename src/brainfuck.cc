#include "esoteric.hpp"
#include <fstream>
#include <vector>

void brainfuck(std::istream &input, std::ostream &output) {
    std::string commands = get_input(input);
    brainfuck(commands, output);
}

void brainfuck(std::string commands, std::ostream &output) {
    int commands_size = commands.length();
    int * stack = new int[1024];
    int stack_pointer = 0;
    int instructions_size = 0;
    struct Instruction * instructions = new struct Instruction[commands_size];
    int index = 0;
    char current_command;
    char previous_command = 0;
    int count = 0;
    int opened_bracket = 0;
    int buffer[30000] = {0};
    int pointer = 0;
    int i = 0;

    while (index < commands_size) {
        current_command = commands[index++];
        if (current_command != previous_command) {
            if (previous_command != 0) {
                instructions[instructions_size].opcode = previous_command;
                instructions[instructions_size].operand = count;
                ++instructions_size;
            }

            if (current_command == '+' || current_command == '-' || current_command == '<' || current_command == '>') {
                previous_command = current_command;
                count = 1;
                continue;
            } else {
                previous_command = 0;
                count = 0;
            }
        } else {
            ++count;
        }

        if (current_command == '[') {
            instructions[instructions_size].opcode = current_command;
            stack[stack_pointer++] = instructions_size;
            ++instructions_size;
        } else if (current_command == ']') {
            --stack_pointer;
            opened_bracket = stack[stack_pointer];
            instructions[instructions_size].opcode = current_command;
            instructions[instructions_size].operand = opened_bracket;
            instructions[opened_bracket].operand = instructions_size;
            ++instructions_size;
        } else if (current_command == '.' || current_command == ',') {
            instructions[instructions_size].opcode = current_command;
            instructions[instructions_size].operand = 0;
            ++instructions_size;
        }
    }

    while (i < instructions_size) {
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
        ++i;
    }

    delete[] instructions;
    delete[] stack;
}
