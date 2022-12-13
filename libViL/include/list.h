#ifndef __LIST_H__
#define __LIST_H__

    #include <stdio.h>
    typedef struct LIST_STRUCT{
        void **Item;
        int Size;
        size_t Sizeof;

    }list_t;


    list_t * __init__list__(size_t);


    int List_Append(list_t *list , void *value);
    void * List_Get(list_t *list,int index);
    void * List_Get_Last(list_t *list);
    void * List_Get_Firts(list_t *list);

    int List_Del(list_t *list , int index,void (*free_method)(void *x));
    void List_Free(list_t *list);




    typedef struct HASH_STRUCT{
        char *key;
        void *value; 
        struct HASH_STRUCT *next;
    }hash_t;

    typedef struct STK_HASH_STRUCT{
        int Size;
        hash_t *TabHash[100];
        size_t sizeOf;
    }stk_t;

    hash_t *__init__hash(const char *key ,void * value );
    stk_t *__init__stk_hash(size_t);// type of element
    int Hash_Append(stk_t * stk ,const char *key ,void * value);
    void *Hash_Get(stk_t *stk , const char *key);
    int Hash_Modif(stk_t *stk , const char *key,void *value);


    void Hash_Print(stk_t *stk);
    

    
#endif