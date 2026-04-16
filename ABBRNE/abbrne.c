#include <stdio.h>
#include <stdlib.h>

#define PRETO 0
#define VERMELHO 1

typedef struct celula {
    int dado;
    int cor;

    struct celula *esq;
    struct celula *dir;
} celula;

celula *rotacao_a_esquerda(celula *raiz){
    celula *a = raiz->dir;
    a->cor = raiz->cor;
    raiz->cor = VERMELHO;
    celula *beta = a->esq;
    a->esq = raiz;
    raiz->dir = beta;
    return a;
}

celula *rotacao_a_direita(celula *raiz){
    celula *a = raiz->esq;
    a->cor = raiz->cor;
    raiz->cor = VERMELHO;
    celula *beta = a->dir;
    a->dir = raiz;
    raiz->esq = beta;
    return a;
}
void sobe_cor(celula *raiz){
    raiz->cor = VERMELHO;
    raiz->esq->cor = raiz->dir->cor = PRETO;
}

int ehPreto(celula *raiz) {
    return raiz == NULL || raiz->cor == PRETO;
}   

int ehVerm(celula *raiz) {
    return raiz != NULL && raiz->cor == VERMELHO;
}

celula *insere_abbrne (celula *raiz, int x){
    if (raiz != NULL){
        if (x < raiz->dado){
            raiz->esq = insere_abbrne(raiz->esq, x); 
        }
        else if (x > raiz-> dado){
            raiz->dir = insere_abbrne (raiz->dir, x);
        }
        if (ehPreto(raiz->esq) && ehVerm(raiz->dir)){
            raiz = rotacao_a_esquerda(raiz);
        }
        if (ehVerm(raiz->esq) && ehVerm(raiz -> esq -> esq)){
            raiz = rotacao_a_direita(raiz);
        }
        if (ehVerm(raiz->esq) && ehVerm(raiz->dir)){
            sobe_cor(raiz);
        }
        return raiz; 
    }
    else{
        celula *novo = malloc(sizeof(celula));
        novo->esq = novo->dir = NULL;
        novo->dado = x;
        novo->cor = VERMELHO;
        return novo; 
    }
}

celula *insere (celula *raiz, int x){
    raiz = insere_abbrne(raiz, x);
    raiz->cor = PRETO;          // a raiz é preta indepentemente se em algum momento for vermelha por conta das correções, assim,
    return raiz;               // se em algum momento a operação sobe_cor for realizada na raiz, significa que a altura negra aumentou
}

void imprime(celula *raiz, int nivel) {
    if (raiz == NULL) return;

    imprime(raiz->dir, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("   ");
    }

    printf("%d (%s)\n", raiz->dado, raiz->cor == VERMELHO ? "V" : "P");

    imprime(raiz->esq, nivel + 1);
}

int main (){

    celula *raiz = NULL;

    int valores[] = {10, 20, 30, 15, 5, 1};
    int n = 6;

    for (int i = 0; i < n; i++) {
        raiz = insere(raiz, valores[i]);
    }

    imprime(raiz, 0);
    printf("Raiz: %d\n", raiz->dado);

    return 0;
}