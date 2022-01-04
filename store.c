#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_stack.h"
#include "store.h"



void store_add_def(char *funame, int linia, lista_fun_def lista2){
    int i;
    if(lista2 == NULL){
        lista2->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*lista2->name_fun_def));
        strcpy(lista2->name_fun_def, funame);
        lista2->linie_fun_def = malloc(1 * sizeof(*lista2->linie_fun_def));
	lista2->linie_koncowe = malloc(1* sizeof(*lista2->linie_koncowe));
        lista2->linie_fun_def[lista2->ile_linii] = linia;
	    lista2->ile_linii++;
       	lista2->next = NULL;
	    ile_fun_def++;    //teraz ile_fun_def == 1
    }
    else {
        idz_pocz_listy_def(lista2);
        for(i=0; i<ile_fun_def; i++){
            if(strcmp(lista2->name_fun_def, funame) == 0){
                realloc(lista2->linie_fun_def, (lista2->ile_linii + 1) * sizeof(*lista2->linie_fun_def));
		realloc(lista2->linie_koncowe, (lista2->ile_linii + 1) * sizeof(*lista2->linie_koncowe));
                lista2->ile_linii++;   //lista2->ile_linii == 2
                lista2->linie_fun_def[lista2->ile_linii - 1] = linia;    // 2 - 1 = 1
                break;
            }
            else {
                if(i+i < ile_fun_def){
                    lista2 = lista2->next;
                    continue;
                }
                else {
                    lista2->next->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*lista2->next->name_fun_def));
                    lista2->next->linie_fun_def = malloc(1 * sizeof(*lista2->next->linie_fun_def));
		    lista2->next->linie_koncowe = malloc(1* sizeof(*lista2->next->linie_koncowe));            
                    strcpy(lista2->next->name_fun_def, funame);
                    lista2->next->linie_fun_def[lista2->next->ile_linii] = linia;
                    lista2->next->ile_linii++;
                    lista2 = lista2->next;
                    lista2->next = NULL;
                    ile_fun_def++;     //teraz ile_fun_def == 2
                    break;
                }    
            }
        }   
    }
}


void store_add_proto(char *funame, int linia, lista_fun_proto lista3){
    int i;
    if(lista3 == NULL){
        lista3->name_fun_proto = malloc((strlen(funame) + 1) * sizeof(*lista3->name_fun_proto));
        strcpy(lista3->name_fun_proto, funame);
        lista3->linie_fun_proto = malloc(1 * sizeof(*lista3->linie_fun_proto));
        lista3->linie_fun_proto[lista3->ile_linii] = linia;
	lista3->ile_linii++;
        lista3->next = NULL;
	ile_fun_proto++;    //teraz ile_fun_proto == 1
    }
    else {
        idz_pocz_listy_proto(lista3);
        for(i=0; i<ile_fun_proto; i++){
            if(strcmp(lista3->name_fun_proto, funame) == 0){
                realloc(lista3->linie_fun_proto, (lista3->ile_linii + 1) * sizeof(*lista3->linie_fun_proto));
                lista3->ile_linii++;   //lista3->ile_linii == 2
                lista3->linie_fun_proto[lista3->ile_linii - 1] = linia;    // 2 - 1 = 1
                break;
            }
            else {
                if(i+i < ile_fun_proto){
                    lista3 = lista3->next;
                    continue;
                }
                else {
                    lista3->next->name_fun_proto = malloc((strlen(funame) + 1) * sizeof(*lista3->next->name_fun_proto));
                    lista3->next->linie_fun_proto = malloc(1 * sizeof(*lista3->next->linie_fun_proto));            
                    strcpy(lista3->next->name_fun_proto, funame);
                    lista3->next->linie_fun_proto[lista3->next->ile_linii] = linia;
                    lista3->next->ile_linii++;
                    lista3 = lista3->next;
                    lista3->next = NULL;
                    ile_fun_proto++;     //teraz ile_fun_proto == 2
                    break;
                }    
            }
        }   
    }
}


void store_add_call(char *funame, int linia, lista_fun_call lista4){
    int i;
    if(lista4 == NULL){
        lista4->name_fun_call = malloc((strlen(funame) + 1) * sizeof(*lista4->name_fun_call));
        strcpy(lista4->name_fun_call, funame);
        lista4->linie_fun_call = malloc(1 * sizeof(*lista4->linie_fun_call));
        lista4->linie_fun_call[lista4->ile_linii] = linia;
	    lista4->ile_linii++;
       	lista4->next = NULL;
	    ile_fun_call++;    //teraz ile_fun_call == 1
    }
    else {
        idz_pocz_listy_call(lista4);
        for(i=0; i<ile_fun_call; i++){
            if(strcmp(lista4->name_fun_call, funame) == 0){
                realloc(lista4->linie_fun_call, (lista4->ile_linii + 1) * sizeof(*lista4->linie_fun_call));
                lista4->ile_linii++;   //lista4->ile_linii == 2
                lista4->linie_fun_call[lista4->ile_linii - 1] = linia;    // 2 - 1 = 1
                break;
            }
            else {
                if(i+i < ile_fun_call){
                    lista4 = lista4->next;
                    continue;
                }
                else {
                    lista4->next->name_fun_call = malloc((strlen(funame) + 1) * sizeof(*lista4->next->name_fun_call));
                    lista4->next->linie_fun_call = malloc(1 * sizeof(*lista4->next->linie_fun_call));            
                    strcpy(lista4->next->name_fun_call, funame);
                    lista4->next->linie_fun_call[lista4->next->ile_linii] = linia;
                    lista4->next->ile_linii++;
                    lista4 = lista4->next;
                    lista4->next = NULL;
                    ile_fun_call++;     //teraz ile_fun_call == 2
                    break;
                }    
            }
        }   
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
