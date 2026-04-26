#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura (no *r){

    if (r == NULL){
        return 0;
    }
    int altura_esquerda = altura(r->esq);
    int altura_direita = altura(r->dir);
    return 1 + ((altura_esquerda > altura_direita) ? altura_esquerda : altura_direita); 
}