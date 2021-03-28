#include <iostream>
#include "esoteric.hpp"

using namespace std;

void hq9_plus(istream &input, ostream &output) {
    string commands = get_input(input);

    hq9_plus(commands, output);
}

void hq9_plus(string commands, ostream &output) {
    int accumulator = 0;

    for (auto command : commands) {
        if (command == 'H') {
            output << "Hello, world!" << endl;
        } else if (command == 'Q') {
            output << commands << endl;
        } else if (command == '9') {
            for (int i = 99; i > 1; i--) {
                output << i << " bottles of beer on the wall," << endl;
                output << i << " bottles of beer." << endl;
                output << "Take one down, pass it around," << endl;
                output << i-1 << " bottles of beer on the wall." << endl << endl;
            }
            output << "1 bottle of beer on the wall," << endl;
            output << "1 bottle of beer." << endl;
            output << "Take one down, pass it around," << endl;
            output << "no more bottles of beer on the wall." << endl;
        } else if (command == '+') {
            accumulator++;
        }
    }
}
