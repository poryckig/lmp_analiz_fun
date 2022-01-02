#ifndef _STORE_H_IS_INCLUDED_
#define _STORE_H_IS_INCLUDED_

typedef struct e {
    char *name_fun_def;
    int *linie_fun_def;
    struct e *prev;
    struct e *next;
} *lista_fun_def;

typedef struct e {
    char *name_fun_proto;
    int *linie_fun_proto;
    struct e *prev;
    struct e *next;
} *lista_fun_proto;

typedef struct e {
    char *name_fun_call;
    int *linie_fun_call;
    struct e *prev;
    struct e *next;
} *lista_fun_call;


void store_add_def(char *funame, int par_level, FILE *file);
void store_add_proto(char *funame, int par_level, FILE *file);
void store_add_call(char *funame, int par_level, FILE *file);
int ile_fun_def, ile_fun_proto, ile_fun_call;

#endif

