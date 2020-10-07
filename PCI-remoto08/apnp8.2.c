#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    
    int num[12], n, ma = 0, me, p_ma, p_me, i, j;

    printf("\n\tVetor Aleatorio:");

    num[0] = 100 + (rand() % 100 - 10);
    me = num[0];              
    for(i = 1 ;i < 12; i++){
        
        for(j = 0; j < 12; j++){
            do{
                n = (rand() % 90) + 10;              
            }while(num[j] == n);
        }

        num[i] = n;     
    }

    for(i = 0; i < 12; i++){
        
        printf(" %d", num[i]);
    }

    for (i = 0; i < 12; i++){
        if(num[i] > ma){
            ma = num[i];
            p_ma = i + 1;
        }
        if(num[i] < me){
            me = num[i];
            p_me = i+1;
        }
    }

    printf("\n\n - Maior elemento: %d / Posicao: %d", ma, p_ma);
    printf("\n\n - Menor elemento: %d / Posicao: %d", me, p_me);

    return 0;
}
