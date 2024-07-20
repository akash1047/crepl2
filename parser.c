#include "parser.h"
#include "ast.h"
#include <stdlib.h>

void parser_next(Parser *p) { scanner_scan(p->sc, &p->tok, &p->lit); }

struct Expr *parser_parse_unary(Parser *p) {

    struct Expr *expr = (struct Expr *)malloc(sizeof(struct Expr));

    if (expr == NULL)
        return NULL;

    switch (p->tok) {
    case TOKEN_ADD:
        expr->tag = UNARY;
        expr->unary.op = TOKEN_ADD;
        parser_next(p);
        expr->unary.expr = parser_parse_unary(p);
        break;
    case TOKEN_SUB:
        expr->tag = UNARY;
        expr->unary.op = TOKEN_SUB;
        parser_next(p);
        expr->unary.expr = parser_parse_unary(p);
        break;
    case TOKEN_IDENT:
    case TOKEN_INT:
    case TOKEN_FLOAT:
    case TOKEN_CHAR:
    case TOKEN_STRING:
        expr->tag = LITERAL;
        expr->literal.type = p->tok;
        expr->literal.lit = &p->lit;
        break;
    default:
        free(expr);
        return NULL;
    }

    parser_next(p);
    return expr;
}