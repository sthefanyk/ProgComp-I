#include <stdio.h>

int main(){

    int v1, v2, v3, maior, menor;

    printf("Digite 3 numeros  inteiros: ");
    scanf("%i %i %i", &v1, &v2, &v3);

    maior = v1;
    menor = v1;

    if( v2 > maior){
        maior = v2;
    }
    if(v3 > maior){
        maior = v3;
    }
    

    if( v2 < menor){
        menor = v2;
    }
    if(v3 < menor){
        menor = v3;
    }

        printf("Maior numero: %i\nMenor numero: %i", maior, menor);

    
    return 0;
}
