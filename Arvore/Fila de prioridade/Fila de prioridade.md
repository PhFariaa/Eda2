## Fila de Prioridade


É uma estrutura de dados com duas operações:
- Inserção
- Remoção (ou extração) do elemento de maior prioridade
  
Consideraremos "maior prioridade" o "maior número" entre os inteiros.

Para representar FPs, utilizaremos àrvores binárias completas.

Uma AB completa é uma AB em que todos os níveis possuem o máximo de nós, com exceção, talvez, do último onde os nós estarão à esquerda

Numa AB completa que representa uma FP, vale a seguinte regra: "para todo nó, seu valor possui maior prioridade que seus filhos".

Para implementarmos uma AB completa, utilizaremos vetores da seguinte forma:



Deste modo temos que
```
V[0] é raiz e
- se V[i] é um nó qualquer:
  -> V[2i+1] é seu filho esquerdo
  -> V[2i+2] é seu filho direito
  -> V[(i-1)/2] é seu pai
``` 
```
typedef struct {
int *dado;
int tamanho, n;
} FP;

Fp *cria_fp(int tamanho);
void insere(FP *f, int x);
int extrair_maximo(FP *f);
void destroi_fp(FP *f);


void insere (FP *fp, int x){
	if (fp -> tam <= fp -> n){
		fp->dado = realloc(2*fp->tam*sizeof(int));
		fp->tam *=2;	
	}
	fp->dado[fp->n] = x;
	fp->n++;
	sobe_no_heap(fp);
}

void sobe_no_heap(FP *fp){
	int i = fp->n-1
	int pai = (i-1)/2
	
	while (i>0 && fp->dado[pai] < fp->dado[i]){
		troca(&fp->dado[pai], &fp->dado[i]);
		i=pai;
		pai = (i-1)/2;
	}
}

int extrai_maximo(FP *fp{
  if (fp->n > 0){
    int max = dado[0];
    fp->dado[0] = fp->dado[fp->n-1];
    fp->n--;
    desce_no_heap(fp);
    return max;
  }
}


void desce_no_heap(FP *fp){
	int i = 0, esq = 1, dir = 2, maior_filho;
	
	while(esq < f -> n){
		maior_filho = esq;
		if (dir < f-> n && f->dado[dir] > f->dado[maior_filho]){
			maior_filho = dir;
		}
		
		if (f->dado[i] < f->dado[maior_filho]){
			troca(&f->dado[i], &f->dado[maior_filho]);
			i=maior_filho;
			esq = 2*i+1;
			dir = 2*i+2;
		}else{
			return;
		}	
	}
}


FP *cria_heap(int tam){
	FP *f = malloc(sizeof(fp));
	f->dado =  malloc(tam*sizeof(int));
	f->tam = tam;
	f->n = 0;
	return f; 
}

void destroi_heap(*FP fp){
	free(f->dado);
	free(f);
}


```
