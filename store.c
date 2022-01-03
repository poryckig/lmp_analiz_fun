#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"
#include "store.h"



void store_add_def(char *funame, int par_level, lista_fun_def lista2){
    if(lista2 == NULL){
        lista2->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*lista2->name_fun_def));
        strcpy(lista2->name_fun_def, funame);
        lista2->linie_fun_def = malloc(1 * sizeof(*lista2->linie_fun_def));
        lista2->linie_fun_def[ile_fun_def] = par_level;
        lista2->next = NULL;
	    ile_fun_def++;
    }
    if(lista2 != NULL){
        lista2->next->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*lista2->next->name_fun_def));
	    lista2->next->linie_fun_def = malloc(1 * sizeof(*lista2->next->linie_fun_def));
	    strcpy(lista2->next->name_fun_def, funame);
        lista2->next->linie_fun_def[ile_fun_def] = par_level;
        lista2 = lista2->next;
        lista2->next = NULL;
	    ile_fun_def++;
    }
}


void store_add_proto(char *funame, int par_level, lista_fun_proto lista3){
    if(lista3 == NULL){
        lista3->name_fun_proto = malloc((strlen(funame) + 1) * sizeof(*lista3->name_fun_proto));
        strcpy(lista3->name_fun_proto, funame);
        lista3->linie_fun_proto = malloc(1 * sizeof(*lista3->linie_fun_proto));
        lista3->linie_fun_proto[ile_fun_proto] = par_level;
        lista3->next = NULL;
	    ile_fun_proto++;
    }
    if(lista3 != NULL){
        lista3->next->name_fun_proto = malloc((strlen(funame) + 1) * sizeof(*lista3->next->name_fun_proto));
	    lista3->next->linie_fun_proto = malloc(1 * sizeof(*lista3->next->linie_fun_proto));
	    strcpy(lista3->next->name_fun_proto, funame);
        lista3->next->linie_fun_proto[ile_fun_proto] = par_level;
        lista3 = lista3->next;
        lista3->next = NULL;
	    ile_fun_proto++;
    }
}


void store_add_call(char *funame, int par_level, lista_fun_call lista4){
    if(lista4 == NULL){
        lista4->name_fun_call = malloc((strlen(funame) + 1) * sizeof(*lista4->name_fun_call));
        strcpy(lista4->name_fun_call, funame);
        lista4->linie_fun_call = malloc(1 * sizeof(*lista4->linie_fun_call));
        lista4->linie_fun_call[ile_fun_call] = par_level;
        lista4->next = NULL;
	    ile_fun_call++;
    }   
    if(lista4 != NULL){
        lista4->next->name_fun_call = malloc((strlen(funame) + 1) * sizeof(*lista4->next->name_fun_call));
	    lista4->next->linie_fun_call = malloc(1 * sizeof(*lista4->next->linie_fun_call));
	    strcpy(lista4->next->name_fun_call, funame);
        lista4->next->linie_fun_call[ile_fun_call] = par_level;
        lista4 = lista4->next;
        lista4->next = NULL;
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
