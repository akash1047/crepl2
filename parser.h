#ifndef CREPL_PARSER_H
#define CREPL_PARSER_H

#include "ast.h"
#include "token.h"

struct Parser {
    Token token;
    struct Literal literal;
};

#endif // CREPL_PARSER_H