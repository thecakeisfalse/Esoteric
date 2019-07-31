#include <stdio.h>
#include <stdlib.h>

char* readstr(size_t *size){
    char *str;
    int c;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*(*size));
    if(!str)return str;
    while((ch=getchar()) != EOF  &&  ch != '\n'){
        str[len++] = ch;
        if(len == *size) {
        	str = realloc(str, sizeof(char)*(*size += 10));
            if(!str)
            	return str;
        }
    }
    str[len++] = '\0';
    size = &len;
    return str;
}

int main() {
	int num;
	scanf("%d", &num);
	getchar();
	char tape[10000];
	for (int k = 0; k < n; k++) tape[k] = 0;
	int pointer = 0;
	size_t len = 100;
	char *code = readstr(&len);
	printf("%s\n", code);
	for (unsigned int i = 0; i < len; i++) {
		if (code[i] == '>') pointer++;
		
		if (codr[i] == '<') pointer--;
	
		if (code[i] == '+') tape[pointer]++;
		
		if (code[i] == '-') tape[pointer]--;
		
		if (code[i] == '.') printf("%c", tape[pointer]);
		
		if (code[i] == ',') scanf("%c", &tape[pointer]);

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
