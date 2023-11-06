## Como utilizar:
- Tenha instalado o g++ para compilação e o make para utilizar Makefile, no caso do windows ambos pode ser baixados facilmente utilizado o gerenciador de pacotes chocolatey.

## Executar individualmente com Makefile
Para executar individualmente cada um dos códigos basta usar os comandos respectivos:
- centralPivot: `make run_central`
- medianPivot: `make run_median`
- randomPivot: `make run_random`

## Executar tudo
Para executar todos os codigos, para todos os conjuntos com apenas um comando basta utilizar `make run_all`

## Executar individualmente com g++
Para executar individualmente cada um dos códigos basta estar na pasta root do projeto (paa-quicksort), e executar os seguintes comandos:

### Para compilar
- `g++ -o ./centralPivot/quickSort.exe ./centralPivot/quickSort.cpp`
- `g++ -o ./medianPivot/quickSort.exe ./medianPivot/quickSort.cpp`
- `g++ -o ./randomPivot/quickSort.exe ./randomPivot/quickSort.cpp`

### Para executar
- `./centralPivot/quickSort.exe`
- `./medianPivot/quickSort.exe`
- `./randomPivot/quickSort.exe`

## Numero de Testes
Por Default o numero de testes utilizado é de 32 testes para cada conjunto, isso pode ser alterado, na variavel `numTests` presente nas respectivas linhas dos codigos:
- centralPivot: line 102
- medianPivot: line 118
- randomPivot: line 104

## Observacoes
O caso base `if (start >= end) return;` possui custo 2.

`int p = partition(arr, start, end);` Possui custo 1 da atribuicao + Custo total de Partition (funcao que escolhe o Pivot e particiona o vetor). Custo total generico para partition = 15n + 29 (?)

O que varia no custo dessa parte do algortimo é a funcao de selecao de pivot, que possui custos diferentes em cada caso:
- centralPivot: 6
- median: 29
- random: 6

Porem note que o custo é constante, portanto nao ira influenciar no custo assintotico.

Nos algoritmos random e median que se utilizam de valores randomicos para selecionar o elemento pivo, podemos notar uma leve variacao na quantidade de swaps realizados, porem isso so se tem visivel em conjuntos de N muito grandes, nao sendo praticamente perceptivel ou fazendo tanta diferenca para conjuntos menores.
