/*

    AV 20210119

    Desafio muxi:
 

    > 6. Implemente a seguinte função

        err_t findCommon( int *list1
                            , int numElem1
                            , int *list2
                            , int numElem2
                            , int *result
                            , int resultSize
                        );

    Onde o array result deve conter os elementos 
    comuns entre os arrays list1 e list2. E também 
    deve ser definido o tipo err_t.

    pwd:  *** alterar no fim ***
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/poc/desafio6

    compilacao: *** alterar no fim ***
    gcc interseccao.c -o interseccao

    Execucao: 
    ./interseccao 

*/


#include <stdio.h>
#include <stdlib.h>


typedef int err_t;


#define Tamanho 10
#define zero 0



err_t findCommon( int * list1, int numElem1, int * list2, int numElem2, int * result, int resultSize ) {
    
    int xResult = 0;

    err_t retorno = 0;


    for (int x = zero; x < Tamanho; x++) {

        printf( "\n:: findCommon :: list1[%d] = %d :: list2[%d] = %d ", x, list1[x], x, list2[x] );
    }
    
    for ( int x1 = zero; x1 < Tamanho; x1++ ) {

        for ( int x2 = zero; x2 < Tamanho; x2++ ) {

            if( list1[x1] == list2[x2] ) {

                result[ xResult ] = list1[x1];

                xResult++ ;
            }
        }
    }


    return( retorno );                    
}

void popularArray( int * list1, int * list2 ) {

    int x = zero;

    for ( x = zero; x < Tamanho; x++ ) {

        list1[x] = x;
        list2[x] = x *3;
    } 
}





int main() {

    system( "clear" );
    printf( "\n :: main() :: ");

    int x = zero;

    int * list1 = malloc(sizeof(int) * Tamanho);
    int numElem1 = Tamanho;

    int * list2 = malloc(sizeof(int) * Tamanho);
    int numElem2 = Tamanho;

    int * result = malloc(sizeof(int) * Tamanho);
    int resultSize = Tamanho;
    
    popularArray( list1, list2 );


    err_t erro = findCommon( list1, numElem1, list2, numElem2, result, resultSize );     


    printf( "\n:: Conjunto Intersecção ::" );
    
    for (x = zero; x < Tamanho; x++) {

        if ( result[x] != 0 ) {

            printf( "\n:: result[%d] = %d ::", x, result[x] );
        }
    }
    

    free(list1);
    free(list2);
    free(result);

    printf( "\n :: Fim :: ");

    return(0);
}

