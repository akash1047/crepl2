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
        struct BasicLiteral {
            Token type; // token type
            struct Literal *lit;
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
            String name;
        } ident;
    };
} Expr;

#endif // CREPL_AST_H