#include <stdio.h>

int main(){

    int num, x;

    printf("Digite um numero inteiro: ");
    scanf("%i", &num);

    x = num % 2;

    if(x == 0){
        printf("O numero <%i> e PAR", num);
    }else
        printf("O numero <%i> e IMPAR", num);
   
    return 0;
}
