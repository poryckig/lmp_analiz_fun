#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_

int top_of_funstack( void );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( void ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame


typedef struct e {
    char *nazwa;
    struct e *prev;
    struct e *next;
} *list_zapamietane_funkcje;

int ile_funkcji = 0;
int ile_fun_def = 0;
int ile_fun_proto = 0;
int ile_fun_call = 0;
void add_zapamietane_funkcje(char *funame);
void idz_pocz_listy(list_zapamietane_funkcje lista);

#endif

