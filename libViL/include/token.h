#ifndef __TOKEN_H__
#define __TOKEN_H__

#include "str.h"
#include "heap.h"

typedef struct TOKEN_STRUCT{
    enum{
        
        T_ID, // var
        T_STRING,// "ma chaine"
        T_CHAR,// 'h'
        T_INT, // 233
        T_FLOAT, // 356.8
        T_SEMI, // ;
        T_COMA, // ,
        T_LBRACE , // {
        T_RBRACE , // }
        T_LBRACKET , // [
        T_RBRACKET , // ]
        T_LPARENT, // (
        T_RPARENT, // )
        T_EQUAL,
        T_PLUS,
        T_PLUS_EQUAL,
        T_MINUS,
        T_MINUS_EQUAL,
        T_MULT,
        T_MULT_EQUAL,
        T_DIV,
        T_DIV_EQUAL,
        T_SUP,
        T_SUP_EQUAL,
        T_INF,
        T_INF_EQUAL,
        T_EQUAL_EQUAL,
        T_DIF,// !=
        T_ESCLA,
        T_AT,// @
        T_UNDERSCORE, // _
        T_GUIL, // '
        T_DIEZ, // #
        T_DOT, // .
        T_COLON, // :
        T_MARK, // ?
        T_TIRET, // -
        T_ASSIGN , // <--
        T_AND,
        T_MODULO,
        T_OR,
        T_EOF,
    }type;
    String value;
}token_t;


token_t * __init_token__(int type , String value);
void token_free(token_t *tok);

char *token_as_string(int type);

#endif 