#ifndef _ESOTERIC_HPP_
#define _ESOTERIC_HPP_

#include <iostream>
#include <map>

class Instruction {
public:
  unsigned char opcode;
  unsigned short operand;
};


void hq9_plus(std::istream&, std::ostream&);
void hq9_plus(std::string, std::ostream&);

void brainfuck(std::istream&, std::ostream&);
void brainfuck(std::string, std::ostream&);

void ook(std::istream&, std::ostream&);
void ook(std::string, std::ostream&);

void spoon(std::istream&, std::ostream&);
void spoon(std::string, std::ostream&);

bool file_exists(std::string);
std::string read_file(std::istream&);
std::string get_only_filename(std::string);
std::string get_input(std::istream&);
bool can_be_converted(std::string);

void arg_help(int, char**);
std::map<std::string, std::string> args_parse(int, char**);

#endif // _ESOTERIC_HPP_
