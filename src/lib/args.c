#include <lib/args.h>

char** args(int argc, char* argv[]) {
    char** argumnets = (char**)malloc(sizeof(char*)*64);
    memset(argumnets, 0, sizeof(char*)*64);
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            i++;
            argumnets[1] = argv[i];
        } else if (strcmp(argv[i], "--version") == 0) {
            printf("esoteric version 1.0.0a\n");
            exit(1);
        } else {
            argumnets[0] = argv[i];
        }
    }
    if (argumnets[0] == NULL) {
        argumnets[0] = "";
    }
    if (argumnets[1] == NULL) {
        argumnets[1] = "";
    }
    return argumnets;
}