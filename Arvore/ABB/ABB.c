#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq;
    struct no *dir;
} No;

No* criarNo(int chave) {
    No* novo = (No*) malloc(sizeof(No));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}
No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }
    if (chave < raiz->chave) {
        raiz->esq = inserir(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        raiz->dir = inserir(raiz->dir, chave);
    }
    return raiz;
}

No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return buscar(raiz->esq, chave);
    }

    return buscar(raiz->dir, chave);
}

// Encontra o menor valor de uma subárvore
No* minimo(No* raiz) {
    while (raiz != NULL && raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    } else {
        if (chave < raiz->chave) {
            raiz->esq = remover(raiz->esq, chave);
        } 
        else if (chave > raiz->chave) {
            raiz->dir = remover(raiz->dir, chave);
        } 
        else {
            if (raiz->esq == NULL && raiz->dir == NULL) { //no folha
                free(raiz);
                return NULL;
            }

            if (raiz->esq == NULL) { //casos com um filho só, não é necessário verificar se o outro lado também é NULL
                No* temp = raiz->dir; //porque se os dois fossem NULL já teria caído no if de cima (59)
                free(raiz);
                return temp;
            }

            if (raiz->dir == NULL) {
                No* temp = raiz->esq;
                free(raiz);
                return temp;
            }

            No* sucessor = minimo(raiz->dir);

            raiz->chave = sucessor->chave;

            raiz->dir = remover(raiz->dir, sucessor->chave);
        }
    }

    return raiz;
}
