#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alex.h"
#include "fun_stack.h"
#include "store.h"


int main(int argc, char **argv){
    
    if(argc == 1){
        fprintf(stderr, "Blad: Prosze podac co najmniej jeden plik zrodlowy.\n");
        return EXIT_FAILURE;
    {
    
    int i, j;

    //struktura **tab = malloc

    for(i=1; i<argc; i++){
        list_zapamietane_funkcje list_fun = malloc(1 * sizeof(*list_fun));
        lista_fun_def list_fun_def = malloc(1 * sizeof(*list_fun_def));
        lista_fun_proto list_fun_proto = malloc(1 * sizeof(*list_fun_proto));
        lista_fun_call list_fun_call = malloc(1 * sizeof(*list_fun_call));
        /*
        int zal_ile = 10;
        struktura **tab_def = malloc(zal_ile * sizeof(*tab_def));
        struktura **tab_proto = malloc(zal_ile * sizeof(*tab_proto));
        struktura **tab_call = malloc(zal_ile * sizeof(*tab_call));
        for(j=0; j<zal_ile; j++){
            tab_def[j] = malloc(1 * sizeof(*tab_def));
            tab_proto[j] = malloc(1 * sizeof(*tab_proto));
            tab_call[j] = malloc(1 * sizeof(*tab_call));
        }
        */
        analizatorSkladni(argv[i]); //wywolujemy analizatorSkladni dla kazdego pliku zrodl.
        idz_pocz_listy(list_fun);       //<-- lista odnosi sie teraz do pierwszej struktury
        for(j = 0; j<ile_funkcji; j++){         //i od niej zaczynamy wypisywanie funkcji
	        printf("Funkcja %s:\n", list_fun->nazwa);       //w kazdym pliku zrodlowym
            printf("\tPrototyp:\n");
            printf("\t\tplik %s
            
	    }


        
        while(list_fun->prev != NULL){
            free(list_fun->nazwa);
            list_fun = list_fun->prev;
        }
        free(list_fun);

        while
        free(list_fun_def);
        free(list_fun_proto);
        free(list_fun_call);
    }
    

    return 0;

}
