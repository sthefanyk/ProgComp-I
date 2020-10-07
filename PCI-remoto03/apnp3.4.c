#include <stdio.h>

int main(){

    char conceito;

    printf("Digite o conceito do aluno: ");
    scanf("%c", &conceito);

    if(conceito == 'A' || conceito == 'B' || conceito == 'C'){
        printf("- APTO");
    }else if(conceito == 'D'){
        printf("- INAPTO");
    }else
        printf("- Conceito invalido!");

  return 0;
}
