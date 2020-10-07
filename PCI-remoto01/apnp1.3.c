#include <stdio.h>

int main(){

    float c_med, gasol, dist;

    printf("Media de consumo (km/l): ");
    scanf("%f", &c_med);
    printf("Gasolina no tanque (l): ");
    scanf("%f", &gasol);

    dist = c_med * gasol;

    printf("- Distancia percorrida = %.1f Km", dist);
    
    return 0;
}
