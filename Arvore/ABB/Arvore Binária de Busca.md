
## Árvore Binária de Busca

Uma árvore binária é uma estrutura em que o nó pai tem, no máximo, dois filhos, o filho esquerdo e o filho direito. Uma árvore binária de busca é uma árvore binária em que os menores elementos ficam à esquerda e os maiores elementos ficam à direita, tornando assim a busca mais simples de ser feita.

##### Complexidade
Uma ABB (Árvore Binária de Busca) tem complexidade diretamente ligada à altura, normalmente uma ABB tem altura e complexidade O(log n), no pior caso uma ABB tem complexidade O(n) quando for uma árvore degenerada, se tornando uma lista encadeada.

##### Operações
Busca:
- A busca começa examinando o nó raiz. Se o valor for menor que a raiz a busca segue pela subárvore esquerda e se for maior segue pela subárvore direita até que ou o valor seja encontrado ou a subárvore ser nula.
Inserção:
- A inserção começa com uma busca, eventualmente ou o valor vai ser encontrado ou o algoritmo chegará à folha, inserindo o valor na posição adequada.
Remoção:
- O processo de remoção costuma ser algo mais complexo, no caso de uma ABB devemos verificar algumas condições. Se o nó for folha, basta remove-lo. Se o nó tiver somente um filho, o filho assume a posição do pai, Exemplo:
  ![[Pasted image 20260426154217.png]]
  Caso o nó tenha dois filhos ai temos duas opções de operar, obtendo o sucessor ou o antecessor do nó na árvore, sendo o antecessor o maior valor da subárvore esquerda e o sucessor o menor valor da subárvore direita, assim que obtivermos o antecessor ou o sucessor, então os nós devem ser trocados de lugar para que o nó original possa ser removido sem alterar a propriedade de busca da árvore. Exemplo:
  ![[Pasted image 20260426154501.png]]
  No exemplo acima, o nó de valor 30 está para ser removido, e possui como sucessor imediato o valor 35 (nó mais à esquerda da sua sub-árvore direita). Assim sendo, na exclusão, o valor 35 será promovido no lugar do nó a ser excluído, enquanto a sua sub-árvore (direita) será promovida para sub-árvore esquerda do 40, como pode ser visto na figura.

##### Percusos
Em uma ABB pode-se fazer 3 percursos, são eles: pré-order, in-order e pos-order.
- Pré-order: raiz, esquerda, direita
- In-order: esquerda, raiz, direita
- Pós-order: esquerda, direita, raiz
Exemplo:
![[Pasted image 20260426155127.png]]
Utilizando essa árvore, teríamos:
Pré-order => 8, 3, 1, 6, 4, 7, 10, 14, 13

In-order => 1, 3, 4, 6, 7, 8, 10, 13, 14 

Pós-order => 1, 4, 7, 6, 3, 13, 14, 10, 8
