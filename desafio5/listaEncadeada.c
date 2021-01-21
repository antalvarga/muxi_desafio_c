/*

    AV 20210119

    Desafio muxi:
 

    > 5. Implemente a seguinte função

    void listPartition(SingleLinkedListOfIntsNode **head, int x);

    Onde head é o início de uma lista de inteiros com encadeamento 
    simples que deve ser particionada de forma que todos os valores 
    menores do que x apareçam antes dos valores maiores do que x.




    pwd:  
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio5

    compilacao: 
    gcc listaEncadeada.c -o lista

    Execucao: 
    ./lista

*/


#include <stdio.h>
#include <stdlib.h>

#define Tamanho 10
#define zero 0



typedef struct no SingleLinkedListOfIntsNode;

struct no {

    int num;
    struct no * proximo;

};



SingleLinkedListOfIntsNode * criarNo() {

    SingleLinkedListOfIntsNode * novoNo = ( SingleLinkedListOfIntsNode *)malloc( sizeof( SingleLinkedListOfIntsNode) );

    return( novoNo );
}

SingleLinkedListOfIntsNode * inserirNo( SingleLinkedListOfIntsNode * lista, int dadoNo ) {

    SingleLinkedListOfIntsNode * novoNo = criarNo();

    novoNo->num = dadoNo;

    if ( ! lista ) {

        lista = novoNo;

        novoNo->proximo = NULL;

    } else {

        novoNo->proximo = lista;

        lista = novoNo;
    }

    return( lista );

}

SingleLinkedListOfIntsNode * popularLista( SingleLinkedListOfIntsNode * lista ) {

    for ( int x = zero; x < Tamanho; x++ ) {

        lista = inserirNo( lista, x );
    }

    return( lista );
}

void listPartition( SingleLinkedListOfIntsNode ** head, int x) {

    printf( "\n :: listPartition ::" );

    SingleLinkedListOfIntsNode * auxiliar1 = * head;
    SingleLinkedListOfIntsNode * auxiliar2 = auxiliar1;

    while ( auxiliar1 ) {

        if ( auxiliar1->num < x ) {
            printf( "\n :: item -> %d :: ", auxiliar1->num );
        }

        auxiliar1 = auxiliar1->proximo;
    }

    printf( "\n");
    printf( "\n :: X -> %d :: ", x);
    printf( "\n");

    while ( auxiliar2 ) {

        if ( auxiliar2->num > x ) {
            printf( "\n :: item -> %d :: ", auxiliar2->num );
        }

        auxiliar2 = auxiliar2->proximo;
    }

}






int main () { 

    system("clear");

    SingleLinkedListOfIntsNode * lista = NULL;

    lista = popularLista( lista );

    listPartition( &lista, 7 );

    return(0);
}