#ifndef CREPL_SCANNER_H
#define CREPL_SCANNER_H

#include "token.h"

typedef struct {
    size_t position;
    size_t read_position;
    char ch;
} Scanner;

void scanner_scan(Scanner *sc, Token *tok, Literal *lit);

#endif // CREPL_SCANNER_H