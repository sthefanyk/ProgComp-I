#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    FILE *arq;
    char caracter;
    int num = 0, imprime = rand() % 10, i = 0;
    char nome[10];
    
    arq = fopen("arquivo.txt", "r");

    do{
        caracter = fgetc(arq);
        if(caracter == '\n'){
            num++;
        }
        if(imprime == num){
            nome[i] = caracter;
            printf("%c", nome[i]);
            i++;
        }
        
    } while (caracter != EOF);

    fclose(arq);

    return 0;
}
