#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alex.h"
#include "fun_stack.h"
#include "store.h"
#include "parser.h"


int main(int argc, char **argv){
    
    if(argc == 1){
        fprintf(stderr, "Blad: Prosze podac co najmniej jeden plik zrodlowy.\n");
        return EXIT_FAILURE;
    {
    
    int i, j, k, l;
    int ile_funkcji, ile_fun_def, ile_fun_proto, ile_fun_call;
    int licznik = 0;
    

    for(i=1; i<argc; i++){
        list_zapamietane_funkcje list_fun = malloc(1 * sizeof(*list_fun));
        lista_fun_def list_fun_def = malloc(1 * sizeof(*list_fun_def));
        lista_fun_proto list_fun_proto = malloc(1 * sizeof(*list_fun_proto));
        lista_fun_call list_fun_call = malloc(1 * sizeof(*list_fun_call));
        ile_funkcji = 0;
        ile_fun_def = 0;
        ile_fun_proto = 0;
        ile_fun_call = 0;
        
        analizatorSkladni(argv[i], list_fun, list_fun_def, list_fun_proto, list_fun_call); //wywolujemy analizatorSkladni dla kazdego pliku zrodl.
        idz_pocz_listy(list_fun);       //<-- lista odnosi sie teraz do pierwszej struktury
        idz_pocz_listy_def(list_fun_def);
        idz_pocz_listy_proto(list_fun_proto);
        idz_pocz_listy_call(list_fun_call);
        printf("***W PLIKU: %s ***\n\n", argv[i]);
        for(j = 0; j<ile_funkcji; j++){         //i od niej zaczynamy wypisywanie funkcji
	        printf("Funkcja %s:\n", list_fun->nazwa);       //w kazdym pliku zrodlowym
            printf("\tPrototyp:\n");
            if(list_fun_proto == NULL){
                printf("brak\n");       //<-- ta funkcja nie jest prototypem w tym pliku
                goto etyk_def;           //<-- idziemy teraz do wypisywania dla tej funkcji definicji
            }
            for(k=0; k<ile_fun_proto; k++){   //w tym pliku sa jakies prototypy, iterujemy po kazdym prototypie
                if(strcmp(list_fun->nazwa, list_fun_proto->name_fun_proto) == 0){   //sprawdzamy, czy akurat ta funkcja
                    for(l=0; l<ile_linii_fun_proto; l++){                           //jest prototypem
                        printf("plik %s od linia %d do linia %d\n", argv[i], list_fun_proto->linie_fun_proto[l], list_fun_proto->linie_fun_proto[l]);
                    }
                    licznik++;
                    if(k+1 < ile_fun_proto){
                        list_fun_proto = list_fun_proto->next;
                        continue;
                    }
                    else
                        break;  
                }
                else {
                    if(k+1 <ile_fun_proto){
                        list_fun_proto = list_fun_proto->next;   //przechodzimy do nastepnego prototypu i bedziemy
                        continue;                                   //sprawdzac, czy ta funkcje nie jest moze nastepnym
                    }                                               //prototypem
                    else
                        break;
                }                                               
            }
            idz_pocz_listy_proto(list_fun_proto);
            if(licznik == 0){      //<-- to znaczy, ze ta funkcja nie jest zadnym prototypem                             
                printf("brak\n");
                goto etyk_def;
            }                                               
    

            etyk_def:
            licznik = 0;
            printf("\tDefinicja:\n");
    
            


            etyk_uzycie:
            licznik = 0;
            printf("\tUzycie:\n");

            if(j+1 < ile_funkcji){
                list_fun = list_fun->next;
                continue;
            }
            else
                break;
	    }


        //***ZWALNIANIE PAMIECI DLA LIST W TYM PLIKU***//
        free(list_fun->nazwa);
        while(list_fun->prev != NULL){
            list_fun = list_fun->prev;
            free(list_fun->nazwa);
        }
        free(list_fun);
        
        free(list_fun_proto->name_fun_proto);
        while(list_fun_proto->next != NULL){
            list_fun_proto = list_fun_proto->next;
            free(list_fun_proto->name_fun_proto);
        }
        //zwolnic dla linii
        free(list_fun_proto);

        free(list_fun_def->name_fun_def);
        while(list_fun_def->next != NULL){
            list_fun_def = list_fun_def->next;
            free(list_fun_def->name_fun_def);
        }
        //zwolnic dla linii
        free(list_fun_def);

        free(list_fun_call->name_fun_call);
        while(list_fun_call->next != NULL){
            list_fun_call = list_fun_call->next;
            free(list_fun_call->name_fun_call);
        }
        //zwolnic dla linii
        free(list_fun_call);
    }
    
    return 0;
}


