#include "skv.h"

int main(){

    int i, j;
	char **nomes;
	char *aux = malloc(50 * sizeof(char));
	
	nomes = malloc(5 * sizeof(char*));
	
	printf("- Digite 5 nomes: \n");
	for(i=0; i<5 ; i++){
		nomes[i] = scang();		
	}

	//CODÍGO DE ORDENAÇÃO
	
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if(strcmp(nomes[i], nomes[j]) < 0){
				strcpy(aux, nomes[i]);
				strcpy(nomes[i], nomes[j]);
				strcpy(nomes[j], aux);
			}
		}
	}
		
	printf("- Ordenado: \n");
	for(i=0; i<4; i++){
		printf("\t%s\n", nomes[i]);		
	}
	printf("\t%s", nomes[4]);

    return 0;
}
