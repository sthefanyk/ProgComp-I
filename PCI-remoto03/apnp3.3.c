#include <stdio.h>

int main(){

    int idade;

    printf("Digite a idade (anos): ");
    scanf("%i", &idade);

    if(idade >= 0 && idade < 12){
        printf("- Crianca");
    }else if(idade > 11 && idade < 18){
        printf("- Adolecente");
    }else if(idade > 17 && idade < 60){
        printf("- Adulto");
    }else if(idade > 59){
        printf("- Idoso");
    }else
        printf("Idade invalida ");

    return 0;
}
