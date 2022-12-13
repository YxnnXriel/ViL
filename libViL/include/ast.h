#ifndef __AST_H__
#define __AST_H__

#include "str.h"
#include "list.h"
#include "token.h"


struct VISITOR_STRUCT;

#define FOREACH_AST(AST)    \
        AST(AST_TYPEOF) \
        AST(AST_CONSTRUCTOR_DEFINITION) \
        AST(AST_VARIABLE_DEFINITION)    \
        AST(AST_VARIABLE)   \
        AST(AST_TYPE_DEFINITION)    \
        AST(AST_TYPE)   \
        AST(AST_TYPE_ACCESS)    \
        AST(AST_TYPE_EXPR)  \
        AST(AST_FUNCTION_DEFINITION)    \
        AST(AST_FUNCTION_CALL)  \
        AST(AST_ASSIGNEMENT)    \
        AST(AST_MODIFIER)   \
        AST(AST_LIST_INIT)  \
        AST(AST_LIST_ACCESS)    \
        AST(AST_LIST_MODIFIER)  \
        AST(AST_DICT_INIT)  \
        AST(AST_DICT_ACCESS)    \
        AST(AST_DICT_MODIFIER)  \
        AST(AST_BINOP)  \
        AST(AST_UNOP)   \
        AST(AST_BOOLEAN)    \
        AST(AST_INTEGER)    \
        AST(AST_FLOAT)  \
        AST(AST_CHAR)   \
        AST(AST_STRING) \
        AST(AST_BREAK)  \
        AST(AST_RETURN) \
        AST(AST_CONTINUE)   \
        AST(AST_IF) \
        AST(AST_WHILE)  \
        AST(AST_FOR)    \
        AST(AST_COMPOUND)   \
        AST(AST_NOOP)

#define GENERATE_AST_ENUM(ENUM) ENUM,
#define GENERATE_STRING_AST(STRING) #STRING,

typedef struct AST_STRUCT{
    enum{
        FOREACH_AST(GENERATE_AST_ENUM)
    }type;

    /*==== AST VARIABLE DEFINITION ====*/
    String variable_definition_name;
    struct AST_STRUCT *variable_definition_value;
    int variable_definition_is_static_variable;
    
    /*==== AST VARIABLE  ====*/
    String variable_name;

    /*==== AST FUNCTION DEFINITION  ====*/
    String function_definition_name;
    list_t *function_definition_args;
    struct AST_STRUCT *function_definition_body;

    /*==== AST ASSIGNEMENT ====*/
    struct AST_STRUCT *assignement_left;
    struct AST_STRUCT *assignement_value;


    /*==== AST FUNCTION Call  ====*/
    String function_call_name;
    list_t *function_call_args;


    /*=== AST BINOP ===*/
    struct AST_STRUCT *binop_left;
    struct AST_STRUCT *binop_right;
    token_t *binop_op;

    /*=== AST UNOP ===*/
    struct AST_STRUCT * unop_right;
    token_t *unop_op;


    /*==== TYPE VALUE ====*/
    String stringValue;
    long intValue;
    float floatValue;
    int booleanValue;
    char charValue;


    /*==== RETURN ====*/
    struct AST_STRUCT *return_expr;

    /*==== IF ====*/
    struct AST_STRUCT *if_expr;
    struct AST_STRUCT *if_body;
    struct AST_STRUCT *if_other;
    struct AST_STRUCT *else_body;

    /*==== WHILE ====*/
    struct AST_STRUCT *while_expr;
    struct AST_STRUCT *while_body;

    /*==== FOR ====*/
    struct AST_STRUCT *for_init;
    struct AST_STRUCT *for_expr;
    struct AST_STRUCT *for_update;
    struct AST_STRUCT *for_body;

    /*==== LIST ====*/
    list_t *list_element;
    struct AST_STRUCT *list_pointeur;


    /*==== DICT ====*/
    stk_t *dict_element;
    struct AST_STRUCT *dict_pointeur;


    /*==== TYPE DEFINITION ====*/
    String type_definition_name;
    stk_t *type_attribut; // les attributs de la structure
    listString type_key;

    /*==== TYPE ====*/
    String type_name;
    int IsConstructor;

    struct SCOPTE_STRUCT *scope_type_yourself_variables;
    

    /*==== TYPEOF ====*/
    int type_of;

    /*==== COMPOUND ====*/
    list_t *compound_list;
    int break_compound;

    /*==== SCOPE ====*/
    struct SCOPTE_STRUCT *scope;
    int is_return_value;

    int Line_n;
    int Colone_n;

    void * value_generic;

    struct AST_STRUCT * (*fptr)(struct VISITOR_STRUCT *,struct AST_STRUCT *,struct LIST_STRUCT*);

}ast_t;


ast_t * __init__ast__(int type);


ast_t *__init_ast_with_line(int type , int line , int colone);

void ast_free(void *ast);
void freeAst(ast_t *as);

static const char *AST_TO_STRING[]={
    FOREACH_AST(GENERATE_STRING_AST)
};

#endif