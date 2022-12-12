// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #include "attr_vil.h"




// /**
//  * @brief [attr.vil] Suppression d'un membre 
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_attr_remove__(visitor_t *visitor,ast_t* node ,list_t *args){


//     if(node->list_element == (void*)0){
//         printf("[ Ligne : %d | Colone : %d ] -> Attribut Append() non pris en charge par ce type\n",
//             node->Line_n,
//             node->Colone_n
//         );
//         exit(1);
//     }


//     list_t *list = node->list_element;

//     if(args->Size != 1){
//         printf("[ Ligne : %d | Colone : %d ] -> Attribut var.Append(<str>|<int>) \n",
//             node->Line_n,
//             node->Colone_n
//         ); 
//         exit(1);

//     }

//     ast_t *m = visitor_visit(visitor,(ast_t*)List_Get(args,0));

//     if(m->type == AST_INTEGER){
//         List_Del(
//             list,
//             m->intValue,
//             NULL
//         );
//     }else if(m->type == AST_STRING){
//         for (int i = 0; i < args->Size; i++){

//             ast_t *vis = (struct AST_STRUCT*) List_Get(args,i);

//             if(vis->type == AST_STRING){
//                 if(strcmp(vis->stringValue->str,m->stringValue->str) == 0){
//                     List_Del(
//                         list,
//                         i,
//                         NULL
//                     );
//                     break;
//                 }
//             }

//         }
//     }

//     return node;

// }


// /**
//  * @brief [attr.vil] Taille d'un élement
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_attr_lenght__(visitor_t *visitor,ast_t* node ,list_t *args){

//         ast_t *l = visitor_visit(visitor,node);

//         ast_t *value = __init__ast__(AST_INTEGER);
//         int nbr = 0;
//         switch(l->type){
//             case AST_STRING: value->intValue = l->stringValue->lenght; break;
//             case AST_INTEGER: 
//             nbr = l->intValue;
//             value->intValue = 1;
//             while (nbr / 10 > 0){
//                 value->intValue +=1;
//                 nbr /= 10;
//             }
            
//             break;
//             case AST_FLOAT: break;
//             case AST_BOOLEAN: break;
//             case AST_LIST_INIT: value->intValue= l->list_element->Size; break;

//         }
        
//     return value;
// }



// /**
//  * @brief [attr.vil] Ajout d'un élement  
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_attr_append__(visitor_t *visitor,ast_t* node ,list_t *args){


//     if(node->list_element == (void*)0){
//         printf("[ Ligne : %d | Colone : %d ] -> Attribut Append() non pris en charge par ce type\n",
//             node->Line_n,
//             node->Colone_n
//         );
//         exit(1);
//     }


//     list_t *list = node->list_element;
//     for (int i = 0; i < args->Size; i++){

//         ast_t *vis = (struct AST_STRUCT*) List_Get(args,i);

//         ast_t *pr = visitor_visit(visitor,vis);


//         ast_t *f = (void*)0;

//         switch (pr->type){
//             case AST_STRING: 
//                 f = __init_ast_with_line(AST_STRING,pr->Line_n,pr->Colone_n);
//                 f->stringValue = new_String(pr->stringValue->str);
//             break;
//             case AST_INTEGER:                    
//                 f = __init_ast_with_line(AST_INTEGER,pr->Line_n,pr->Colone_n);
//                 f->intValue = pr->intValue;break;
//             case AST_FLOAT:                    
//                 f = __init_ast_with_line(AST_FLOAT,pr->Line_n,pr->Colone_n);
//                 f->floatValue = pr->floatValue;break;
//             case AST_BOOLEAN:                    
//                 f = __init_ast_with_line(AST_BOOLEAN,pr->Line_n,pr->Colone_n);
//                 f->booleanValue = pr->booleanValue;break;break;
//             default: f = pr; break;
//         }

//         List_Append(list,f);

//     }

    
//     return node;

// }


// ast_t *__bulletin_attr_search__(visitor_t *visitor,ast_t* node ,list_t *args){

//     ast_t *re = (ast_t*) List_Get(args,0);
//     ast_t *se = (ast_t*) List_Get(args,1);

//     re = visitor_visit(visitor,re);
//     se = visitor_visit(visitor,se);

//     if(re->type == AST_STRING && se->type == AST_STRING){
//         ast_t * ini = __init__ast__(AST_BOOLEAN);

//         if(strstr(re->stringValue->str,se->stringValue->str) != (void*)0){
//             ini->booleanValue = 1;
//         }else{
//             ini->booleanValue = 0;
//         }

//         return ini;
//     }


//     return node;
// }