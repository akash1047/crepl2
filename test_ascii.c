#include "ascii.h"

#include <stdio.h>
#include <stdlib.h>

void expect_ch(char expected, char actual) {
    if (expected != actual) {
        fprintf(stderr, "Expected: %c, Actual: %c\n", expected, actual);
        exit(1);
    }
}

void expect(int value) {
    if (!value) {
        fprintf(stderr, "Value is false\n");
        exit(1);
    }
}

int main() {

    char UPPER_CASE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char LOWER_CASE[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++) {
        expect_ch(LOWER_CASE[i], ascii_to_lower(UPPER_CASE[i]));
        expect_ch(UPPER_CASE[i], ascii_to_upper(LOWER_CASE[i]));

        expect(ascii_alpha(UPPER_CASE[i]));
        expect(ascii_upper(UPPER_CASE[i]));
        expect(!ascii_upper(LOWER_CASE[i]));

        expect(ascii_alpha(LOWER_CASE[i]));
        expect(ascii_lower(LOWER_CASE[i]));
        expect(!ascii_lower(UPPER_CASE[i]));
    }

    char NUMBERS[] = "0123456789abcdefABCDEF";

    for (int i = 0; i < 16; i++) {
        if (i < 10) {
            expect(ascii_digit(NUMBERS[i]));
        } else {
            expect(!ascii_digit(NUMBERS[i]));
        }

        if (i < 8) {
            expect(ascii_oct(NUMBERS[i]));
        } else {
            expect(!ascii_oct(NUMBERS[i]));
        }

        expect(ascii_hex(NUMBERS[i]));

        if (i < 2) {
            expect(ascii_bin(NUMBERS[i]));
        } else {
            expect(!ascii_bin(NUMBERS[i]));
        }
    }

    {
        char test[26];
        for (int i = 0; i < 26; i++) {
            test[i] = ascii_to_lower(UPPER_CASE[i]);
        }

        if (strncmp(test, LOWER_CASE, 26) != 0) {
            fprintf(stderr, "Expected: %s, Actual: %s\n", LOWER_CASE, test);
            exit(1);
        }
    }

    {
        char test[26];
        for (int i = 0; i < 26; i++) {
            test[i] = ascii_to_upper(LOWER_CASE[i]);
        }

        if (strncmp(test, UPPER_CASE, 26) != 0) {
            fprintf(stderr, "Expected: %s, Actual: %s\n", UPPER_CASE, test);
            exit(1);
        }
    }

    return 0;
}