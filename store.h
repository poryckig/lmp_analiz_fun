#ifndef _STORE_H_IS_INCLUDED_
#define _STORE_H_IS_INCLUDED_
/*
typedef struct e {
    char *name_fun;
} struktura;
*/
typedef struct e {
    char *name_fun_def;
    int *linie_fun_def;
    
} *lista_fun_def;

typedef struct e {
    char *name_fun_proto;
    int *linie_fun_proto;
} *lista_fun_proto;

typedef struct e {
    char *name_fun_call;
    int *linie_fun_call;
} *lista_fun_call;



void store_add_def(char *funame, int par_level, FILE *file);
void store_add_proto(char *funame, int par_level, FILE *file);
void store_add_call(char *funame, int par_level, FILE *file);

#endif
