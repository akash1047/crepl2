#ifndef CREPL_TOKEN_H
#define CREPL_TOKEN_H

typedef enum {
    TOKEN_ILLEGAL,
    TOKEN_EOF,

    // Identifiers and literals
    TOKEN_IDENT,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_CHAR,
    TOKEN_STRING,

    // Arithmetic operators
    TOKEN_ADD,         // +
    TOKEN_SUB,         // -
    TOKEN_DIV,         // /
    TOKEN_REM,         // %
    TOKEN_TILDE,       // ~
    TOKEN_AND,         // &
    TOKEN_OR,          // |
    TOKEN_XOR,         // ^
    TOKEN_LEFT_SHIFT,  // <<
    TOKEN_RIGHT_SHIFT, // >>

    TOKEN_INCREMENT, // ++
    TOKEN_DECREMENT, // --

    TOKEN_PERIOD, // .
    TOKEN_ARROW,  // ->

    TOKEN_TERNARY, // ?
    TOKEN_ELIPSIS, // ...

    // Logical operators
    TOKEN_LOGICAL_NOT, // !
    TOKEN_LOGICAL_AND, // &&
    TOKEN_LOGICAL_OR,  // ||

    // Comparison operators
    TOKEN_EQUAL,         // ==
    TOKEN_NOT_EQUAL,     // !=
    TOKEN_GREATER_THAN,  // >
    TOKEN_GREATER_EQUAL, // >=
    TOKEN_LESS_THAN,     // <
    TOKEN_LESS_EQUAL,    // <=

    // Assignments
    TOKEN_ADD_ASSIGN,         // +=
    TOKEN_SUB_ASSIGN,         // -=
    TOKEN_STAR_ASSIGN,        // *=
    TOKEN_DIV_ASSIGN,         // /=
    TOKEN_REM_ASSIGN,         // %=
    TOKEN_AND_ASSIGN,         // &=
    TOKEN_OR_ASSIGN,          // |=
    TOKEN_XOR_ASSIGN,         // ^=
    TOKEN_LEFT_SHIFT_ASSIGN,  // <<=
    TOKEN_RIGHT_SHIFT_ASSIGN, // >>=

    TOKEN_COMMA,         // ,
    TOKEN_SEMICOLON,     // ;
    TOKEN_COLON,         // :
    TOKEN_OPEN_PAREN,    // (
    TOKEN_CLOSE_PAREN,   // )
    TOKEN_OPEN_CURLY,    // {
    TOKEN_CLOSE_CURLY,   // }
    TOKEN_OPEN_BRACKET,  // [
    TOKEN_CLOSE_BRACKET, // ]

    // Keyword
    TOKEN_KW_AUTO,     // auto
    TOKEN_KW_BREAK,    // break
    TOKEN_KW_CASE,     // case
    TOKEN_KW_CHAR,     // char
    TOKEN_KW_CONST,    // const
    TOKEN_KW_CONTINUE, // continue
    TOKEN_KW_DEFAULT,  // default
    TOKEN_KW_DO,       // do
    TOKEN_KW_DOUBLE,   // double
    TOKEN_KW_ELSE,     // else
    TOKEN_KW_ENUM,     // enum
    TOKEN_KW_EXTERN,   // extern
    TOKEN_KW_FLOAT,    // float
    TOKEN_KW_FOR,      // for
    TOKEN_KW_GOTO,     // goto
    TOKEN_KW_IF,       // if
    TOKEN_KW_INLINE,   // inline
    TOKEN_KW_INT,      // int
    TOKEN_KW_LONG,     // long
    TOKEN_KW_REGISTER, // register
    TOKEN_KW_RESTRICT, // restrict
    TOKEN_KW_RETURN,   // return
    TOKEN_KW_SHORT,    // short
    TOKEN_KW_SIGNED,   // signed
    TOKEN_KW_SIZEOF,   // sizeof
    TOKEN_KW_STATIC,   // static
    TOKEN_KW_STRUCT,   // struct
    TOKEN_KW_SWITCH,   // switch
    TOKEN_KW_TYPEDEF,  // typedef
    TOKEN_KW_UNION,    // union
    TOKEN_KW_UNSIGNED, // unsigned
    TOKEN_KW_VOID,     // void
    TOKEN_KW_VOLATILE, // volatile
    TOKEN_KW_WHILE,    // while

    // Pre processors
    TOKEN_HASH,         // #
    TOKEN_HASH_HASH,    // ##
    TOKEN_HASH_IF,      // #if
    TOKEN_HASH_ELIF,    // #elif
    TOKEN_HASH_ELSE,    // #else
    TOKEN_HASH_ENDIF,   // #endif
    TOKEN_HASH_IFDEF,   // #ifdef
    TOKEN_HASH_IFNDEF,  // #ifndef
    TOKEN_HASH_DEFINE,  // #define
    TOKEN_HASH_UNDEF,   // #undef
    TOKEN_HASH_INCLUDE, // #include
    TOKEN_HASH_LINE,    // #line
    TOKEN_HASH_ERROR,   // #error
    TOKEN_HASH_PRAGMA,  // #pragma
    TOKEN_HASH_DEFINED, // #defined
} Token;

#define TOKEN_FIRST TOKEN_ILLEGAL
#define TOKEN_LAST TOKEN_HASH_DEFINED

const char *token_string(Token token);

struct Literal {
    enum {
        CHAR,
        CHAR2,
        CHAR3,
        STRING,
    } type;

    union {
        char c;
        char c2[2];
        char c3[3];
        struct String {
            char *ptr;
            int len;
        } s;
    };
};

#endif // CREPL_TOKEN_H
