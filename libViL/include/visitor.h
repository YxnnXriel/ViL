#ifndef __VISITOR_H__
#define __VISITOR_H__


#include "scope.h"
#include "ast.h"

typedef struct VISITOR_STRUCT{
    scope_t *global_scope;
}visitor_t;

scope_t *scope_Get_scope(visitor_t *visitor,scope_t *scope);


visitor_t *__init__visitor();


ast_t *visitor_visit(visitor_t *visitor , ast_t *node);


void ini_args(int argc,char const *args[] );

listString_t * get_args();



#endif 