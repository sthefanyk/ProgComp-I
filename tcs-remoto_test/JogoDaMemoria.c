#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define TAM 6
#define REPT 2
#define MAX 90 + 1
#define MIN 65
#define TIME 2
#define ENTER 13

int geraNumerosAleat( int min, int max, int vetor[], int numElement);
int Agrupar(int qtdNum, int rept, int vetor[], int result[]);
int embaralhaVetor(int vetor[], int numElement);

int main(){

    int numElement = (TAM * TAM) / REPT;
    int letras[numElement], grupo[TAM * TAM];
    int i, j, k = 0, t;
    int fim, pc, pl, tecla, lin, col;
    char mtz[TAM][TAM], tab[TAM][TAM], comp[2];
    int count = 0, pcc, plc, ponto = 0;

   geraNumerosAleat( MIN, MAX, letras, numElement);
   Agrupar(numElement, REPT, letras, grupo);
   embaralhaVetor(grupo, TAM * TAM);

    for ( i = 0; i < TAM; i++){
        for ( j = 0; j < TAM; j++, k++){
            mtz[i][j] = grupo[k];
        }  
    }

    for ( t = TIME; t >= 0; t--){

        system("cls");
        printf("===================\n");
        printf("= GAME DA MEMORIA =\n");
        printf("===================\n");

        for ( i = 0; i < TAM; i++){
            printf("   ");
            for ( j = 0; j < TAM; j++, k++){
                printf(" %c", mtz[i][j]);
            }
            printf("\n");    
        }
        printf("===================\n");
        printf("   %d segundo(s)   \n", t);
        printf("===================\n");
        fflush(stdin);
        sleep(1);
        
    }

    for ( i = 0; i < TAM; i++){
        for ( j = 0; j < TAM; j++, k++){
            tab[i][j] = '@';   
        }  
    }
    
    fim = pc = pl = 0;

    while(fim == 0) {

		system("cls");

        printf("===================\n");
        printf("= GAME DA MEMORIA =\n");
        printf("===================\n");
		for(lin = 0; lin < TAM; lin++) {
            printf("   ");
			for(col = 0; col < TAM; col++) {
				if(lin == pl && col == pc) {
					printf("_ ");
				}
				else {
					printf("%c ", tab[lin][col]);
				}
			}
			printf("\n");
		}
        printf("===================\n");
        printf("    segundo(s)   \n");
        printf("===================\n");
        fflush(stdin);


		tecla = getche();
		t = tecla;
		// CIMA
		if(t == 119) {
			if(pl > 0) pl--;
		}
		// BAIXO
		else if(t == 115) {
			if(pl < TAM-1) pl++;
		}
		// DIREITA
		else if(t == 100) {
			if(pc < TAM-1) pc++;
		}
			
        // ESQUERDA
		else if(t == 97) {
			if(pc > 0) pc--;
		}
			
		else if(tecla == ENTER) {

            if(tab[pl][pc] != '@'){
                printf("Pocisao invalida!");
                sleep(1);
            }else{
                tab[pl][pc] = mtz[pl][pc];
                if(count == 0){
                    comp[count] = mtz[pl][pc];
                    plc = pl;
                    pcc = pc;
                    count++;
                }else if(count == 1){
                    comp[count] = mtz[pl][pc];
                    count--;
                    
                    if(comp[0] != comp[1]){
                        tab[plc][pcc] = '@';
                        tab[pl][pc] = '@';
                        printf("     [ERROU!]");
                    }else if(comp[0] == comp[1]){
                        printf("    [ACERTOU!]");
                        ponto++;
                    }
                    
                }
                printf("\n [%c] Selecionado!", mtz[pl][pc]);
                fflush(stdin);
                getchar();
            }
		}
	}
	
	printf("\n\n");

    return 0;
}

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
