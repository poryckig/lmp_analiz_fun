#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"

typedef struct lista {
        char* funame;
        int par_level;
        struct lista* prev_stack;
} sterta_t;


static sterta_t *sterta;
char funame_tmp[256]; //maksymalna długość nazwy funkcji

void stack_init( sterta_t* sterta ){
        sterta = malloc( sizeof sterta );
        sterta->funame = malloc(sizeof (char));
        sterta->funame = '\0';
        sterta->par_level = 0;
        sterta->prev_stack = NULL;
}

int top_of_funstack(){
        return sterta->par_level;
}

void put_on_fun_stack (int par_level, char *funame){
        sterta_t *tmp = malloc( sizeof tmp);
        tmp->funame = malloc(sizeof tmp->funame * strlen(funame) + 1);
        strcpy( tmp->funame, funame);
        tmp->par_level = par_level;
        tmp->prev_stack = sterta;
        sterta = tmp;
}

char* get_from_fun_stack(){
        strcpy( funame_tmp, sterta->funame);

        sterta_t * to_remove = sterta;
        sterta = sterta->prev_stack;
        free(to_remove->funame);
        free(to_remove);

        return funame_tmp;
}



void add_zapamietane_funkcje(char *funame, list_zapamietane_funkcje lista){
    if(lista == NULL){
        lista->nazwa = malloc((strlen(funame) + 1) * sizeof(*lista->nazwa));
        strcpy(lista->nazwa, funame);
        lista->next = NULL;
	    ile_funkcji++;
    }
    if(lista != NULL){
        lista->next->nazwa = malloc((strlen(funame) + 1) * sizeof(*lista->next->nazwa));
        strcpy(lista->next->nazwa, funame);
        lista = lista->next;
        lista->next = NULL;
	    ile_funkcji++;
    }
}

void idz_pocz_listy(list_zapamietane_funkcje lista){
    while(lista->prev != NULL)
	    lista = lista->prev;
}
