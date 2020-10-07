#include <stdio.h>

int main(){

    int valor, l, c;

    printf("\n\t\tDigite 1 valor inteiro: ");
    scanf("%i", &valor);

    printf("\n\n");

    for(c = 0;c < valor; c++){
        for(l = 0; l < valor; l++){
            printf("  * ");
        }
        printf("\n");
    }
    
    return 0;
}
