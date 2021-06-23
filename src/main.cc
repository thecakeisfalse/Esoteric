#include "esoteric.hpp"
#include <fstream>

int main(int argc, char * argv[]) {
    std::map<std::string, std::string> args = args_parse(argc, argv);

    std::ifstream fin;
    if (args["input_filename"] == "" || !file_exists(args["input_filename"])) {
        std::cout << argv[0] << ": no input files" << std::endl;
        return 2;
    } else {
        fin.open(args["input_filename"]);
    }

    std::ofstream fout;
    bool custom_output = false;
    if (args["output_filename"] != "stdout") {
        fout.open(args["output_filename"]);
        custom_output = true;
    }

    if (args["language"] == "hq9+") {
        hq9_plus(fin, (custom_output ? fout : std::cout));
    } else if (args["language"] == "brainfuck") {
        brainfuck(fin, (custom_output ? fout : std::cout));
    } else if (args["language"] == "ook") {
        ook(fin, (custom_output ? fout : std::cout));
    } else if (args["language"] == "spoon") {
        spoon(fin, (custom_output ? fout : std::cout));
    }
    return 0;
}
