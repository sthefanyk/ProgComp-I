#include "skv.h"

#define TAM 5

int main(){

    srand(time(NULL));

    int matriz[TAM][TAM], vetor[TAM * TAM];
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

    for( lin = 0 ; lin < TAM ; lin++ ){ // ordena matriz
        for( col = 0 ; col < TAM ; col++){

            for( lin2 = 0 ; lin2 < TAM ; lin2++ ){
                for( col2 = 0 ; col2 < TAM ; col2++){
            
                    if(matriz[lin][col] < matriz[lin2][col2]){
                        aux = matriz[lin][col];
                        matriz[lin][col] = matriz[lin2][col2];
                        matriz[lin2][col2] = aux;

                    }
                }
            }
        }
    }

    printf("\n\n - Matriz Ordenada:\n\n\t");

    for( lin = 0 ; lin < TAM ; lin++ ){
        for( col = 0 ; col < TAM ; col++){
            printf(" %d", matriz[lin][col]);
        }
        printf("\n\t");
    }

    return 0;
}
