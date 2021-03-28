#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sys/stat.h>

using namespace std;

bool file_exists(string filename) {
    struct stat sb;

    return stat(filename.c_str(), &sb) == 0 && S_ISREG(sb.st_mode);
}

string read_file(istream &input) {
    string line;
    string text = "";

    while (getline(input, line)) {
        text += line + "\n";
    }

    return text;
}

string get_only_filename(string filename) {
    filename = filename.substr(filename.find_last_of("/")+1);

    return filename.substr(0, filename.find_first_of("."));
}

string get_input(istream &input) {
    string text;

    if (&input == &std::cin) {
        getline(input, text);
    } else {
        text = read_file(input);
    }

    return text;
}

bool can_be_converted(string name) {
    vector<string> languages = {"brainfuck", "ook!", "spoon"};

    return find(languages.begin(), languages.end(), name) != languages.end();
}
