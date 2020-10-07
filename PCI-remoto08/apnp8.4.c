#include <stdio.h>

int main(){
    
    int preco[4], i, inf = 0, j = 0;
    char produto[4], p[4];

    for ( i = 0; i < 4; i++){
        printf("Produto / Preco: ");
        fflush(stdin);
        scanf("%c %d", &produto[i], &preco[i]);
        if (produto[i] >= 'a' && produto[i] <= 'z'){
            produto[i] -= 32;
        }    
        if (preco[i] < 60){
            inf++;
        }
        if (preco[i] >= 40 && preco[i] <= 100){
            p[j] = produto[i];
            j++;
        }
    }
    printf("\n - Produto com preco inferior R$60,00: %d\n", inf);
    printf(" - Produto com preco entre R$40,00 e R$100,00:");

    for ( i = 0; i < j; i++){
        printf(" %c", p[i]);    
    }
    
    return 0;
}
