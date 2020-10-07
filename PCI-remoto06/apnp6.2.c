#include <stdio.h>

int main(){

    int num, f1 = 0, f2 = 1, res, i;

    printf("Numero de termos: ");
    scanf("%i", &num);

    printf("\n- Serie Fibonacci[%i]: 1", num);

    for(i = 1;i < num ; i++){
   
        res = f1 + f2;
        printf(" %i", res);
        f1 = f2;
        f2 = res;
        
    }

    return 0;
}
