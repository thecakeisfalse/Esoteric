#include <map>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

void arg_help(int __attribute__((unused)) argc, char * argv[]) {
    cout << "Usage: " << argv[0] << " [options] file..." << endl;
    cout << "Options:" << endl;
    cout << "  -x <language>    Specify the language of the following input file." << endl;
    //cout << "  -c               Converts input file to C file." << endl;
    cout << "  -o <file>        Place the output info <file>." << endl;
}

map<string, string> args_parse(int argc, char * argv[]) {
    map<string, string> args;

    args["language"] = "brainfuck";
    args["output_filename"] = "stdout";
    args["input_filename"] = "stdin";
    //args["convert"] = "false";

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-x")) {
            args["language"] = argv[++i];
        } else if (!strcmp(argv[i], "-o")) {
            args["output_filename"] = argv[++i];
        } /*else if (!strcmp(argv[i], "-c")) {
            args["convert"] = "true";
        } */ else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
            arg_help(argc, argv);
            args.clear();
            exit(1);
        } else {
            args["input_filename"] = argv[i];
        }
    }

    return args;
}
