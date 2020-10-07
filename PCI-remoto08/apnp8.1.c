#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int num[12], i, q = 0, m = 0, n[12], p, j = 0;

    for(i = 0;i < 12; i++){
        num[i] = 50 + (rand() % 50 - 10);
    }

    printf("\n\tVetor aleatorio:");


    for(i = 0 ;i < 12; i++){

        printf(" %d", num[i]);

        if (num[i] > 20 && num[i] < 40){
            q++;
        }
        if(num[i] > 35){
            m++;
        }
        p = num[i] % 2;
        if(p == 0){
            n[j] = num[i];
            j++;
        }
    }

    printf("\n\n - Qtde de numeros entre 20 e 40: %d", q);

    printf("\n - Numeros pares:");   
    for(i = 0 ;i < j; i++){
        printf(" %d", n[i]);
    }

    printf("\n - Qtde de numeros maiores que 35: %d", m);
    return 0;
}
