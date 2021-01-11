/*

    AV 20210109
    Desafio muxi:

    Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em cada célula, 
    escreva um programa que verifique se esta matriz é uma solução válida para o 
    Sudoku (isto é, uma solução é válida no Sudoku se cada linha, cada coluna  e 
    cada bloco contém os números de 1 a 9 somente uma vez).

    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio2

    compilacao:
    gcc matriz.c -o matriz

    Execucao: 
    ./matriz 

*/
#include <stdio.h>
#include <stdlib.h>

#define totalLinhas 9
#define numeroInicio 0
#define totalColunas 9
#define totalQuadrante 3





// Avalia x1 e x2 se existem valores repetidos na mesma linha Y
int varrerLinhas( int matriz[totalLinhas][totalColunas], int * repetidos ) {

    int y, x1, x2;

    int retorno = 1;

    // Linha Y - Interrompe o processamento com && retorno
    // for ( y = numeroInicio; y < totalLinhas && retorno; y++) {
    for ( y = numeroInicio; y < totalLinhas; y++) {

        // Coluna x1
        for ( x1 = numeroInicio; x1 < totalLinhas; x1++) {

            // Coluna x2
            for ( x2 = numeroInicio; x2 < totalLinhas; x2++) {

                if ( (matriz[y][x1] == matriz[y][x2]) && (x1 != x2 ) ) {

                    retorno = 0;

                    repetidos[ matriz[y][x1] ]++ ;

                }
            }
        }        
    }

    return (retorno);
}


// Avalia y1 e y2 se existem valores repetidos na mesma coluna x
int varrerColunas( int matriz[totalLinhas][totalColunas], int * repetidos ) {

    int x, y1, y2;

    int retorno = 1;

    // Coluna x - Interrompe o processamento com && retorno
    // for ( x = numeroInicio; x < totalColunas && retorno; y++) {
    for ( x = numeroInicio; x < totalColunas; x++) {    

        // LINHA 1
        for ( y1 = numeroInicio; y1 < totalLinhas; y1++) {

            // Coluna x2
            for ( y2 = numeroInicio; y2 < totalLinhas; y2++) {

                if ( (matriz[y1][x] == matriz[y2][x]) && (y1 != y2 ) ) {

                    retorno = 0;

                    repetidos[ matriz[y1][x] ]++ ;

                }
            }
        }        
    }

    return (retorno);
}


int varrerQuadrante( int quadrante[totalQuadrante][totalQuadrante], int * repetidos ) {

    int x, y;
    
    int nPesquisar, nExiste;

    int retorno = 1;

    // Avaliar de 1 a 9 no quadrante
    for ( nPesquisar = numeroInicio; nPesquisar < totalColunas; nPesquisar++ ) {

        // Avaliar as linhas
        for (y = numeroInicio; y < totalQuadrante; y++) {

            // Avaliar colunas
            for ( x = numeroInicio; x < totalQuadrante; x++) {
                
                if ( quadrante[y][x] == nPesquisar ) {

                    nExiste++;

                } 
            }

            if (repetidos[nPesquisar] > 1 ) {

                repetidos[nPesquisar]++ ;

                return(0);
            }
        }
    }

    return( retorno );
}

int varrerMatriz( int matriz[totalLinhas][totalColunas], int * repetidos ) {

    int x1, x2, y1, y2, retorno;

    int quadrante[totalQuadrante][totalQuadrante];

    retorno = 1;


    for(y1 = 0; y1 < 9; y1 += 3) {

        for(x1 = 0; x1 < 9; x1 += 3){

            for(y2 = 0; y2 < 3; y2++) {

                for(x2 = 0; x2 < 3; x2++) {

                    quadrante[y2][x2] = matriz[y2 + y1][x2 + x1];
                }
            }

            if(!varrerQuadrante(quadrante, repetidos)) {

                return(0);
            }
        }
    }

    return (retorno);
}


int main() {

    int x;

    // Despreza a posicao zero :: validos de 1 a 9
    int repetidos[totalColunas +1] = {0}; 

    int matrizSudoku[totalLinhas][totalColunas] = {        
          {5, 3, 4, 6, 7, 8, 9, 1, 2}
        , {6, 7, 2, 1, 9, 5, 3, 4, 8}
        , {1, 9, 8, 3, 4, 2, 5, 6, 7}

        , {8, 5, 9, 7, 6, 1, 4, 2, 3}
        , {4, 2, 6, 8, 5, 3, 7, 9, 1}
        , {7, 1, 3, 9, 2, 4, 8, 5, 6}

        , {9, 6, 1, 5, 3, 7, 2, 8, 4}
        , {2, 8, 7, 4, 1, 9, 6, 3, 5}
        , {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };


    system("clear");
    printf("main() :: Matriz Quadrada :: " );


    if( varrerLinhas( matrizSudoku, repetidos) 
        && varrerColunas(matrizSudoku, repetidos ) 
        && varrerMatriz(matrizSudoku, repetidos ) ) {

        printf( "\n Matriz válida");

    } else {

        printf( "\n *** Inválida *** ");

    }

    // Valido de 1 a 9
    for (x = 1; x < totalColunas +1; x++) {

        printf( "\n " );
        printf("\n :: Número: %d, repetido %d vezes", x, repetidos[x] );

    }

    return(0);
}

