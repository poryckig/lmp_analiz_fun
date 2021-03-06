#ifndef _STORE_H_IS_INCLUDED_
#define _STORE_H_IS_INCLUDED_

typedef struct e2 {
    char *name_fun_def;
    int *linie_fun_def;
    int *linie_koncowe;
    int ile_linii;
    struct e2 *prev;
    struct e2 *next;
} *lista_fun_def;

typedef struct e3 {
    char *name_fun_proto;
    int *linie_fun_proto;
    int ile_linii;
    struct e3 *prev;
    struct e3 *next;
} *lista_fun_proto;

typedef struct e4 {
    char *name_fun_call;
    int *linie_fun_call;
    int ile_linii;
    struct e4 *prev;
    struct e4 *next;
} *lista_fun_call;


void store_add_def(char *funame, int linia, lista_fun_def lista2);
void store_add_proto(char *funame, int linia, lista_fun_proto lista3);
void store_add_call(char *funame, int linia, lista_fun_call lista4);
int ile_fun_def, ile_fun_proto, ile_fun_call;


void idz_pocz_listy_def(lista_fun_def lista);
void idz_pocz_listy_proto(lista_fun_proto lista);
void idz_pocz_listy_call(lista_fun_call lista);

#endif

