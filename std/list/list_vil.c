// #include <stdio.h>
// #include <stdlib.h>

// #include "list_vil.h"


// ast_t * bulletin_get_list_element(visitor_t *visitor ,ast_t *node , list_t *args){
    
//     ast_t *res = (void*)0;

//     if(args->Size <= 0) return res;

//     ast_t *list = (ast_t*) List_Get(args,0);
//     list = visitor_visit(visitor,list);

//     if(list->type != AST_LIST_INIT) return res;

//     ast_t *pointeur = List_Get(args,1);

//     pointeur = visitor_visit(visitor,pointeur);

//     switch (pointeur->type)
//     {
//         case AST_INTEGER:
//             if( pointeur->intValue >= list->list_element->Size ) return res;
//             res = (ast_t*) List_Get(list->list_element,pointeur->intValue);
//             // printf("Bulletin list c'est entrer \n");
//             break;
//         default:break;
//     }
//     return res;

// }