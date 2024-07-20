#ifndef CREPL_AST_H
#define CREPL_AST_H

#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expr {
    enum {
        LITERAL,
        UNARY,
        BINARY,
        IDENT,
    } tag;

    union {
        struct Literal {
            int type; // token type
            char *value;
            size_t value_len;
        } literal;

        struct Unary {
            int op; // token type
            struct Expr *expr;
        } unary;

        struct Binary {
            int op; // token type
            struct Expr *lhs;
            struct Expr *rhs;
        } binary;

        struct Ident {
            char *name;
            size_t len;
        } ident;
    };
} Expr;

#endif // CREPL_AST_H