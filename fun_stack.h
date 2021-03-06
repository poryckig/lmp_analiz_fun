#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_


typedef struct e1 {
    char *nazwa;
    struct e1 *prev;
    struct e1 *next;
} *list_zapamietane_funkcje;

typedef struct lista {
    char *funame;
    int par_level;
    struct lista *prev_stack;
} sterta_t;



void stack_init(sterta_t *sterta);
int top_of_funstack( void );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( void ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame

sterta_t *sterta;
char funame_tmp[256];



int ile_funkcji;
int ile_fun_def;
int ile_fun_proto;
int ile_fun_call;
void add_zapamietane_funkcje(char *funame, list_zapamietane_funkcje lista);
void idz_pocz_listy(list_zapamietane_funkcje lista);

#endif

