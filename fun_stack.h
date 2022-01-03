#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_

int top_of_funstack( void );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( void ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame


typedef struct e1 {
    char *nazwa;
    struct e1 *prev;
    struct e1 *next;
} *list_zapamietane_funkcje;

int ile_funkcji;
int ile_fun_def;
int ile_fun_proto;
int ile_fun_call;
void add_zapamietane_funkcje(char *funame);
void idz_pocz_listy(list_zapamietane_funkcje lista);

#endif

