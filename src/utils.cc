#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sys/stat.h>

bool file_exists(std::string filename) {
    struct stat st;
    return stat(filename.c_str(), &st) == 0 && S_ISREG(st.st_mode);
}

std::string read_file(std::istream &input) {
    std::stringstream ss;
    while (input >> ss.rdbuf());
    return ss.str();
}

std::string get_only_filename(std::string filename) {
    filename = filename.substr(filename.find_last_of("/")+1);
    return filename.substr(0, filename.find_first_of("."));
}

std::string get_input(std::istream &input) {
    std::string text;

    if (&input == &std::cin) {
        std::getline(input, text);
    } else {
        text = read_file(input);
    }

    return text;
}

int get_file_size(std::string filename) {
    struct stat st;
    stat(filename.c_str(), &st);
    return st.st_size;
}
