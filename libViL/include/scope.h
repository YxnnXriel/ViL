#ifndef __SCOPE_H__
#define __SCOPE_H__


#include "list.h"
#include "ast.h"

typedef struct SCOPTE_STRUCT{

    list_t *List_Variable_Definition;
    list_t *List_Function_Definition;
    list_t *List_struct_Definition;
    
}scope_t;



scope_t *__init_scope__();



#endif 