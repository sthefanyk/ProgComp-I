#include <stdio.h>

int main(){

    int num, maior, menor, i = 0;

    do{
        printf("Digite um numero inteiro: ");
        scanf("%i", &num);
        if(i == 0){
            maior = num;
            menor = num; 
            i++;
        }
        if(num > maior){
            maior = num;
        }
        if(num < menor && num >= 0){
            menor = num;
        }
    }while(num > 0);
    
    printf("\nMaior numero: %i", maior);
    printf("\nMenor numero: %i", menor);

    return 0;
}
