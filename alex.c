#include "alex.h"

#include <ctype.h>

static int ln= 0;
static char ident[256];
static FILE *ci= NULL;

void alex_init4file( FILE *in ) {
   ln= 0;
   ci= in;
}

lexem_t alex_nextLexem( void ) {
    int c;
    while( (c= fgetc(ci)) != EOF ) {
        if( isspace( c ) )
            continue;
        else if( c == '\n' )
            ln++;
        else if( c == '(' )
            return OPEPAR;
        else if( c == ')' )
            return CLOPAR;
        else if( c == '{' )
            return OPEBRA;
        else if( c == '}' )
            return CLOBRA;
        else if( isalpha( c ) ) {
            int i= 1;
            ident[0] = c;
            while( isalnum( c= fgetc(ci) ) )
                ident[i++] = c;
            ident[i] = '\0';
            return isKeyword(ident) ? OTHER : IDENT;
        }
        else if( c == '"' ) {     /* obsluga znaku nowej linii w stringu */
            while( (c = fgetc(in)) != EOF && c != '"'){
                if(c == '\n')
                    ln ++;
                //if(c == '\\')
                    //.......
            } 
            else if(c == EOF)
                return ERROR;   //bo mamy sytuacje: printf("....    //blad skladni
            else
                continue;
        }
        
    /*
    while( (c= fgetc(ci)) != EOF && c != '"' && cp == '\\' ) {
        cp = c;
      }
      return c==EOF ? EOFILE : OTHER; 
    */


               //***KOMENTARZE***//
        else if( c == '/' ) {    //sprawdzamy komentarze
            if( (c = fgetc(in)) == '/') {       //komentarz jednolinijkowy
                while((c = fgetc(in)) != '\n')
                    continue;
                else {
                    ln++;
                    return COMMENT;
                }
            }
            if((c = fgets(in)) == '*') {      //komentarz wielolinijkowy
                etykieta1:
                while((c = fgets(in)) != EOF && c ! '*'){
                    if(c == '\n'){
                        ln++;
                        continue;
                    }
                    else
                        continue;
                }
                if(c == '*'){
                    if((c = fgets(in)) == '/')
                        return COMMENT;
                    else if((c = fgets(in)) == '\n'){
                        ln++;
                        goto etykieta1;
                    }
                    else if((c = fgetc(in)) == EOF)
                        return ERROR;       //nie domkniecie komentarza wielolinijkowego traktujemy jako blad skladni
                    else
                        goto etykieta1;
                }
                else
                    return ERROR; //nie domkniecie komentarza wiel. <- blad skladni   
            }
                //***KONIEC KOMENTARZY***//
    


        }       //***LICZBY***//
        /* zle
        else if( isdigit( c ) ) {
            if((c = fgetc(in)) == '.'){
                if(isdigit(c = fgetc(in)))
                    continue;
                else
                    return ERROR;       //blad skladni: sytuacja np: 23. //
            else
                continue
            }
        }
        */
                //***KONIEC LICZB***//
        else 
            return OTHER;
    }       
    return EOFILE;
}

///////


char * alex_ident( void ) {
    return ident;
}

int alex_getLN() {
    return ln;
}

