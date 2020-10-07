#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIN 5
#define COL 5
#define TAM 5
ew5
int main(){

	srand(time(NULL));

	int matriz[TAM][TAM], linha, coluna, soma = 0,maior;

	for (linha = 0; linha < TAM; ++linha){
		for (coluna = 0; coluna < TAM; ++coluna){
			matriz[linha][coluna] = rand() % 10;
		}
	}

	maior = matriz[0][0];

	printf("\t- Valores da Matriz: \n\t");
	for (linha = 0; linha < TAM; ++linha){
		for (coluna = 0; coluna < TAM; ++coluna){
			if (matriz[linha][coluna] < 10){
				printf("0");
			}
			printf("%i ", matriz[linha][coluna]);
		}
		printf("\n\t");
	}


	for (linha = 0; linha < TAM; ++linha){
		for (coluna = 0; coluna < TAM; ++coluna){
			if (maior < matriz[linha][coluna]){
				maior = matriz[linha][coluna];
			}
		}
	}

	printf("- Maior : %i", maior);
	printf("\n");


	return 0;
}
