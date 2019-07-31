#include <iostream>
using namespace std;
 
int main(int argc, char* argv) {
	const int n = 30000;
	string tape(n,0);
	int pointer = 0;
	string program;
	if (argc == 2) {
		ifstream infile(argv[1]);
                while (infile) {
			getline(infile, program);
		}
		infile.close();
        }
	else cin >> program;
	for (unsigned int i = 0; i < program.length(); i++) {
	        if (program[i] == '>')
		        pointer++;
		
	        if (program[i] == '<')
			pointer--;
		
		if (program[i] == '+')
			tape[pointer]++;
		
		if (program[i] == '-')
			tape[pointer]--;
		
		if (program[i] == '.')
			cout << tape[pointer];
		
		if (program[i] == ',')
			cin >> tape[pointer];
		
		if (program[i] == '[') {
			if (tape[pointer] == 0) {
				int counter = 1;
				while (counter > 0) {
					i++;
					if (program[i] == '[')
						counter++;
					if (program[i] == ']')
						counter--;
				}
			}
                }
                else if (program[i] == ']') {
			if (tape[pointer] != 0) {
				int counter = 1;
				while (counter > 0) {
					i--;
					if (program[i] == '[')
						counter--;
					if (program[i] == ']')
						counter++;
				}
			}
                }
        }
	return 0;
}