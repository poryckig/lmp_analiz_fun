#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"


int top_of_funstack(void){


}


void put_on_fun_stack(int par_level, char *funname){


}


char *get_from_fun_stack(void){


}


void add_zapamietane_funkcje(char *funame){
    if(list_fun == NULL){
        list_fun->nazwa = malloc((strlen(funame) + 1) * sizeof(*list_fun->nazwa));
        strcpy(list_fun->nazwa, funame);
        list_fun->next = NULL;
	    ile_funkcji++;
    {
    if(list_fun != NULL){
        list_fun->next->nazwa = malloc((strlen(funame) + 1) * sizeof(*list_fun->next->nazwa));
        strcpy(list_fun->next->nazwa, funame);
        list_fun = list_fun->next;
        list_fun->next = NULL;
	    ile_funkcji++;
    }
}

void idz_pocz_listy(list_zapamietane_funkcje lista){
    while(lista->prev != NULL)
	    lista = lista->prev;
}
