#include <iostream>
#include <fstream>
#include "esoteric.hpp"

using namespace std;

int main(int argc, char * argv[]) {
    map<string, string> args = args_parse(argc, argv);

    ifstream fin;
    if (args["input_filename"] == "" || !file_exists(args["input_filename"])) {
        cout << argv[0] << ": no input files" << endl;
        return 2;
    } else {
        fin.open(args["input_filename"]);
    }

    ofstream fout;
    bool custom_output = false;
    if (args["output_filename"] != "stdout") {
        fout.open(args["output_filename"]);
        custom_output = true;
    }

    if (args["language"] == "hq9+") {
        hq9_plus(fin, (custom_output ? fout : cout));
    } else if (args["language"] == "brainfuck") {
        brainfuck(fin, (custom_output ? fout : cout));
    } else if (args["language"] == "ook") {
        ook(fin, (custom_output ? fout : cout));
    } else if (args["language"] == "spoon") {
        spoon(fin, (custom_output ? fout : cout));
    }
    return 0;
}
