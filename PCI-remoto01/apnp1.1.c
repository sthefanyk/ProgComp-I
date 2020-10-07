#include <stdio.h>

int main(){

    int val, q, c;

    printf("Digite um valor inteiro: ");
    scanf("%i", &val);

    q = val * val;
    c = q * val;

    printf("- Quadrado = %i\n- Cubo = %i", q, c);
    
    return 0;
}
