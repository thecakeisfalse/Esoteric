#include <iostream>
using namespace std;
 
int main() {
	int num;
    cin >> num;
	string tape(num,0);
	int pointer = 0;
	string code;
	cin >> code;
	for (unsigned int i = 0; i < code.length(); i++) {
		if (code[i] == '>')
			pointer++;
		
		if (code[i] == '<')
			pointer--;
		
		if (code[i] == '+')
			tape[pointer]++;
		
		if (code[i] == '-')
			tape[pointer]--;
		
		if (code[i] == '.')
			cout << tape[pointer];
		
		if (code[i] == ',')
			cin >> tape[pointer];
		
		if (code[i] == '[') {
			if (tape[pointer] == 0) {
				int count = 1;
				while (count > 0) {
					i++;
					if (code[i] == '[')
						count++;
					if (code[i] == ']')
						count--;
				}
			}
        }
        else if (code[i] == ']') {
			if (tape[pointer] != 0) {
				int count = 1;
				while (count > 0) {
					i--;
					if (code[i] == '[')
						count--;
					if (code[i] == ']')
						count++;
				}
			}
        }
    }
 
	return 0;
}
