#include "repl.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    repl_start(stdin, stdout, stderr);
    return 0;
}

void repl_start(FILE *input, FILE *output, FILE *error) {
    char buffer[1024];

    while (1) {
        fprintf(output, "> ");
        if (fgets(buffer, 1024, input) == NULL) {
            break;
        }

        fprintf(output, "You entered: %s", buffer);
    }
}