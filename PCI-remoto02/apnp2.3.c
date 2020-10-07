#include <stdio.h>
#include <math.h>

int main(){

    int a, b;
    float resultado;

    printf("Digite os valores de (a) e (b): ");
    scanf("%i %i", &a, &b);

    resultado = tan(sqrt(pow(a,b)));

    printf("- Resultado = %.2f", resultado);


    return 0;
}

