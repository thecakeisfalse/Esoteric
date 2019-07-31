#include <stdio.h>
#include <stdlib.h>

char* read_string(size_t *size){
    char *str;
    int c;
    size_t length = 0;
    str = realloc(NULL, sizeof(char)*(*size));
    if(!str)return str;
    while((c=getchar()) != EOF  &&  c != '\n'){
        str[length++] = c;
        if(length == *size) {
        	str = realloc(str, sizeof(char)*(*size += 10));
            if(!str)
            	return str;
        }
    }
    str[length++] = '\0';
    size = &length;
    return str;
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char tape[10000];
	for (int k = 0; k < n; k++)
		tape[k] = 0;
	int pointer = 0;
	size_t length = 100;
	char *program = read_string(&length);
	printf("%s\n", program);
	for (unsigned int i = 0; i < length; i++) {
		if (program[i] == '>')
			pointer++;
		
		if (program[i] == '<')
			pointer--;
		
		if (program[i] == '+')
			tape[pointer]++;
		
		if (program[i] == '-')
			tape[pointer]--;
		
		if (program[i] == '.')
			printf("%c", tape[pointer]);
		
		if (program[i] == ',')
			scanf("%c", &tape[pointer]);

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
