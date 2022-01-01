#include <stdio.h>
#include <stdlib.h>

#include "fun_stack.h"
#include "store.h"


void store_add_def(char *funame, int par_level, FILE *file){
    int k = 0;
    if(list_fun_def == NULL){
        list_fun_def->name_fun_def = malloc((strlen(funame) + 1) * sizeof(*list_fun_def->name_fun_def));
        list_fun_def->name_fun_def = funame;
        list_fun_def->linie_fun_def = malloc(1 * sizeof(*list_fun_def->linie_fun_def));
        list_fun_def->linie_fun_def[k] = &par_level;
        list_fun_def->next = NULL;
        

    }

}



void store_add_proto(char *funame, int par_level, FILE *file){


}

void store_add_call(char *funame, int par_level, FILE *file){



}

