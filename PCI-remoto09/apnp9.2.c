#include <stdio.h>

int main(){

    int v[10], i, j;

    for ( i = 0; i < 10; i++){
        printf("\nDigite o valor da posicao %d: ", i);
        scanf("%d", &v[i]);
    }

    printf("\nPosicao\t\tValor\t\tHistograma\n");
    for ( i = 0; i < 10; i++){
        printf("%d\t\t%d\t\t", i, v[i]);
        for ( j = 0; j < v[i]; j++){
            printf("*");
        }
        printf("\n");
        
    }
    
    

    return 0;
}
