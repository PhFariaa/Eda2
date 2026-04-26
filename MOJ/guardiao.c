#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;


int numero_folhas(no *r){

    int total = 0; 

    if (r->esq == NULL && r->dir == NULL){
        return total +=1;
    }
    if (r->esq != NULL){
        total += numero_folhas(r->esq);
    }
    if (r->dir != NULL){
        total += numero_folhas(r->dir);
    }
    return total;      
}