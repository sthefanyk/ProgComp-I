#include <stdio.h>

int main(){

    int num, i, div, soma = 0, c1 = 0, c2 = 1;

    printf("Digite um numero: ");
    scanf("%i", &num);

    printf("- [");

    for(i = 1;i < num; i++){
        div = num % i;

        if(div == 0){

            if(c1 == c2){
                printf(" + ");
                c1--;
            }
            
            printf("%i", i);
            c1++;
            soma += i;      
        }
        
    }
    if(soma == num){
        printf("] = %i / PERFEITO", num);
    }else
        printf("] != %i / IMPERFEITO", num);


    return 0;
}
