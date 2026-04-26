## Tabela de dispersão
Uma tabela de dispersão (hash) é uma estrutura de dados que, usando um vetor:
- insere um objeto na posição f(obj) onde f é o que chamamos de função de espalhamento (hash)
A função de hash calcula um valor numérico a partir do objeto. 
Chamamos de colisão quando a função de hash gera o mesmo valor para duas entradas distintas.

Se a função de hash fosse injetora, o custo de busca e inserção na tabela hash seria O(1).

Chamamos isso de hash perfeito. No caso médio, suponha que temos uma tabela hash de tamanho M. Se os dados não forem viciados, ao inserir um elemento na tabela, a probabilidade deste elemento ocupar uma posição qualquer é 1/M.

Depois de inserir n elementos, espera-se que cada posição da tabela possua n/m elementos, ou seja, o custo médio da busca, inserção e remoção é O(n/m)

Obs: M tem relação com o tamanho do domínio, que nem sempre é conhecido.

#### Implementação
Para implementar uma tabela hash, é preciso decidir: 
 - o tamanho M da tabela e afunção de espalhamento.
 - A estratégia para lidar com as colisões.

##### Funções de Hash Padrão
A função de hash mais comum é o método da divisão:
	- f(x) = x mod M.
Funciona quando o objeto (ou chave) for numérico.
- Para uma string: 
	``` f(str) = (str[0], 256^t-1 + str[1], 256^t-2 + ... + str[t-1]) mod M.```  // conversão de uma string para um número decimal, onde t é o tamanho da string

Há ainda o método da multiplicação:
``` f(x) = [M.(A.x) mod 1]   ```

Onde A é um número real qualquer e o resultado tem que ser arredondado para baixo

E o hashing universal - dado um inteiro p:
``` 
F a,b (x) = ((a.x+b) mod p) mod M

Com a, b pertencentes ao conjunto {1, ..., p} escolhidos aleatoriamente a cada chamada de função
