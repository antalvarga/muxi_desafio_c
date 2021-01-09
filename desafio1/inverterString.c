/*
    AV 20210108
    Desafio muxi
    Escreva usando a linguagem C uma função para inverter uma string.

    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio1

    compilacao:
    gcc inverterString.c -o inverter

    Execucao: 
    ./inverter 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAMANHO 40



char * inverterString2( char * palavraInicial ) {

    int tamanhoPalavraInicial = strlen( palavraInicial );
    int y = tamanhoPalavraInicial -1;
    
    char palavraInvertida[TAMANHO];
    int x;


    for ( x = y; x >= 0; x--) {

        palavraInvertida[ y-x] = palavraInicial[x];

    }

    strcpy( palavraInicial, palavraInvertida );

    return( palavraInicial );
}



int main() {

    char palavra[TAMANHO];
    char palavra2[TAMANHO] = "Deus";
    
    system("clear");
    printf("\n main() :: \n ");

    printf( "Digite: ");
    scanf("%s", palavra);

    inverterString2( palavra );
    inverterString2( palavra2 );
    
    printf("\n main :: após inverter a palavra %s", palavra );
    printf("\n main :: após inverter a palavra2 %s", palavra2  );

    return(0);
}