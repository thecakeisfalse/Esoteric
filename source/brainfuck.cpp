#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	const int n = 30000;
	char tape[n];
	for (int i = 0; i < n; i++) tape[i] = 0;
	int pointer = 0;
	string code = "", tmp;
	while (cin >> tmp) code += tmp;
	cin >> code;
	for (unsigned int i = 0; i < code.length(); i++) {
		if (code[i] == '>') pointer++;
		
		if (code[i] == '<') pointer--;
		
		if (code[i] == '+') tape[pointer]++;
		
		if (code[i] == '-') tape[pointer]--;
		
		if (code[i] == '.') cout << "c++"; //cout << tape[pointer];
		
		if (code[i] == ',') cin >> tape[pointer];
		
		if (code[i] == '[') {
			if (tape[pointer] == 0) {
				int counter = 1;
				while (counter > 0) {
					i++;
					if (code[i] == '[')
						counter++;
					if (code[i] == ']')
						counter--;
				}
			}
                }
                else if (code[i] == ']') {
			if (tape[pointer] != 0) {
				int counter = 1;
				while (counter > 0) {
					i--;
					if (code[i] == '[')
						counter--;
					if (code[i] == ']')
						counter++;
				}
			}
                }
        }
	return 0;
}
