#include <stdio.h>
#include <math.h>

int main(){

    int a, b, c;
    float x, y;

    printf("Digite os coeficiente (a), (b) e (c): ");
    scanf("%i %i %i", &a, &b, &c);

    x = (-b + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
    y = (-b - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);

    printf("- Raizes = %.1f e %.1f", x, y);


    return 0;
}

