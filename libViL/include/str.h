#ifndef __STR_H__
#define __STR_H__


        typedef struct STRUCT_STR
        {
            char *str;
            int lenght;
        }string_t , *String;


        String new_String(const char *str);
        char String_index(String str , int index);
        char *String_str(String str);
        int String_lenght(String str);
        int String_Set(String str , char *new_str);
        int String_Set_char(String str , int index , char carac);
        String String_cat(char *format , ...);
        String String_Reverse(String chaine);
        String String_Read_FIle(const char *args);
        int String_free(String str);




        typedef struct STRUCT_LIST_STR
        {
            string_t **ListStr;
            int Size;
            int Limit_Size;
        }listString_t , *listString;


        listString new_ListString();
        listString new_ListString_limit(int x);

        int ListString_Append(listString list , char *value);
        int ListString_lenght(listString list , int index);
        char * ListString_Get(listString list , int index);
        void ListString_Set(listString list , int index , char *new_value);
        int ListString_Search(listString list , char *value);
        int ListString_Delete(listString list , int index);
        int ListString_Clear(listString list);
        listString ListString_Copy(listString list);
        void ListString_Print(listString list);
        void ListString_Print_mod(listString list , void (*print)(listString));
        String String_Remont(listString list ,char *delim);
        listString String_Split(String str , char *delim);
        void Table(String champs,listString list);



#endif