#include <stdio.h>
#include <stdlib.h>

char* read_str(size_t *size){
    char *str;
    int c;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*(*size));
    if(!str)return str;
    while((c=getchar()) != EOF  &&  c != '\n'){
        str[len++] = c;
        if(len == *size) {
        	str = realloc(str, sizeof(char)*(*size += 10));
            if(!str)
            	return str;
        }
    }
    str[len++] = '\0';
    size = len;
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
	size_t len = 100;
	char *code = read_str(&len);
	printf("%s\n", code);
	for (unsigned int i = 0; i < len; i++) {
		if (code[i] == '>')
			pointer++;
		
		if (code[i] == '<')
			pointer--;
		
		if (code[i] == '+')
			tape[pointer]++;
		
		if (code[i] == '-')
			tape[pointer]--;
		
		if (code[i] == '.')
			printf("%c", tape[pointer]);
		
		if (code[i] == ',')
			scanf("%c", &tape[pointer]);

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
