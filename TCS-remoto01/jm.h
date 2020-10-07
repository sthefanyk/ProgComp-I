#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6
#define REPT 2
#define MAX 90 + 1
#define MIN 65
#define TIME 2
#define ENTER 13
#define NUM_ELEMENT (TAM * TAM) / REPT

int geraNumerosAleat( int min, int max, int vetor[], int numElement);
int Agrupar(int qtdNum, int rept, int vetor[], int result[]);
int embaralhaVetor(int vetor[], int numElement);

int geraNumerosAleat( int min, int max, int vetor[], int numElement){

    srand(time(NULL));

    int i, j, num, existe;

    vetor[0] = rand() % (max - min) + min;
    
    for(i = 1; i < numElement ; i++){
        do{
            num = rand() % (max - min) + min;
            for(j = 0; j < i; j++){
                if(num == vetor[j]){
                    existe = 1;
                    j = i;
                }else
                    existe = 0;
            }
        }while(existe != 0);
        vetor[i] = num;
    }
    return vetor[numElement];
}

int Agrupar(int qtdNum, int rept, int vetor[], int result[]){
    int i, j, a = 0, b;

    for ( i = 0; i < qtdNum; i++){
        b = 0;
        for ( j = a; b < rept; j++){
            result[j] = vetor[i]; 
            b++;
        }
        a += rept;
    }
    return result[qtdNum * rept];
}
 
int embaralhaVetor(int vetor[], int numElement){

    int i, j;
    int posic[numElement], embaralhado[numElement];

    geraNumerosAleat( 0, numElement, posic, numElement );
    
    for(i = 0; i < numElement ; i++){
        embaralhado[posic[i]] = vetor[i] ;
    }
    
    for ( i = 0; i < numElement; i++){
        vetor[i] = embaralhado[i];
    }
    return vetor[numElement];
}
