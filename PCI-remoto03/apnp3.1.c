#include <stdio.h>

int main(){

    int num;

    printf("Digite um numero inteiro: ");
    scanf("%i", &num);

    if(num > 0){
        printf("O numero <%i> e POSITIVO.", num);
    }else if(num < 0){
        printf("O numero <%i> e NEGATIVO.", num);
    }else
        printf("O numero <%i> e NEUTRO.", num);

    return 0;
}