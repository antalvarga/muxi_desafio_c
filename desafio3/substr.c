/*

    AV 20210111
    Desafio muxi:


    > 3. Escreva uma função que dada uma string composta por substrings 
    separadas por um dado caractere, retorne todas as suas substrings da 
    string original. Por exemplo, dado o separador ‘/’, 
    a string “/Fla/Flu/Bota/” será decomposta em:
        • Fla
        • Flu
        • Bota

    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio3

    compilacao:
    gcc substr.c -o substr

    Execucao: 
    ./substr

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define zero 0



int totalLimitador ( char strIn[], char limitador[] ) {

    int x, total = 0;
    int tamanho = strlen( strIn );


    // recupera o codigo asci 
    int asciStrIn, asciLimite = 0; 

    asciLimite = limitador[0];


    for ( x = 0; x <= tamanho; x++ ) {

        asciStrIn = strIn[x];

        if (asciStrIn == asciLimite ) {

            total ++ ;
        }
    }

    return( total );
}



int splitTexto( char strIn[], char limitador[] ) {

    int x1, x2 = zero;
    int tamanho = strlen( strIn );

    int asciStrIn, asciLimite = zero; 

    asciLimite = limitador[zero];


    int total = totalLimitador( strIn, limitador );

    char * retorno[total][tamanho];


    for ( x1 = zero; x1 <= tamanho; x1++ ) {

        asciStrIn = strIn[x1];

        if (asciStrIn == asciLimite ) {

            // salvar aonde foi encontrado o limitador
            if ( x1 >= 0) {

                // incrementa x1 para desprezar o limitador
                x1++ ; 
                x2++ ;

                printf( "\n" );
            }

        }

        // Recupero o byte e salva acumulando
        //retorno[x2][x1] += strIn[x1]; 

        printf( "%c", strIn[x1] );

    }

    printf( " :: total limitadores: %d ::  ", total );

    return( total );
}



int main() {


    system("clear");
    printf("main() :: Split :: " );
 
    char texto[] = "/Fla/Flu/Bota/";
    
    int tamanho = strlen( texto );

    char limitador[] = "/";

    // Nr de vezes que aparece o limitador dentro da string texto
    int totalLimite = totalLimitador( texto, limitador );

    int x1 = 0;

    splitTexto( texto, limitador );

    return(0);

}