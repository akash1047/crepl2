#ifndef CREPL_PARSER_H
#define CREPL_PARSER_H

#include "ast.h"
#include "scanner.h"
#include "token.h"

typedef struct {
    Scanner *sc;

    // lookahad
    Token tok;
    Literal lit;
} Parser;

#endif // CREPL_PARSER_H