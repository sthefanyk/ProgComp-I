#include <stdio.h>

int main(){

    int v1, v2, par, i, soma = 0, c1 = 0;
	char cont;

	printf("Digite dois valores inteiros: ");
	scanf("%i %i", &v1, &v2);
	
	printf("\nSomando valores pares: ");
	    
	if(v1 < v2){
	
	    for(i = v1 + 1;i < v2;i++){
	        par = i % 2;
	
	        if(par == 0){
	            if(c1 == 1){
	                printf(" + ");
	                c1--;
	            }
	            printf("%i", i);
	            c1++;
	            soma += i;
	        }
	    }
	    printf(" = %i", soma);
	}else
	    printf("Valores incorretos.");

    return 0;
}