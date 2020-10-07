#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

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
    int i = 0, j, k = 0, t;
    int fim, pc1, pl1, pc2, pl2, tecla, lembra;
    char mtz[TAM][TAM], tab[TAM][TAM], memoria[TAM][TAM], op[2];
    int  ponto = 0, sabe = 0, jogador = 0, jogada = 0;
    int pc = 0, pl = 0, mesma;
    char *nome1, *nome2; 
    int enter = 0;

    op[0] = '>';
    op[1] = op[2] = ' ';
  
    // seleciona contra quem quer jogar
    do{
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t===========================\n");
        printf("\t\t\t\t\t\t=     GAME DA MEMORIA     =\n");
        printf("\t\t\t\t\t\t===========================\n\n");
        
        printf("\t\t\t\t\t\t %c1) VS CPU          \n", op[0]);
        printf("\t\t\t\t\t\t %c2) VS P2           \n", op[1]);
        printf("\t\t\t\t\t\t %c3) SAIR            \n\n\n", op[2]);
       
        printf("\t\t\t\t\t\t===========================\n");
        printf("\t\t\t\t\t\t=    SELECIONE PLAYER     =\n");
        printf("\t\t\t\t\t\t===========================\n");

        tecla = getche();
        // CIMA
        if(tecla == 119 ) {
            if(i > 0){
                op[i] = ' ';
                i--;
                op[i] = '>';
            }
        }
        // BAIXO
        else if(tecla == 115) {
            if(i < 2){
                op[i] = ' ';
                i++;
                op[i] = '>';
            }
        }

    }while(tecla != ENTER);

             
        geraNumerosAleat( MIN, MAX, letras, numElement);
        Agrupar(numElement, REPT, letras, grupo);
        embaralhaVetor(grupo, TAM * TAM);

        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t - Digite seu nome: \n\t\t\t\t\t\t    ");

        //PEGA NOME DO PLAYER
        int pos = 0;
        char c;
        nome1 = malloc(1 * sizeof(char));
                
        fflush(stdin);
            
        do {
            c = getche    ();
            if(c != 13) {
                nome1[pos] = c;
                pos++;
                nome1 = realloc(nome1, (pos+1) * sizeof(char));
            }
        }while(c != 13);

        nome1[pos] = '\0';

        //monta matriz
        for ( i = 0; i < TAM; i++){
            for ( j = 0; j < TAM; j++, k++){
                mtz[i][j] = grupo[k];
            }  
        }            
              
        // tempo para memorizar
        for ( t = TIME; t >= 0; t--){

            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t=========================\n");
            printf("\t\t\t\t\t\t=    GAME DA MEMORIA    =\n");
            printf("\t\t\t\t\t\t=========================\n");

            for ( i = 0; i < TAM; i++){
                printf("\t\t\t\t\t\t       ");
                for ( j = 0; j < TAM; j++, k++){
                    printf(" %c", mtz[i][j]);
                }
                printf("\t\t\t\t\t\t\n");    
            }
            printf("\t\t\t\t\t\t=========================\n");
            printf("\t\t\t\t\t\t      %d segundo(s)      \n", t);
            printf("\t\t\t\t\t\t=========================\n");
            fflush(stdin);
            sleep(1);
            
        }

        // incializa matrizes tab e memoria
        for ( i = 0; i < TAM; i++){
            for ( j = 0; j < TAM; j++, k++){
                tab[i][j] = '@';
                memoria[i][j] = '#';   
            }  
        }
            
    fim = pc1 = pl1 = 0;
    //inicia o jogo
    while(fim == 0) {

        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t==========================\n");
        printf("\t\t\t\t\t\t        %s jogando        \n", nome1);
        printf("\t\t\t\t\t\t==========================\n");
        for(i = 0; i < TAM; i++) {
            printf("\t\t\t\t\t\t       ");
            for(j = 0; j < TAM; j++) {
                printf(" %c", tab[i][j]);
            }           
            printf("\t\t\t\t\t\t\n");
        }
        printf("\t\t\t\t\t\t==========================\n");
        if(jogada == 1){
            printf("\t\t\t\t\t\t       Encontrar [%c]      \n", mtz[pl1][pc1]);
        }else if (jogada == 0){
            printf("\t\t\t\t\t\t        [SELECIONE]        \n");
        }
        printf("\t\t\t\t\t\t==========================\n");
        for(i = 0; i < TAM; i++) {
            printf("\t\t\t\t\t\t       ");
            for(j = 0; j < TAM; j++) {
                printf(" %c", memoria[i][j]);
            }           
        printf("\t\t\t\t\t\t\n");
        }
        sleep(2);
        fflush(stdin);
        sleep(0);
                    
        //verifica se é a primeira ou a segunda jogada
        if(jogada == 0){
            //seleciona posição aleatória
            do{
                pl1 = rand() % 6; 
                pc1 = rand() % 6;
            }while(tab[pl1][pc1] != '@');

                tab[pl1][pc1] = memoria[pl1][pc1] = mtz[pl1][pc1];

                system("cls");
                printf("\n\n\n\n");
                printf("\t\t\t\t\t\t==========================\n");
                printf("\t\t\t\t\t\t        %s jogando        \n", nome1);
                printf("\t\t\t\t\t\t==========================\n");
                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf(" %c", tab[i][j]);
                    }           
                printf("\t\t\t\t\t\t\n");
                }
                printf("\t\t\t\t\t\t==========================\n");
                printf("\t\t\t\t\t\t     [%c] Selecionado!    \n", mtz[pl1][pc1]);
                printf("\t\t\t\t\t\t==========================\n");
                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf(" %c", memoria[i][j]);
                    }           
                printf("\t\t\t\t\t\t\n");
                }
                sleep(2);
                fflush(stdin);
                sleep(0);
                        
            jogada++;
        }else{
                        
            //verifica se posição ja esta salva na memoria
            for ( i = 0; i < TAM; i++){
                for ( j = 0; j < TAM; j++){
                    if (mtz[pl1][pc1] == memoria[i][j] && !(pl1 == i && pc1 == j)){
                        sabe = 1;
                        pl2 = i;
                        pc2 = j;
                        i = TAM;
                    }
                }  
            }
                        
                        
            if(sabe == 1){
                        
                lembra = rand() % 2;
                if (lembra == 1){
                    tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2];//mostra
                }else{
                    memoria[pl1][pc1] = '#';
                    do{
                        pl2 = rand() % 6; 
                        pc2 = rand() % 6;
                    }while(tab[pl2][pc2] != '@' && !(pl2 == pl1 && pc2 == pc1));

                    tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2];//mostra
                }
                sabe = 0;
            }else{
                do{
                    pl2 = rand() % 6; 
                    pc2 = rand() % 6;
                }while(tab[pl2][pc2] != '@' && !(pl2 == pl1 && pc2 == pc1));

                tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2];//mostra

            }
            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t==========================\n");
            printf("\t\t\t\t\t\t        %s jogando        \n", nome1);
            printf("\t\t\t\t\t\t==========================\n");
            for(i = 0; i < TAM; i++) {
                printf("\t\t\t\t\t\t       ");
                for(j = 0; j < TAM; j++) {
                    printf(" %c", tab[i][j]);
                }           
            printf("\t\t\t\t\t\t\n");
            }
            printf("\t\t\t\t\t\t==========================\n");
            printf("\t\t\t\t\t\t [%c] e [%c] Selecionado! \n", mtz[pl1][pc1], mtz[pl2][pc2]);
            printf("\t\t\t\t\t\t==========================\n");
            for(i = 0; i < TAM; i++) {
                printf("\t\t\t\t\t\t       ");
                for(j = 0; j < TAM; j++) {
                    printf(" %c", memoria[i][j]);
                }           
            printf("\t\t\t\t\t\t\n");
            }
            sleep(1);
            fflush(stdin);
            sleep(0);

            if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                system("cls");
                printf("\n\n\n\n");
                printf("\t\t\t\t\t\t==========================\n");
                printf("\t\t\t\t\t\t        %s ACERTOU!       \n", nome1);
                printf("\t\t\t\t\t\t==========================\n");
                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf(" %c", tab[i][j]);
                    }           
                printf("\t\t\t\t\t\t\n");
                }
                printf("\t\t\t\t\t\t==========================\n");
                printf("\t\t\t\t\t\t pontos                   \n");
                printf("\t\t\t\t\t\t==========================\n");
                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf(" %c", memoria[i][j]);
                    }           
                printf("\t\t\t\t\t\t\n");
                }
                memoria[pl1][pc1] = mtz[pl1][pc1];
                sleep(2);
                fflush(stdin);
                sleep(0);

                jogador++;
            }else{
                            
                system("cls");
                printf("\n\n\n\n");
                printf("\t\t\t\t\t\t=========================\n");
                printf("\t\t\t\t\t\t=        %s ERROU!      =\n", nome1);
                printf("\t\t\t\t\t\t=========================\n");
                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf(" %c", tab[i][j]);
                    }           
                printf("\t\t\t\t\t\t\n");
                }
                printf("\t\t\t\t\t\t==========================\n");
                printf("\t\t\t\t\t\t pontos                   \n");
                printf("\t\t\t\t\t\t==========================\n");
                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf(" %c", memoria[i][j]);
                    }           
                printf("\t\t\t\t\t\t\n");
                }
                sleep(1);
                fflush(stdin);
                sleep(1);
                tab[pl2][pc2] = '@';
                tab[pl1][pc1] = '@';
                            
                jogador++;  
            }
            printf("\n");
            sleep(1);
            fflush(stdin);
                        
            jogada--;      
        }  
    }

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
