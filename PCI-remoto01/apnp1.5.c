#include <stdio.h>

int main(){

    float cel, far;

    printf("Digite a temperatura em Celsius (ºC): ");
    scanf("%f", &cel);

    far = (9 * cel + 160) / 5;

    printf("- Temperatura em Fahrenheit = %.1f", far);
    
    return 0;
}
