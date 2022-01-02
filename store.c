#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"
#include "store.h"


void store_add_def(char *funame, int par_level, FILE *file){
    if(list_fun_def == NULL){
        list_fun_def->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*list_fun_def->name_fun_def));
        strcpy(list_fun_def->name_fun_def, funame);
        list_fun_def->linie_fun_def = malloc(1 * sizeof(*list_fun_def->linie_fun_def));
        list_fun_def->linie_fun_def[ile_fun_def] = &par_level;
        list_fun_def->next = NULL;
	    ile_fun_def++;
    }
    if(list_fun_def != NULL){
        list_fun_def->next->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*list_fun_def->next->name_fun_def));
	    list_fun_def->next->linie_fun_def = malloc(1 * sizeof(*list_fun_def->next->linie_fun_def));
	    strcpy(list_fun_def->next->name_fun_def, funame);
        list_fun_def->next->linie_fun_def[ile_fun_def] = &par_level;
        list_fun_def = list_fun_def->next;
        list_fun_def->next = NULL;
	    ile_fun_def++;
    }
}


void store_add_proto(char *funame, int par_level, FILE *file){
    if(list_fun_proto == NULL){
        list_fun_proto->name_fun_proto = malloc((strlen(funame) + 1) * sizeof(*list_fun_proto->name_fun_proto));
        strcpy(list_fun_proto->name_fun_proto, funame);
        list_fun_proto->linie_fun_proto = malloc(1 * sizeof(*list_fun_proto->linie_fun_proto));
        list_fun_proto->linie_fun_proto[ile_fun_proto] = &par_level;
        list_fun_proto->next = NULL;
	    ile_fun_proto++;
    }
    if(list_fun_proto != NULL){
        list_fun_proto->next->name_fun_proto = malloc((strlen(funame) + 1) * sizeof(*list_fun_proto->next->name_fun_proto));
	    list_fun_proto->next->linie_fun_proto = malloc(1 * sizeof(*list_fun_proto->next->linie_fun_proto));
	    strcpy(list_fun_proto->next->name_fun_proto, funame);
        list_fun_proto->next->linie_fun_proto[ile_fun_proto] = &par_level;
        list_fun_proto = list_fun_proto->next;
        list_fun_proto->next = NULL;
	    ile_fun_proto++;
    }
}


void store_add_call(char *funame, int par_level, FILE *file){
    if(list_fun_call == NULL){
        list_fun_call->name_fun_call = malloc((strlen(funame) + 1) * sizeof(*list_fun_call->name_fun_call));
        strcpy(list_fun_call->name_fun_call, funame);
        list_fun_call->linie_fun_call = malloc(1 * sizeof(*list_fun_call->linie_fun_call));
        list_fun_call->linie_fun_call[ile_fun_call] = &par_level;
        list_fun_call->next = NULL;
	    ile_fun_call++;
    }   
    if(list_fun_call != NULL){
        list_fun_call->next->name_fun_call = malloc((strlen(funame) + 1) * sizeof(*list_fun_call->next->name_fun_call));
	    list_fun_call->next->linie_fun_call = malloc(1 * sizeof(*list_fun_call->next->linie_fun_call));
	    strcpy(list_fun_call->next->name_fun_call, funame);
        list_fun_call->next->linie_fun_call[ile_fun_call] = &par_level;
        list_fun_call = list_fun_call->next;
        list_fun_call->next = NULL;
	    ile_fun_call++;
    }
}


void idz_pocz_listy_def(lista_fun_def lista){
    while(lista->prev != NULL)
	    lista = lista->prev;
}

void idz_pocz_listy_proto(lista_fun_proto lista){
    while(lista->prev != NULL)
	    lista = lista->prev;
}

void idz_pocz_listy_call(lista_fun_call lista){
    while(lista->prev != NULL)
	    lista = lista->prev;
}
