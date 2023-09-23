<div style="display: inline-block;">
    <img align="center" height="20px" width="50px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
    <img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
    <img align="center" height="20px" width="60px" th="60px" src="https://img.shields.io/badge/Linux-E34F26?style=for-the-badge&logo=linux&logoColor=black"/>
</div>

# Atividade 1: Árvores

Um exemplo clássico de problema que pode ser solucionado utilizando-se _hash_ e heap é o chamado top _k_ itens. Neste problema, é preciso encontrar os _k_ itens mais valiosos de uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos _k_ itens de maior valor. Sabendo-se disso, foi elaborada uma solução em _C++_ que dado uma entrada:

- Cria uma tabela de dispersão (_hash_) para contar a frequência de cada elemento tokenizado da coleção de dados de entrada.

- Cria uma árvore de prioridades (_heap_) de tamanho _k_ e insere os primeiros _k_ elementos do hash nela.

  1. Para cada elemento restante na hash, compare a contagem com o menor valor do heap.

  1. Se a contagem for maior do que o menor valor da heap, remova o menor valor, insira o novo elemento e refaça a estrutura.

  1. Caso contrário, ignore o elemento e vá para o próximo.

- No final, a heap conterá os _k_ elementos com maiores valores (frequências) da coleção de dados. Então, imprima-os em ordem crescente.

Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos elementos e heap para manter a lista dos _k_ elementos com maiores valores. Sua complexidade, caso implementado adequadamente, é de _O(n log k)_, onde n é o tamanho da coleção de dados e _k_ o número de itens mais relevantes.

Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários. Para atingir essa finalidade, será adotada a estrutura da árvore binária como base.

### Quais as vantagens da árvore binária?

A busca de elementos é uma das tarefas fundamentais na área da ciência da computação. Tal objetivo pode ser alcançado com a utilização da estrutura árvore de busca binária. Uma árvore de busca binária é uma estrutura de dados na qual cada nó possui, no máximo, dois filhos, um à direita e outro à esquerda. Cada nó é identificado por uma chave. Estas chaves são organizadas de forma que a chave de um nó seja maior do que todas as chaves presentes em sua subárvore esquerda e menor do que todas as chaves na sua subárvore direita.

O custo computacional envolvido na busca binária é $log(n + 1)$, ou seja, faz ao menos este número de comparações para inserir ou buscar na árvore binária. Porém, a medida que novos itens são inseridos na árvore, esta pode ficar desbalanceada, gerando um aumento na complexidade do processo de busca. Para tanto, existem algoritmos capazes de garantir o rebalanceamento da árvore enquanto são inseridos novos itens na árvore.

Os algoritmos de ordenação se aproveitam do custo da árvore binária. Nesses algoritmos, são utilizadas árvores de decisão, baseando-se em comparações binárias. Dado que a altura de uma árvore binária com $n!$ folhas é ao menos $log(n!)$, ao menos $log(n!)$ comparações são necessárias. Sabe-se que $log(n!)$ é equivalente a n $log(n)$, como comumente encontrado em funções de complexidade de algoritmos. Com isso, consegue-se alcançar um custo de $n\ log(n)$ ao ordenar-se uma lista.

As árvores binárias ainda podem ser utilizadas para comprimir textos. A ideia geral é que as letras com maior frequência no texto ocupem uma quantidade menor de espaço. Pode-se delimitar um caractere como uma sequência de bits ou terminada em zero ou com um limite máximo de bits. Um exemplo seria 0: e, 10: a, 110: t, 1110: n e 1111: s.

A codificação Huffman consiste em, dada a frequência de cada símbolo, juntar todos os símbolos de forma que os itens de maior frequência ocupem menos bits. Para tanto, cada item é uma árvore separada. As árvores de menor frequência são concatenadas, até que se sobre apenas uma única árvore. No final, os itens de maior frequência estarão ocupando menos espaço de armazenamento, gerando assim um texto mais compacto.

Por fim, as árvores ainda podem ser utilizadas para jogos, como o xadrez e o jogo da velha. Nestas árvores, os vértices são representados por quadrados nos níveis pares e por círculos nos níveis ímpares, representando de qual jogador é a vez. A partir disso, cria-se um caminho do jogo, onde cada vértice pode dar em um resultado final mostrado em uma de suas folhas. Geralmente é utilizado em jogos com jogadas finitas.

## Considerações
- Este programa lê uma coleção de arquivos contento textos sem nenhuma formatação onde cada sentença termina por um sinal de pontuação (`.`, `,`, `?`, `!`, `:`, `;`).
- Cada parágrafo é separado por, pelo menos, uma linha em branco.
- Foram consideradas como palavras qualquer sequência de letras delimitada por espaço em branco, ”coluna da esquerda”, ”coluna da direita” e símbolos de pontuação.
- Além dos sinais de pontuação e espaços em branco, será considerado, para separar as palavras, caracteres como `'`, `"`, `(`, `)`, `\`, `/`, `-` e `\n`.
- Será solicitado ao usuário um arquivo denominado `input.data`, contendo uma lista de palavras. Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema.
- Os arquivos de texto a serem utilizados para teste possuem formatação `input%d.data`, onde `%d` é o número do arquivo, que começa de `1` e vai até não encontrar mais nenhum arquivo.
- O tamanho _k_ de itens valiosos é 20.
- Os resultados da análise serão apresentados em um arquivo chamado `output.data`.

## Arquivos utilizados

- `main.cpp` é o ponto de entrada do programa, onde a sua execução começa.
- `utils.hpp` _header_ da biblioteca de utilidades, onde as definições das funções utilizadas para a construção do programa estão situadas, como a leitura dos arquivos de entrada.
- `utils.cpp` é onde o corpo das funções definidas no _header_ citado acima se encontram.
- `tree.h` _header_ da árvore binária básica
- `tree.c` é onde o corpo das funções definidas no _header_ citado acima se encontram.
- `avl.h` _header_ da árvore AVL
- `avl.c` é onde o corpo das funções definidas no _header_ citado acima se encontram.
- `huffman.h` _header_ da árvore de Huffman
- `huffman.c` é onde o corpo das funções definidas no _header_ citado acima se encontram.
- `record.hpp` é onde fica a definição da _struct_ de dados dos nós das árvores

## Decisões de implementação

Primeiramente, foi necessário abrir os arquivos de entrada para leitura. Para tanto, foi alocado um espaço na memória, em um ponteiro `buffer`, do tamanho da primeira entrada, para lê-lo. O tipo do ponteiro é `wchar_t *`, pois as entradas possuem codificação especial. Então, foi lida a entrada neste ponteiro, onde cada caractere foi analisado individualmente, para determinar se o caractere analisado é um separador de palavras. Quando o caractere não é uma separador de palavras, ele é concatenado ao final de uma _string_ temporária.

Caso o seja, o programa entenderá que a _string_ temporária é uma palavra completa, e o programa irá verificar se esta _string_ é uma _stop word_. Se a palavra não o for, ela é adicionada a um `unordered_map` do tipo `<std::wstring, unsigned short>`, onde o seu valor será incrementado em um.

Para armazenar as _stop words_, foi utilizado um `unordered_set`. Se a _string_ temporária estiver neste _set_, ela não é contabilizada. A utilização, tanto do `unordered_map`, quanto do `unordered_set`, foi escolhida devido ao custo constante de O(1) de pesquisa em situações ideias.

Assim que o programa lê todas as palavras do primeiro arquivo, o espaço alocado para o ponteiro do `buffer` é liberado, e então o programa tenta abrir a entrada `input2.data`. Caso não consiga abrir, o `buffer` receberá um `nullptr`, informando ao _loop_ que todas as palavras dos arquivos de entrada já foram lidos.

Logo, é criado um iterador que aponta para o início do _map_ que contém as palavras. Os vinte primeiros itens deste iterador são armazenados em um `vector`, e então é utilizada a função `make_heap` da biblioteca padrão do _C++_. Esta função faz um _min heap_ destes vinte primeiros itens, fazendo com que o item de menor valor seja o primeiro elemento do _heap_.

O iterador então continua verificando se o item atual possui maior valor que o primeiro item do _heap_; caso o seja, este primeiro item é substituído pelo item atual do iterador, e é feito então um novo `make_heap`, para garantir que o item de menor valor esteja na primeira posição. Isso continua até que o iterador chegue ao final do _map_.

Finalizado o _heap_, é criado um novo _heap_ temporário que receberá os dados do _heap_ original. Se a palavra estiver no _heap_, esta palavra é removida do _heap_, para a palavra $k + 1$ entrar em seu lugar. São criadas, a partir deste _heap_ temporário, as árvores binária, AVL e de Huffman, para então serem gravadas no arquivo `output.data`.

Serão passados, para o arquivo de saída `output.data`, os dados referentes aos nós das três árvores para cada palavra no arquivo `input.data`. Na árvore binária básica, são gravadas no arquivo apenas a palavra e a frequência de cada nó. Na árvore AVL, são gravados a palavra, a frequência e o peso de cada nó. Já na árvore Huffman, são gravados a palavra, a frequência e o código de Huffman gerado pelo algoritmo.

É importante destacar que utilizou-se a biblioteca padrão do _C++_ ao máximo, devido a sua alta performance e confiabilidade. Foi considerada a realização deste presente trabalho em _C_, porém, este encontraria maior propensão a error de acesso inválido de memória e uma função _hash_ que gerasse muitas colisões, tornando o programa mais lento.

## Árvore binária de busca

Conforme discorrido anteriormente, as árvores binárias possui utilização para as mais diversas finalidades. Nas árvores, pode-se efetuar operações de busca, mínimo, máximo, predecessor, sucessor, inserir e deletar. Pode-se ainda utilizar as árvores de busca como um dicionário ou uma fila de prioridades.

As operações nas árvores de busca binária levam um tempo $\Theta(\mathrm{lg}\ n)$. Porém, se a árvore possuir uma estrutura semelhante a uma lista simplesmente encadeada, pode levar um tempo $\Theta(n)$. Este caso ocorre quando se insere uma lista de itens ordenados, fazendo com que os itens conseguintes caminhem apenas para um lado.

Para tanto, existem opções para garantir que a árvore possua um tempo $\Theta(\mathrm{lg}\ n)$, como a árvore AVL ou a árvore rubro-negra. No decorrer dos próximos parágrafos, será discorrida apenas a árvore binária básica, onde não existe qualquer operação de rebalanceamento.

### Inserção

Nas árvores binárias básicas, a chave do item a ser inserido é comparado com a raiz; se o do item a ser inserido for menor que o da raiz, caminha-se para a direita e, caso seja maior, caminha-se para a esquerda. O algoritmo compara a chave do valor a ser inserido com cada nó da árvore, até que se chegue à uma das folhas.

Ao chegar a uma folha, o item é inserido no lugar de um nó _NIL_. Este nó seguira a mesma lógica de caminhamento descrita anteriormente, indo para a esquerda ou para a direita conforme a comparação do valor das chaves do nó atual de caminhamento e do item a ser inserido.

```
TREE-INSERT(T, z)
 1 y = NIL
 2 x = T.root
 3 while x != NIL
 4     y = x
 5     if z.key < x.key
 6         x = x.left
 7     else x = x.right
 8 z.p = y
 9 if y == NIL
10     T.root = z // tree T was empty
11 elseif z.key < y.key
12     y.left = z
13 else y.right = z
```

Para inserir um novo valor $v$ à árvore binária $T$, é necessário encontrar um nó $z$ onde $z.key = v$, $z.left = NIL$ e $z.right = NIL$. Com isso, modifica-se $T$ e alguns dos atributos de $z$ de forma que $z$ seja inserido na posição apropriada da árvore.

### Mínimo e máximo

Para determinar o elemento mínimo de uma árvore binária, é necessário somente caminhar para a direita até que se chegue ao nó mais à esquerda.

```
TREE-MINIMUM(x)
1 while x.left != NIL
2     x = x.left
3 return x
```

O pseudo-código para determinar o maior elemento da árvore é semelhante, visto que é necessário caminhar apenas para a direita, até que se encontre o último nó não nulo.

```
TREE-MAXIMUM(x)
1 while x.right != NIL
2     x = x.right
3 return x
```

### Remoção

A estratégia para remover um nó de uma árvore binária envolve três casos:

1. Se $z$ não possui filhos, então este simplesmente será removido substituindo o atributo do pai que aponta para $z$ por $NIL$.

1. Se $z$ tem apenas um filho, então este filho assume a posição de $z$.

1. Se $z$ possui dois filhos, então é necessário encontra o sucessor $y$, que estará na subárvore direita de $z$, para que $y$ possa então tomar o lugar de $z$. A ex-subárvore direita de $z$ se torna a nova subárvore direita de $y$.

The procedure for deleting a given node ´ from a binary search tree T takes as arguments pointers to T and ´. It organizes its cases a bit differently from the three cases outlined previously by considering the four cases shown in Figure 12.4.

- Se $z$ não tiver filho esquerdo, então substituímos $z$ por seu filho direito, que pode ou não ser $NIL$. Quando o filho certo de $z$ é $NIL$, este caso trata da situação em que $z$ não tem filhos. Quando o filho certo de $z$ não é $NIL$, este caso trata da situação em que $z$ tem apenas um filho, que é seu filho certo

- Se $z$ tiver apenas um filho, que é o filho esquerdo, então substituímos $z$ pelo filho esquerdo.

- Caso contrário, $z$ tem um filho esquerdo e um filho direito. Encontramos o sucessor de $z$, $y$, que está na subárvore direita de $z$ e não tem filho esquerdo (ver Exercício 12.2-5). Queremos separar $y$ de sua localização atual e substituí-lo $z$ na árvore.

  - Se $y$ é o filho direito de $z$, então substituímos $z$ por $y$, deixando o filho direito de $y$ sozinho.

  - Caso contrário, $y$ está na subárvore direita de $z$, mas não é filho direito de $z$. Neste caso, primeiro substituímos $y$ pelo seu filho direito e depois substituímos $z$ por $y$.

A fim de mover subárvores de árvores binárias, é necessário definir uma função denominada _TRANSPLANT_, que substitui uma subárvore como filha de seu pai por outra subárvore. Quando TRANSPLANT substitui a subárvore enraizada no nó $u$ por a subárvore com raiz em nó, o pai do nó $u$ torna-se o pai do nó $v$ e o pai de $u$ o pai acaba tendo $v$ como filho apropriado.

```
TRANSPLANT(T,u,v)
1 if u.p == NIL
2     T.root = v
3 elseif u == u.p.left
4     u.p.left = v
5 else u.p.right = v
6 if v != NIL
7     v.p = u.p
```

Definida a função _TRANSPLANT_, é possível implemetar a função de remoção de um nó da árvore. O pseudo-código abaixo demonstra o procedimento da remoção do nó $z$ da árvore binária $T$.

```
TREE-DELETE(T,z)
 1 if z:left == NIL
 2     TRANSPLANT(T,z,z.right)
 3 elseif z.right == NIL
 4     TRANSPLANT(T,z,z.left)
 5 else y = TREE-MINIMUM(z.right)
 6     if y.p != z
 7         TRANSPLANT(T,y,y.right)
 8         y.right = z.right
 9         y.right.p = y
10     TRANSPLANT(T,z,y)
11     y.left =z.left
12     y.left.p = y
```

- Linhas 1–2: tratam do caso em que o nó $z$ não tem filho esquerdo, e as linhas 3–4 tratam do caso em que $z$ tem um filho esquerdo, mas nenhum filho direito.

- Linhas 5–12: tratam dos dois casos restantes, nos quais $z$ tem dois filhos.

A linha 5 encontra o nó $y$, que é o sucessor de $z$. Como $z$ tem uma subárvore direita não vazia, seu sucessor deve ser o nó dessa subárvore com a menor chave; daí a chamada para TREE-MINIMUM(z.right). Como observamos antes, $y$ não tem filho esquerdo. Queremos separar $y$ de sua localização atual e ele deve substituir $z$ na árvore. Se $y$ for o filho direito de $z$, então as linhas 10–12 substituem $z$ como filho de seu pai por $y$ e substituem o filho esquerdo de $y$ pelo filho esquerdo de $z$. Se $y$ não for o filho esquerdo de $z$, as linhas 7–9 substituem $y$ como filho de seu pai pelo filho direito de $y$ e transformam o filho direito de $z$ em $y$' s filho direito e, em seguida, as linhas 10–12 substituem $z$ como filho de seu pai por $y$ e substituem o filho esquerdo de $y$ pelo filho esquerdo de $z$.

### Busca

O algoritmo de busca é semelhante, de modo que este também busca itens baseando-se na mesma comparação para determinar se o caminhamento caminhamento será realizado para a esquerda ou para a direita.

```
TREE-SEARCH(x,k)
1 if x == NIL or k == x.key
2     return x
3 if k < x.key
4     return TREE-SEARCH(x.left, k)
5 else return TREE-SEARCH(x.right, k)
```

### Caminhamento _preorder_, _inorder_ e _posorder_

Para imprimir os itens das árvores em ordem crescente, podem ser utilizados os métodos _preorder_, _inorder_ e _posorder_.

O algoritmo de _preorder_ imprime o nó atual antes de imprimir os filhos, e assim por diante.

```
PREORDER-TREE-WALK(x)
1 if x != NIL
2     print x.key
3     PREORDER-TREE-WALK(x.left)
4     PREORDER-TREE-WALK(x.right)
```

O método _inorder_ busca, recursivamente, os valores mais a esquerda, ou seja, os de menor valor, para então os imprimir na tela e, em seguida, buscar os valores mais a direita.

```
INORDER-TREE-WALK(x)
1 if x != NIL
2     INORDER-TREE-WALK(x.left)
3     print x.key
4     INORDER-TREE-WALK(x.right)
```

Já o _posorder_ busca as folhas para depois então desempilar a recursão e imprimir os pais. Os pseudo-códigos a seguir demonstram a implementação destes algoritmos:

```
POSORDER-TREE-WALK(x)
1 if x != NIL
2     POSORDER-TREE-WALK(x.left)
4     POSORDER-TREE-WALK(x.right)
3     print x.key
```

Com isso, é possivel imprimir todos os nós de uma árvore. O método _inorder_ seria o mais preferível de um ponto de vista de ordenação, visto que este imprime os nós em ordem crescente das chaves.

## Árvore AVL

As árvores binárias de busca apresentam uma desvantagem significativa que pode impactar seu desempenho. Essa desvantagem está intimamente relacionada com a natureza do conjunto de dados e como ele é inserido na árvore.

Em uma árvore de binária básica, o número esperado de comparações para encontrar um registro é aproximadamente $1,39\ log(n)$, o que é cerca de 39% pior do que uma árvore completamente balanceada.

Essa diferença no desempenho ocorre devido à natureza aleatória das inserções em uma árvore de pesquisa binária aleatória, que pode acabar resultando em árvores desequilibradas em comparação com árvores balanceadas, onde cada nó é inserido de forma estratégica para manter o equilíbrio.

Isso significa que, em média, seria necessário realizar mais comparações em uma árvore de pesquisa binária básica para encontrar um registro específico em comparação com uma árvore completamente balanceada.

A fim de melhorar seu comportamento, é necessário aplicar um conceito conhecido como balanceamento da árvore. Uma generalização dessa ideia é a árvore AVL (Adelson-Velsky e Landis). Com a árvore AVL, é possível garantir que as consultas, inserções e remoções apresentarão custo em $O(log\ n)$.

O objetivo fundamental da árvore AVL é manter as subárvores esquerda e direita com alturas aproximadamente iguais. Isso permite garantir que a altura da árvore seja limitada por logaritmo na base 2 do número de nós $log(n)$.

Para assegurar esse equilíbrio, a AVL calcula o desequilíbrio com base na profundidade do nó mais distante de cada subárvore. Se esse desequilíbrio atingir um valor maior ou igual a 2, a árvore é reequilibrada por meio de operações de rotação. As rotações podem ser divididas em 4 configurações:

- Rotação simples à esquerda;

```
Rotação simples à esquerda
input : t → root of the Tree
output: Balanced Tree

aux = t.right;
t.right = aux.left;
aux.left = t;
t.peso = MaxWeight(getWeight(raizˆ .esquerdo), getWeight(raizˆ .direito)) + 1;
aux.peso := MaxWeight(getWeight(auxˆ .direito), raizˆ .peso) + 1;
raiz = aux;
```

- Rotação simples à direita;

```
Rotação simples à direita
input : t → root of the Tree
output: Balanced Tree

aux = t.left;
t.left = aux.right;
aux.right = t;
t.peso = MaxWeight(getWeight(t.left), getWeight(t.right)) + 1;
aux.peso = MaxWeight(getWeight(aux.left), t.peso) + 1;
t = aux;
```

- Rotação dupla à esquerda;

```
Rotação dupla esquerda / direita
input : t → root of the Tree
output: Balanced Tree

rotacaoSimplesEsquerda(t.left);
rotacaoSimplesDireita(t);
```

- Rotação dupla à direira.

```
Rotação dupla direita / esquerda
input : t → root of the Tree
output: Balanced Tree

rotacaoSimplesDireita(t.right);
rotacaoSimplesEsquerda(t);
```

O peso de uma árvore AVL indica o equilíbrio da árvore. Em uma árvore AVL, o peso de um nó é a diferença entre a altura da subárvore direita e a altura da subárvore esquerda desse nó. O equilíbrio de uma árvore AVL é mantido garantindo que o peso de todos os nós da árvore seja menor que 2. Se o peso de qualquer nó ultrapassar esse limite, a árvore estará desequilibrada e um rebalanceamento será realizado por meio de rotações.

```
Método para obter o peso
input : t → root of the Tree
output: Weight of the node

if(t == NULL):
    WEIGHT = -1
else:
    WEIGHT = t.weight;
```

```
Método para obter o peso máximo
input : leftw,rightw → weight of left and right child
output: Max Weight

if (leftw > rightw):
    maxWeight = leftw
else:
    maxWeight = rightw
```

Abaixo é apresentado o pseudo-código da inserção em uma árvore AVL:

```
Método de inserção
input : t → root of the tree
input : item → new item
output: Tree with the new item inserted

if (t == NULL):
    new(t);
    t.item = item;
    t.weight = 0;
    t.left := NULL;
    t.right = NULL;
else if (item.key < t.item.key):
    inserir(item, t.left);
    if ((getWeight(t.left) - getWeight(t.right)) = 2):
    if (item.key < t.left.item.key):
        rotacaoSimplesDireita(t)
    else
        rotacaoDuplaEsquerdaDireita(t);
  else if (item.key > t.item.key):
    inserir(item, t.right);
    if ((getWeight(t.right) - getWeight(t.left)) = 2):
        if (item.key > t.right.item.key):
            rotacaoSimplesEsquerda(t)
        else
            rotacaoDuplaDireitaEsquerda(t);
t.weight := MaxWeight(getWeight(t.left), getWeight(t.right)) + 1;
```

É importante observar que a inserção em uma árvore AVL pode exigir uma ou mais rotações para manter o equilíbrio. A complexidade da inserção em uma árvore AVL é $O(log n)$, devido ao número limitado de rotações necessárias para manter o equilíbrio da árvore. Isso garante um desempenho eficiente para operações de inserção, remoção e busca em árvores AVL.

## Codificação de Huffman

A codificação de Huffman é um algoritmo guloso que tem por objetivo comprimir dados, diminuindo o tamanho destes dados de 20% a 90%, dependendo das características dos mesmos. Dada uma cadeia de caracteres, a codificação de Huffman utiliza uma tabela da frequência de cada caractere, a fim de construir uma árvore a utilizando a frequência como chave.

Primeiramente, é implementada uma fila de prioridades crescente, onde os itens de menor frequência ficam nas primeiras posições. Cada item nesta fila é uma árvore, a cada iteração, as duas árvores de menor frequência (as duas primeiras da fila) são mescladas, gerando assim uma nova árvore onde o filho esquerdo é o primeiro item da fila, o filho direito é o segundo elemento da fila e o pai possui como frequência a soma da frequência destas duas árvores. A fila de prioridade então exclui os dois primeiros itens e adiciona a nova árvore mesclada à fila.

O algoritmo continua mesclando as árvores até que sobre apenas uma única árvore, que é a árvore que contém a codificação de Huffman. Segue abaixo o pseudo-código da implementação da árvore de Huffman:

```
HUFFMAN(C)
1 n = |C|
2 Q = C
3 for i = 1 to n - 1
4     allocate a new node z
5     z.left = x D EXTRACT-MIN(Q)
6     z.right = y = EXTRACT-MIN(Q)
7     z.freq = x.freq + y.freq
8     INSERT(Q.z)
9 return EXTRACT-MIN(Q) // return the root of the tree
```

Supondo que $C$ seja um conjunto de $n$ caracteres e cada caractere $c \in C$ possui um atributo $c.freq$ representando sua frequência, o algoritmo constrói a árvode de baixo para cima.

Cada folha do conjunto $\left\lvert C \right\lvert$ é mesclada até construir a árvore final, utilizando uma fila de prioridades. Quando dois objetos são mesclados, o resultado é um novo objeto em que a frequência é a soma das frequências dos dois objetos mesclados.

Na implementação deste trabalho, foi utilizado, no lugar de caracteres, palavras e sua frequência no texto. Esta implementação possui uma lógica semelhante, que se difere por pegar o _heap_ com as _K_ palavras mais frequêntes e jogando-as em uma fila prioritária, para então construir a árvore de Huffman.

Montada a árvore de Huffman, realiza-se a codificação das palavras, representadas pelas folhas da árvore. Cada vez que o algoritmo teve que andar para a esquerda acrescenta-se um 0 ao código, enquanto o caminhmento à direita gera um 1. Por fim, tem-se como resultado a codificação de Huffman das palavras, gerando assim um código mais curto para palavras mais frequentes e um código mais longo para palavras mais longas.

## Casos sem tratamento

O algoritmo reconhece como fazendo parte de uma palavra qualquer caractere que não seja os já citados anteriormente. Com isso, é possível que caracteres especiais façam parte de uma palavra, fazendo com que algo que não poderia ser considerado como palavra o seja, o que é algo indesejado. Uma possível solução para este problema seria acrescentá-los à _string_ constante que define os caracteres a não serem lidos. Outra solução seria colocar estes caracteres, caso formem uma palavra por si só, na lista de _stop words_.

Para verificar se uma palavra do arquivo `input.data` está contida nos arquivos, o programa busca apenas as palavras presentes no `map`. Com isso, as _stop words_ serão consideradas como não presentes no texto. Outro caso que pode acontecer é uma palavra que foi dividida durante a separação das palavras presentes no texto. Isso faz com que uma palavra possa não ser reconhecida, mesmo estando presente nos textos, pois o programa a interpretou de uma outra maneira.

## Exemplo

Foi realizado um teste com um arquivo de palavras `input.data`, um arquivo de _stop words_ `stopwords.txt` e dois textos `inputa1.data` e `input2.data`, a fim de demonstrar a saída após a execução do programa, conforme mostrado abaixo.

`input.data`

```
segundo
social
heap
```

`input1.data`

```
Caros amigos, a infinita diversidade da realidade única nos obriga à análise do demônio de Laplace. Por outro lado, a complexidade dos estudos efetuados cumpre um papel essencial na formulação da fundamentação metafísica das representações. Assim mesmo, a forma geral da proposição significativa deverá confirmar as consequências decorrentes do sistema de conhecimento geral.

Neste sentido, o novo modelo estruturalista aqui preconizado auxilia a preparação e a composição das posturas dos filósofos divergentes com relação às atribuições conceituais. Baseando-se nos ensinamentos de Dewey, a canalizaçao do Ser do Ente garante a contribuição de um grupo importante na determinação das novas teorias propostas. A prática cotidiana prova que a consolidação das estruturas psico-lógicas não sistematiza essa relação, de tal modo que a pulsão funciona funciona como significado da determinação do Ser enquanto Ser.

Nunca é demais lembrar o peso e o significado destes problemas, uma vez que o conceito de diáthesis e os princípios fundamentais de rhytmos e arrythmiston facilita a criação do sistema de formação de quadros que corresponde às necessidades lógico-estruturais. Como Deleuze eloquentemente mostrou, o início da atividade geral de formação de conceitos obstaculiza a apreciação da importância dos paradigmas filosóficos. Acabei de provar que o desafiador cenário globalizado não oferece uma interessante oportunidade para verificação dos relacionamentos verticais entre as hierarquias conceituais. Se estivesse vivo, Foucault diria que o Übermensch de Nietzsche, ou seja, o Super-Homem, acarreta um processo de reformulação e modernização da substancialidade e causalidade entendidos como certezas fundamentais. Pretendo demonstrar que a expansão dos mercados mundiais pode nos levar a considerar a reestruturação das ciências discursivas.

[...]
```

`input2.data`

```
Deve-se produzir um conceito que a consolidação das estruturas psico-lógicas tem que apresentar uma homogenidade em relação aos extremos das condições epistemológicas e cognitivas exigidas. Evidentemente, a complexidade dos estudos efetuados cumpre um papel essencial na formulação da fundamentação metafísica das representações. Assim mesmo, a universalidade eidética do puro-devir possibilita o ato de intenção consciente do sistema de conhecimento geral.

No entanto, não podemos esquecer que o novo modelo estruturalista aqui preconizado auxilia a preparação e a composição da sensibilia dos não-sentidos. Do mesmo modo, a indeterminação contínua de distintas formas de fenômeno desafia a capacidade de equalização das novas teorias propostas. Prospectos designam, de início, a infinita diversidade da realidade única talvez venha a ressaltar a relatividade do movimento in loco da desterritorialização indiscernível. Nunca é demais lembrar o peso e o significado destes problemas, uma vez que o conceito de diáthesis e os princípios fundamentais de rhytmos e arrythmiston facilita a criação do sistema de formação de quadros que corresponde às necessidades lógico-estruturais.

Contudo, a crítica contundente de Deleuze/Guatarri - dupla implacável - nos mostra que o início da atividade geral de formação de conceitos obstaculiza a apreciação da importância dos paradigmas filosóficos. Acabei de provar que o desafiador cenário globalizado não oferece uma interessante oportunidade para verificação dos relacionamentos verticais entre as hierarquias conceituais. Se estivesse vivo, Foucault diria que o Übermensch de Nietzsche, ou seja, o Super-Homem, acarreta um processo de reformulação e modernização do processo de comunicação como um todo. Em primeiro lugar, a expansão dos mercados mundiais pode nos levar a considerar a reestruturação da incompatibilidade do próprio pensamento de Hegel e Foucault.

[...]
```

Após a análise das duas entradas, o _heap_ ficou da seguinte forma:

```
~~~> Original heap <~~~

princípio: 188
maneira: 190
É: 191
wittgenstein: 190
sentido: 221
sistema: 234
sobre: 228
vista: 191
social: 213
condição: 267
pode: 229
modo: 258
teoria: 368
sujeito: 294
priori: 269
deve: 229
pensamento: 230
segundo: 228
imanente: 213
mundo: 278
```

Foram inseridas, no arquivo `input.data`, três palavras; uma presente no _heap_, uma que não está presente n _heap_, mas está nos textos e uma que não existe nos textos. Com isso, será possível verificar os três casos de saída das palavras. A primeira palavra, presente no _heap_, é a palavra "segundo". O seu heap ficou da seguinte forma:

```
~~~> Heap of "segundo" word <~~~

quanto: 180
princípio: 188
É: 191
wittgenstein: 190
maneira: 190
sistema: 234
sobre: 228
vista: 191
imanente: 213
sentido: 221
pode: 229
modo: 258
teoria: 368
sujeito: 294
priori: 269
deve: 229
pensamento: 230
social: 213
mundo: 278
condição: 267
```

É possível perceber que a palavra "segundo" foi retirada do _heap_, para dar lugar à palavra $k + 1$ "quanto". Para a segunda palavra, "conceito", o _heap_ ficou inalterado:

```
~~~> Heap of "conceito" word <~~~

princípio: 188
maneira: 190
É: 191
wittgenstein: 190
sentido: 221
sistema: 234
sobre: 228
vista: 191
social: 213
condição: 267
pode: 229
modo: 258
teoria: 368
sujeito: 294
priori: 269
deve: 229
pensamento: 230
segundo: 228
imanente: 213
mundo: 278
```

E, por fim, a terceira palavra, "heap", que não estava presente nos textos, ofereceu a seguinte saída no terminal:

```
~~~> The "heap" word isn't present on the texts <~~~
```

Devido ao fato de que a saíd _inorder_ é ordenada crescentemente, optou-se por demonstrá-la nos exemplos a seguir. É importante destacar que apenas as árvores binária básica e AVL terão saída crescente, pois a árvore Huffman não mantém as menores sempre à esquerda e os menores à direta. Serão mostrados os exemplos para as três árvores apenas para a palavra "segundo", pois para qualquer palavra as saídas seram semelhantes, exceto pela eventual adição da palavra $k + 1$.

`Basic tree`

```
quanto: 180
maneira: 190
wittgenstein: 190
social: 213
sentido: 221
imanente: 213
vista: 191
pensamento: 230
deve: 229
pode: 229
sobre: 228
condição: 267
mundo: 278
priori: 269
sujeito: 294
teoria: 368
modo: 258
sistema: 234
É: 191
princípio: 188
```

`AVL tree`

```
quanto : 180 : 0
princípio : 188 : 1
wittgenstein : 190 : 0
maneira : 190 : 2
É : 191 : 0
vista : 191 : 1
imanente : 213 : 4
social : 213 : 0
sentido : 221 : 1
sobre : 228 : 2
pode : 229 : 0
deve : 229 : 1
pensamento : 230 : 0
sistema : 234 : 3
modo : 258 : 1
condição : 267 : 0
priori : 269 : 2
mundo : 278 : 0
sujeito : 294 : 1
teoria : 368 : 0
```

`Huffman tree`

```
sentido : 221 : 0000
sobre : 228 : 0001
pode : 229 : 0010
deve : 229 : 0011
pensamento : 230 : 0100
sistema : 234 : 0101
modo : 258 : 0110
condição : 267 : 0111
priori : 269 : 1000
mundo : 278 : 1001
sujeito : 294 : 1010
teoria : 368 : 1011
quanto : 180 : 11000
princípio : 188 : 11001
maneira : 190 : 11010
wittgenstein : 190 : 11011
É : 191 : 11100
vista : 191 : 11101
imanente : 213 : 11110
social : 213 : 11111
```
Na árvore Huffman, o código das palavras variara de 4 a 5 bits. Isso ocorreu devido ao fato de que elas possuem uma frequência próxima, fazendo com a árvore mesclada fique com quase o dobro da frequência da palavra de maior frequência. Com isso, a árvore mesclada vai ao final da fila de prioridade, e as folhas da árvore final ficam aproximadamente no mesmo nível.

O exemplo aqui exposto foi compilado com o GNU Compiler Collection (gcc) versão 4:10.2.1-1, no sistema operacional Debian 11 (Bullseye). O computador possuia uma placa-mãe ASUS AM1M-A/BR, 8 GB de memória RAM DDR3 e um processador AMD Athlon 5150 (arquitetura x86_64).

## Conclusão

Pode-se afirmar que a código cumpriu com o que foi proposto na atividade, criando um contador de palavras que armazena as palavras que mais aparecem nos textos de entrada em um _max heap_, para posteriormente realizar a construção das árvores binária simples, AVL e de Huffman com base na frequência destas palavras. A execução do programa ocorreu conforme esperado, como foi possível verificar no exemplo citado.

Dessa forma, é possível afirmar que a utilização da estratégia de construir árvores baseadas na frequência de cada palavra constitui um ótimo custo de $log(n)$, fazendo com que a sua busca e alteração seja rápida. Conforme visto, a árvore binária pode se desbalancear com a inserção de novos elementos, implicando negativamente no custo de busca. Para tanto, descreveu-se algoritmos para balanceá-las conforme novos itens são inseridos na árvore.

Ainda existem alguns pontos de possível melhora no programa, como a verificação das exceções vistas nos casos sem tratamento. Portanto, uma revisão do programa o tornaria ainda melhor, pois, nestas atuais condições, o usuário poderá comprometer a execução do programa, dependendo do que este colocar como entrada.

## Compilação e Execução

O algoritmo do labirinto decorrente disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


## Contato

<a style="color:black" href="mailto:rafaelg000@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
    ✉️ <i>rafaelg000@gmail.com</i>
</a>
