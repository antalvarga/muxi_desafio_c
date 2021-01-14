/*

    AV 20210111
    AV 20210113: Refazendo para contemplar o protótipo

    Desafio muxi:

    > 3. Escreva uma função que dada uma string composta por substrings 
    separadas por um dado caractere, retorne todas as suas substrings da 
    string original. Por exemplo, dado o separador ‘/’, 
    a string “/Fla/Flu/Bota/” será decomposta em:
        • Fla
        • Flu
        • Bota

    O protótipo da função é o seguinte: 

    char** stringSplit (const char *text, char separator, int *length);


    pwd: 
    /Volumes/Macintosch/Users/asvarga/App/C/muxi/desafio/desafio3

    compilacao:
    gcc subString.c -o subString

    Execucao: 
    ./subString 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define zero 0



/*

    Retornar o total de ocorrencia em uma string

*/
int totalLimitador ( char strIn[], char limitador[] ) {

    int x, total = 0;
    int tamanho = strlen( strIn );

    // recupera o codigo asci 
    int asciStrIn, asciLimite = 0; 

    asciLimite = limitador[0];


    //printf( "\n :: strIn :: %s", strIn);
    //printf( "\n :: limitador :: %s", limitador);


    for ( x = 0; x <= tamanho; x++ ) {

        asciStrIn = strIn[x];

        if (asciStrIn == asciLimite ) {

            total ++ ;
        }
    }

    return( total );
}




char ** stringSplit( const char * text, char separator, int *length) {

    int x = 0;

    char ** retorno;

    char * meuSplit;

    // para evitar bug no casting/strtok
    int tamanho = *(length);
    
    char * novoTexto = (char *)text;

    char * novoLimitador = &separator; 

    int total = totalLimitador( novoTexto, novoLimitador);

    meuSplit = strtok( novoTexto, novoLimitador) ;

    retorno = malloc( sizeof( char *) * total );

    do {

        if ( meuSplit ) {
            *( retorno + x++ ) = strdup( meuSplit );

        }

        meuSplit = strtok( 0, novoLimitador );

    } while ( meuSplit );

    return( retorno );
}




int main() {

    system("clear");
    printf("main() :: Split :: " );

    char texto[] = "/Fla/Flu/Bota/";
    
    int tamanho = strlen( texto );

    char limitador = '/';

    int x1 = zero;

    char ** subStrings;

    subStrings = stringSplit( texto, limitador, &tamanho );


    if ( subStrings ) {
        
        for ( x1 = zero; *( subStrings + x1); x1++ ) {

            printf( "\n %s", *(subStrings + x1 ));

            free( *(subStrings + x1) );
        }
    }

    free( subStrings );

    printf("\n :: Fim :: ");
    
    return(0);
}