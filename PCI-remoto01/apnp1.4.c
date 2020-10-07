#include <stdio.h>

int main(){

    int num, d1, d2, d3, soma;

    printf("Digite um numero de tres digitos: ");
    scanf("%i", &num);

    d1 = num / 100;
    d2 = (num % 100) / 10;
    d3 = ((num % 100) % 10);

    soma = d1 + d2 + d3;
    
    printf("- soma = %i + %i + %i = %i", d1, d2, d3, soma);
    return 0;
}