#include "token.h"
#include <stdio.h>

#define TOKEN_ERROR_LEN 20
static char TOKEN_ERROR[TOKEN_ERROR_LEN];

static const char TOKEN_STRING_TABLE[][9] = {
    "ILLEGAL",
    "EOF",

    // Identifiers and literals
    "IDENT",
    "INT",
    "FLOAT",
    "CHAR",
    "STRING",

    // Arithmetic operators
    "+",
    "-",
    "/",
    "%",
    "~",
    "&",
    "|",
    "^",
    "<<",
    ">>",

    "++",
    "--",

    ".",
    "->",

    "?",
    "...",

    // Logical operators
    "!",
    "&&",
    "||",

    // Comparison operators
    "==",
    "!=",
    ">",
    ">=",
    "<",
    "<=",

    // Assignments
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    "&=",
    "|=",
    "^=",
    "<<=",
    ">>=",

    ",",
    ";",
    ":",
    "(",
    ")",
    "{",
    "}",
    "[",
    "]",

    // Keyword
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "inline",
    "int",
    "long",
    "register",
    "restrict",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while",

    // Pre processors
    "#",
    "##",
    "#if",
    "#elif",
    "#else",
    "#endif",
    "#ifdef",
    "#ifndef",
    "#define",
    "#undef",
    "#include",
    "#line",
    "#error",
    "#pragma",
    "#defined",
};

const char *token_string(Token token) {
    if (token < TOKEN_FIRST || token > TOKEN_LAST) {
        sprintf_s(TOKEN_ERROR, TOKEN_ERROR_LEN, "Token(%d)\0", token);
        return TOKEN_ERROR;
    }
    return TOKEN_STRING_TABLE[token];
}