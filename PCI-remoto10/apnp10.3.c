#include "skv.h"

#define TAM 5

int main(){

    srand(time(NULL));

    int matriz[TAM][TAM], trasnp[TAM][TAM], vetor[TAM*TAM];
    int lin, col, lin2, col2;
    int i, j, k, aux;

    geraNumerosAleat( 10, 51, vetor, 36);

    for ( i = 0; i < TAM; i++){
        for ( j = 0; j < TAM; j++, k++){
            matriz[i][j] = vetor[k];
        }  
    }            
              
    printf(" - Matriz Aleatorios:\n\n\t");

    for( lin = 0 ; lin < TAM ; lin++ ){
        for( col = 0 ; col < TAM ; col++){
            printf(" %d", matriz[lin][col]);
        }
        printf("\n\t");
    }

    for( lin = 0 ; lin < TAM ; lin++ ){
        for( col = 0 ; col < TAM ; col++){
            trasnp[col][lin] = matriz[lin][col];
        }
    }

    printf("\n\n - Matriz Transposta:\n\n\t");

    for( lin = 0 ; lin < TAM ; lin++ ){
        for( col = 0 ; col < TAM ; col++){
            printf(" %d", trasnp[lin][col]);
        }
        printf("\n\t");
    }

    return 0;
}
