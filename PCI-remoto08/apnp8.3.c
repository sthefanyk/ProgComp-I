#include <stdio.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int v[4], i, soma = 0, media;

    printf("Vetor aleatorio:");
    for ( i = 0; i < 4; i++){
        v[i] = 100 + (rand() % 100 - 10);
        soma += v[i];
        printf(" %d", v[i]);
    }
    media = soma / 4;

    printf("\n - Valor medio: %d", media);        

    return 0;
}
