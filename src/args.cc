#include "esoteric.hpp"
#include <cstring>

void arg_help(int __attribute__((unused)) argc, char * argv[]) {
    std::cout << "Usage: " << argv[0] << " [options] file..." << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -x <language>    Specify the language of the following input file." << std::endl;
    std::cout << "  -o <file>        Place the output info <file>." << std::endl;
}

std::map<std::string, std::string> args_parse(int argc, char * argv[]) {
    std::map<std::string, std::string> args;

    args["language"] = "brainfuck";
    args["output_filename"] = "stdout";
    args["input_filename"] = "";

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-x")) {
            args["language"] = argv[++i];
        } else if (!strcmp(argv[i], "-o")) {
            args["output_filename"] = argv[++i];
        } else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
            arg_help(argc, argv);
            args.clear();
            exit(1);
        } else {
            args["input_filename"] = argv[i];
        }
    }

    return args;
}
