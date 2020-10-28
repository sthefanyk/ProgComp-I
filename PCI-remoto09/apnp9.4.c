#include "skv.h"

int main(){

	char *nome;
	int fim, start;

	printf("- Digite um nome: ");
	fflush(stdin);
	nome = scang();

	int i;

	for(i = 0; i < strlen(nome); i++){
		if(nome[i] >= 'A' && nome[i] <= 'Z'){//pega o último maiusculo
			fim = i;
		}
	}
		
	for(i = fim; i < strlen(nome); i++){
		if(nome[i] >= 'a'){
			nome[i] -= 32;
		}
		printf("%c", nome[i]);
	}
	printf(", ");

	for(i = 0; nome[i] != ' '; i++){
		printf("%c", nome[i]);	
	}
	printf(" ");
	
	start = i;

	for ( i = start; i < fim; i++){
		if(nome[i] >= 'A' && nome[i] <= 'Z'){
			printf("%c. ", nome[i]);
		}
	}

	printf("\n\n");
	return 0;
}

