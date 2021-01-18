
# Preliminar
Desafio Técnico:
Desafio Técnico remoto - Plataforma POSWEB
para vaga de desenvolvedor na Muxi/Conductor

Dicas para a entrevista presencial e para o desafio técnico:

Durante a entrevista técnica as perguntas de codificação podem envolver estruturas de dados, algoritmos de ordenação e algoritmos de busca. 
É fundamental conhecimento da linguagem C. Após a resolução de cada problema pode ser pedido para encontrar a complexidade assintótica dos algoritmos implementados.
Seguem as questões a serem resolvidas, as respostas devem ser enviadas por e-mail. As perguntas que serão feitas durante a entrevista técnica exigem os mesmos conhecimentos. 

	



### Desafio 

> pwd: /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio


> 1. Escreva usando a linguagem C uma função para inverter uma string.



> 2. Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em cada célula, escreva um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9 somente uma vez).

        5 3 4 | 6 7 8 | 9 1 2
        6 7 2 | 1 9 5 | 3 4 8
        1 9 8 | 3 4 2 | 5 6 7

        8 5 9 | 7 6 1 | 4 2 3
        4 2 6 | 8 5 3 | 7 9 1
        7 1 3 | 9 2 4 | 8 5 6

        9 6 1 | 5 3 7 | 2 8 4
        2 8 7 | 4 1 9 | 6 3 5
        3 4 5 | 2 8 6 | 1 7 9



> 3. Escreva uma função que dada uma string composta por substrings separadas por um dado caractere, retorne todas as suas substrings da string original. Por exemplo, dado o separador ‘/’, a string “/Fla/Flu/Bota/” será decomposta em:
        • Fla
        • Flu
        • Bota

O protótipo da função é o seguinte: 

char** stringSplit (const char *text, char separator, int *length);



> 4. Considere a existência de um tipo abstrato cuja interface é definida da seguinte forma:

typedef struct stack Stack;
Stack *stackNew (void);
void stackFree (Stack *p);
void stackPush (Stack *p, int elem);
int stackPop (Stack *p);
int stackEmpty (Stack *p);

Escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
função deve obedecer ao seguinte protótipo:
void stackRemoveEven (Stack *p);



> 5. Implemente a seguinte função:

void listPartition(SingleLinkedListOfIntsNode **head, int x);

Onde head é o início de uma lista de inteiros com encadeamento simples que deve ser particionada de forma que todos os valores menores do que x apareçam antes dos valores maiores do que x.



> 6. Implemente a seguinte função

err_t findCommon(int *list1, int numElem1, int *list2, int numElem2,
                 int *result, int resultSize);

Onde o array result deve conter os elementos comuns entre os arrays list1 e list2. E também deve ser definido o tipo err_t.





### R.F.:

> Buscas sempre usando DDD
	. tipo
	. operadora
	. plano




### O que usei:

> Editor: vsCode

> Repositório: GitHub

> Versionador: Git







#### Requirements

- Compilador Gcc





#### Executando 

> Compilar
- gcc poc1.c -o poc1  

> Executar
- ./poc1

> Saída
- hello world %

- 



## Obrigado
 
[Antal Varga](asvarga@gmail.com) 

