#include "token.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_token_string(FILE *stream);

int main() {

    int result = 0;

    result = test_token_string(stderr);

    return result;
}

typedef struct {
    Token token;
    char literal[10];
} Ts;

int test_token_string(FILE *stream) {

    {
        Ts preprocessor[] = {
            {TOKEN_HASH, "#"},
            {TOKEN_HASH_HASH, "##"},
            {TOKEN_HASH_IF, "#if"},
            {TOKEN_HASH_ELIF, "#elif"},
            {TOKEN_HASH_ELSE, "#else"},
            {TOKEN_HASH_ENDIF, "#endif"},
            {TOKEN_HASH_IFDEF, "#ifdef"},
            {TOKEN_HASH_IFNDEF, "#ifndef"},
            {TOKEN_HASH_DEFINE, "#define"},
            {TOKEN_HASH_UNDEF, "#undef"},
            {TOKEN_HASH_INCLUDE, "#include"},
            {TOKEN_HASH_LINE, "#line"},
            {TOKEN_HASH_ERROR, "#error"},
            {TOKEN_HASH_PRAGMA, "#pragma"},
            {TOKEN_HASH_DEFINED, "#defined"},
        };

        const char *expected;
        const char *actual;

        for (int i = 0; i < sizeof(preprocessor) / sizeof(Ts); i++) {
            expected = preprocessor[i].literal;
            actual = token_string(preprocessor[i].token);

            if (strcmp(expected, actual) != 0) {
                fprintf(stream, "test_token_string: preprocessor\n");
                fprintf(stream, "Expected: %s\n", expected);
                fprintf(stream, "Actual: %s\n", actual);
                return 1;
            }
        }
    }

    return 0;
}