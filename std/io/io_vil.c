// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <assert.h>
// #include "io_vil.h"
// #include "../../src/include/str.h"


// static void clear_buffer(){
//     int c = 0;

//     while (c != '\n' && c != EOF)
//     {
//         c = getchar();
//     }
    
// }


// /**
//  * @brief [io.vil] scanf, mon propre scanf 
//  * 
//  * @param chaine 
//  */
// void __bulletin_io_scanf_static_(String chaine){
    
//     char buffer[BUFSIZ];
//     // fflush(stdin);
//     // fflush(stdin);
//     strcpy(buffer,"Nulll");
//     fgets(buffer,BUFSIZ-1,stdin);


//     buffer[strlen(buffer)-1] = '\0';

//     String_Set(chaine,buffer);

// }


// /**
//  * @brief [io.vil] Affichage d'une liste
//  * 
//  * @param visitor 
//  * @param node 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_io_print_list__(visitor_t *visitor , ast_t *node){
        
//         printf("[ ");

//         if(node->list_element->Size == 0)
//             printf("vide!");

//         else

//         for (int i = 0; i < node->list_element->Size; i++){
//             ast_t *h = List_Get(node->list_element,i);

//             switch (h->type){
//                 case AST_STRING: printf("\"%s\"",h->stringValue->str);break;
//                 case AST_INTEGER:printf("%ld",h->intValue);break;
//                 case AST_FLOAT:printf("%f",h->floatValue);break;
//                 case AST_BOOLEAN:printf("%s",h->booleanValue == 1 ? "true" :"false");break;
//                 case AST_CHAR:printf("'%c'",h->charValue);break;
//                 case AST_LIST_INIT: __bulletin_io_print_list__(visitor,h);break;
//                 case AST_TYPE: __bulletin_io_print_type__(visitor,h);break;
//             }
//             if(i < node->list_element->Size-1){
//                 printf(" , ");
//             }
//         }

//         printf(" ]");

//     return node;

// }


// /**
//  * @brief [io.vil] Affichage d'un type complexe
//  * 
//  * @param visitor 
//  * @param node 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_io_print_type__(visitor_t *visitor , ast_t *node){


//         if(ListString_Search(node->type_key,"__print__") != -1){
//             ast_t * func = Hash_Get(node->type_attribut,"__print__");
//             if(func != (void*)0)
//                 if(func->type == AST_FUNCTION_DEFINITION){
//                     visitor_t *vs = __init__visitor();
//                     vs->global_scope = node->scope_type_yourself_variables;
//                     visitor_visit(vs,func->function_definition_body);
//                     return node;
                
//                 }
//         }

//         printf("< %p >",node);

//     return node;
// }





// /**
//  * @brief [io.vil] Affichage sans retoure à la ligne
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_io_print__(visitor_t *visitor ,ast_t *node ,list_t *args){
//     return __bulletin_io_render__(visitor,node,args,0);
// }


// /**
//  * @brief [io.vil] Affichage avec retour à la ligne
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_io_println__(visitor_t *visitor ,ast_t *node ,list_t *args){
//     return __bulletin_io_render__(visitor,node,args,1);
// }



// /**
//  * @brief [io.vil] Affichage general
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @param new_ligne 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_io_render__(visitor_t *visitor ,ast_t *node ,list_t *args,int new_ligne){


//     for (int i = 0; i < args->Size; i++){
//         ast_t * vis = (struct AST_STRUCT*) List_Get(args,i);
        
//         vis->scope = scope_Get_scope(visitor,node->scope);
        
//         ast_t *pr = visitor_visit(visitor, vis);
//         switch (pr->type){
//             case AST_STRING:printf("%s",pr->stringValue->str != (void*)0 ? pr->stringValue->str :"");break;
//             case AST_INTEGER:printf("%ld",pr->intValue);break;
//             case AST_FLOAT:printf("%f",pr->floatValue);break;
//             case AST_CHAR:printf("%c",pr->charValue);break;
//             case AST_BOOLEAN:printf("%s",pr->booleanValue == 1 ? "true" :"false");break;
//             case AST_TYPE: __bulletin_io_print_type__(visitor,pr);break;
//             case AST_LIST_INIT: __bulletin_io_print_list__(visitor,pr);break;
//             break;
//             default:printf("< %p >",pr);break;
//         }
//     }

//     if(new_ligne) printf("\n");

//     return node;
// }


// ast_t *__bulletin_io_readline__(visitor_t *visitor,ast_t* node ,list_t *args){

//     __bulletin_io_println__(visitor,node,args);
//     ast_t *h = __init__ast__(AST_STRING);
//     h->stringValue = new_String("Null"); 
//     __bulletin_io_scanf_static_(h->stringValue);


//     return h;
// }


// ast_t *__bulletin_io_input__(visitor_t *visitor,ast_t* node ,list_t *args){

//     for (int i = 0; i < args->Size; i++){

//         ast_t *type = visitor_visit(visitor,List_Get(args,i));
//         switch (type->type){
//             case AST_STRING:
//                 __bulletin_io_scanf_static_(type->stringValue);
//             break;
//             case AST_INTEGER:scanf("%ld",&type->intValue); break;
//             case AST_FLOAT: scanf("%f",&type->floatValue); break;
//             case AST_BOOLEAN: scanf("%d",&type->booleanValue); break;
//         }

//     }

//     return node;
// }


// ast_t *__bulletin_io_open__(visitor_t *visitor,ast_t* node ,list_t *args){
    
//     if(args->Size != 2) return (void*)0;



//     ast_t *ast_file_name = List_Get(args,0);
//     ast_t *ast_mod = List_Get(args,1);

//     ast_file_name = visitor_visit(visitor,ast_file_name);
//     ast_mod = visitor_visit(visitor,ast_mod);

//     assert(ast_mod->type == AST_STRING && ast_file_name->type == AST_STRING);

//     FILE *fic = fopen(ast_file_name->stringValue->str,ast_mod->stringValue->str);
//     if(fic == (void*)0){

//         fprintf(stderr,"line :%d , files :%s , function : %s , l'ouverture du fichier n'a pas fonctionner \n",
//             __LINE__,
//             __FILE__,
//             __func__
//         );
//         exit(1);
//     }

//     ast_t *ast_res = __init__ast__(AST_STRING);
//     ast_res->stringValue = String_cat("<FILE>::%s",ast_file_name->stringValue->str);
//     ast_res->value_generic = fic;


//     return ast_res;
// }


// ast_t *__bulletin_io_close__(visitor_t *visitor,ast_t* node ,list_t *args){

//     if(args->Size != 1) return (void*)0;


//     ast_t *ast_file_name = List_Get(args,0);
//     ast_file_name = visitor_visit(visitor,ast_file_name);


//     FILE *fic = (FILE*) ast_file_name->value_generic;

//     assert(ast_file_name->type == AST_STRING && fic != (void*)0);

//     fclose(fic);
//     return node;
// }



// ast_t *__bulletin_io_write__(visitor_t *visitor,ast_t* node ,list_t *args){

//     if(args->Size < 2) return (void*)0;


//     ast_t *ast_file_name = List_Get(args,0);
//     ast_file_name = visitor_visit(visitor,ast_file_name);
//     FILE *fic = (FILE*) ast_file_name->value_generic;
//     assert(ast_file_name->type == AST_STRING && fic != (void*)0);


//     for (int i = 1; i < args->Size; i++){

//         ast_t * vis = (struct AST_STRUCT*) List_Get(args,i);
//         vis->scope = scope_Get_scope(visitor,node->scope);

//         ast_t *pr = visitor_visit(visitor, vis);

//         switch (pr->type){
//             case AST_STRING:fprintf(fic,"%s",pr->stringValue->str != (void*)0 ? pr->stringValue->str :"");break;
//             case AST_INTEGER:fprintf(fic,"%ld",pr->intValue);break;
//             case AST_FLOAT:fprintf(fic,"%f",pr->floatValue);break;
//             case AST_CHAR:fprintf(fic,"%c",pr->charValue);break;
//             case AST_BOOLEAN:fprintf(fic,"%s",pr->booleanValue == 1 ? "true" :"false");break;
//             case AST_TYPE: __bulletin_io_print_type__(visitor,pr);break;
//             case AST_LIST_INIT: __bulletin_io_print_list__(visitor,pr);break;
//             break;
//             default:fprintf(fic,"< %p >",pr);break;
//         }
//     }

//     return node;
// }

// /**
//  * @brief [io.vil] Ajoute des élements GENERAL !
//  * 
//  * @param visitor 
//  * @param node 
//  * @param args 
//  * @return ast_t* 
//  */
// ast_t *__bulletin_io_append__(visitor_t *visitor,ast_t* node ,list_t *args){

//     list_t *list = (void*)0;

//     for (int i = 0; i < args->Size; i++){

//         ast_t *vis = (struct AST_STRUCT*) List_Get(args,i);

//         ast_t *pr = visitor_visit(visitor,vis);

//         if(i == 0){
//             if(pr->type != AST_LIST_INIT){
//                 printf("[ Ligne : %d | Colone : %d ] -> le premier argument doit etre la liste. Append(var::<List> ,...); \n",
//                     pr->Line_n,
//                     pr->Colone_n
//                 );
//                 exit(1);
//             }
//             list = pr->list_element;
//         }else{

//             ast_t *f = (void*)0;

//             switch (pr->type){
//                 case AST_STRING: 
//                     f = __init_ast_with_line(AST_STRING,pr->Line_n,pr->Colone_n);
//                     f->stringValue = new_String(pr->stringValue->str);
//                 break;
//                 case AST_INTEGER:                    
//                     f = __init_ast_with_line(AST_INTEGER,pr->Line_n,pr->Colone_n);
//                     f->intValue = pr->intValue;break;
//                 case AST_FLOAT:                    
//                     f = __init_ast_with_line(AST_FLOAT,pr->Line_n,pr->Colone_n);
//                     f->floatValue = pr->floatValue;break;
//                 case AST_BOOLEAN:                    
//                     f = __init_ast_with_line(AST_BOOLEAN,pr->Line_n,pr->Colone_n);
//                     f->booleanValue = pr->booleanValue;break;break;
//                 default: f = pr; break;
//             }

//             List_Append(list,f);

//         }

//     }
    
//     return node;

// }

