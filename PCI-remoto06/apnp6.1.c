#include <stdio.h>

int main(){

    int num, mul = 1, i, count = 0;

    printf("Digite um valor inteiro: ");
    scanf("%i", &num);

    printf("- Fatorial(%i) = ", num);

    for(i = num;i > 1; i--){
        mul *= i;

        if(i != 2){
            printf("%i x ", i);
        }else
            printf("%i ", i);
    }
   
    printf("= %i", mul);

    return 0;
}