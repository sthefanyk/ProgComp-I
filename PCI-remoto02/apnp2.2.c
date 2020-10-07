#include <stdio.h>
#include <math.h>

int main(){

    int a, b, c;
    float resultado;

    printf("Digite os valores de (a), (b) e (c): ");
    scanf("%i %i %i", &a, &b, &c);

    resultado = sin(pow(a,b) + sqrt(c));


    printf("- Resultado = %.2f", resultado);


    return 0;
}
