#include "skv.h"

#define TAM 5

int main(){

    srand(time(NULL));

    int matriz[TAM][TAM], vetor[TAM * TAM];
    int lin, col, lin2, col2;
    int i, j, k, aux, maior = 0;

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
            if (lin == col && matriz[lin][col] > maior){
                maior = matriz[lin][col];
            }
        }
        printf("\n\t");
    }

    printf("\n- Maior Valor: %d\n", maior);
    
    return 0;
}
