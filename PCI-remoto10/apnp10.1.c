#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main(){

    srand(time(NULL));

    int matriz[TAM][TAM];
    int lin, col, lin2, col2;
    int aux, existe = 0, num;

    for( lin = 0 ; lin < TAM ; lin++ ){
        for( col = 0 ; col < TAM ; col++){

            num = (rand() % 40) + 10;

            for( lin2 = 0 ; lin2 < lin ; lin2++ ){
                for( col2 = 0 ; col2 < col ; col2++){

                    if(matriz[lin2][col2] == num){
                        existe = 1;
                        lin2 = lin;
                    }
                }
            }
            while(existe = 1){

                existe = 0;
                matriz[lin][col] = (rand() % 40) + 10;

                for( lin2 = 0 ; lin2 < lin ; lin2++ ){
                    for( col2 = 0 ; col2 < col ; col2++){
                        if(matriz[lin2][col2] = num){
                            existe = 1;
                        }
                    }
                }
            }
            matriz[lin][col] = num;
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
