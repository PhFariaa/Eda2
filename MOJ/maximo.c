#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;


int numero_folhas(no *r){

    while(r->dir != NULL){
        r = r->dir;
    }
    return r;  
}