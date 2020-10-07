#include <stdio.h>
#include <math.h>

int main(){

    int co , ca;
    float hi;

    printf("Cateto oposto: \n");
    scanf("%i", &co);

    printf("Cateto adjacente: \n");
    scanf("%i", &ca);

    hi = sqrt(pow(co,2) + pow(ca,2));

    printf("- Resultado = %.1f", hi);

    return 0;
}
