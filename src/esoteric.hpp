#ifndef _ESOTERIC_HPP_
#define _ESOTERIC_HPP_

#include <string>
#include <iostream>
#include <map>

// esoteric languages start

void hq9_plus(std::istream&, std::ostream&);
void hq9_plus(std::string, std::ostream&);

void brainfuck(std::istream&, std::ostream&);
void brainfuck(std::string, std::ostream&);

void ook(std::istream&, std::ostream&);
void ook(std::string, std::ostream&);

void spoon(std::istream&, std::ostream&);
void spoon(std::string, std::ostream&);

// esoteric languages end

// utils start

bool file_exists(std::string);
std::string read_file(std::istream&);
std::string get_only_filename(std::string);
std::string get_input(std::istream&);
bool can_be_converted(std::string);

// utils end

// args start

void arg_help(int, char**);
std::map<std::string, std::string> args_parse(int, char**);

// args end

#endif // _ESOTERIC_HPP_
