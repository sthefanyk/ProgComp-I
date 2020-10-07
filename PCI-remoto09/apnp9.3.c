#include "skv.h"

int main(){

    char frase[50], caractere;
    int i, num_c = 0;

    printf("Digite uma frase: ");
    getss(frase, 50);
    //printf("\n%s", frase);
    printf("\n\nDigite um caractere a ser procurado: ");
    scanf("%c", &caractere);
    for ( i = 0; i < 50; i++){
        if (frase[i] == '\0'){
            i = 50;
        }else if (frase[i] == caractere){
            num_c++;
        }
    }
    if (num_c == 0){
        printf("\nCaractere nao encontrado.");
    }else
        printf("\nO caractere < %c > foi encontrado < %d > vezes", caractere, num_c);

    printf("\n\n");
    return 0;
}

