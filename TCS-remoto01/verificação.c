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
    int  ponto1 = 0, ponto2 = 0, sabe = 0, jogador = 0, jogada = 0, ponto = 0;
    int pc = 0, pl = 0, terminar;
    char *nome1, *nome2;
    int pos = 0, pos1 = 0;
    char c, d;

    op[0] = '>';
    op[1] = op[2] = ' ';
  
    // seleciona contra quem quer jogar
    do{
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t\t===========================\n");
        printf("\t\t\t\t\t\t=     GAME DA MEMORIA     =\n");
        printf("\t\t\t\t\t\t===========================\n\n");
        
        printf("\t\t\t\t\t\t %c1) 1 JOGADOR            \n", op[0]);
        printf("\t\t\t\t\t\t %c2) 2 JOGADOR            \n", op[1]);
        printf("\t\t\t\t\t\t %c3) SAIR             \n\n\n", op[2]);
       
        printf("\t\t\t\t\t\t===========================\n");
        printf("\t\t\t\t\t\t=    SELECIONE PLAYER     =\n");
        printf("\t\t\t\t\t\t===========================\n");

        tecla = getche();
        if(tecla >= 'A' && tecla <= 'Z' ){
            tecla += 32;
        }
        // CIMA
        if(tecla == 119) {
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

    switch(i){
        // Contra MAQUINA
        case 0:         
            geraNumerosAleat( MIN, MAX, letras, numElement);
            Agrupar(numElement, REPT, letras, grupo);
            embaralhaVetor(grupo, TAM * TAM);

            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t - Digite seu nome: ");

            //PEGA NOME DO PLAYER
            nome1 = malloc(1 * sizeof(char));
                
            fflush(stdin);
            
            do {
                c = getche();
                if(c >= 'a' && c <= 'z'){
                    c -= 32;
                }
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
                printf("\t\t\t\t\t\t     GAME DA MEMORIA     \n");
                printf("\t\t\t\t\t\t=========================\n");

                for ( i = 0; i < TAM; i++){
                    printf("\t\t\t\t\t\t       ");
                    for ( j = 0; j < TAM; j++, k++){
                        printf("%c ", mtz[i][j]);
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

                if(jogador == 0){

                    system("cls");
                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t==========================\n");
                    printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome1);
                    printf("\t\t\t\t\t\t==========================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            if(i == pl && j == pc) {
                                printf("_ ");
                            }
                            else {
                                printf("%c ", tab[i][j]);
                            }
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
                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                    printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            printf("%c ", memoria[i][j]);
                        }           
                        printf("\t\t\t\t\t\t\n");
                    }
                    
                    fflush(stdin);

                    tecla = getche();
                    if(tecla >= 'A' && tecla <= 'Z' ){
                        tecla += 32;
                    }
                    // CIMA
                    if(tecla == 119) {
                        if(pl > 0) pl--;
                    }
                    // BAIXO
                    else if(tecla == 115) {
                        if(pl < TAM-1) pl++;
                    }
                    // DIREITA
                    else if(tecla == 100) {
                        if(pc < TAM-1) pc++;
                    }
                        
                    // ESQUERDA
                    else if(tecla == 97) {
                        if(pc > 0) pc--;
                    }
                        
                    else if(tecla == ENTER) {
                        
                        if(tab[pl][pc] != '@'){//op invalida
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome1);
                            printf("\t\t\t\t\t\t==========================\n");
                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    if(i == pl && j == pc) {
                                        printf("_ ");
                                    }
                                    else {
                                        printf("%c ", tab[i][j]);
                                    }
                                }
                                printf("\t\t\t\t\t\t\n");
                            }
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t    Pocisao invalida!     \n", mtz[pl1][pc1]);
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                            printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                            fflush(stdin);
                            sleep(1);
                        }else{//op valida
                            if(jogada == 0){
                                pl1 = pl;
                                pc1 = pc;
                                tab[pl1][pc1] = memoria[pl1][pc1] = mtz[pl1][pc1];
                                system("cls");
                                printf("\n\n\n\n");
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome1);
                                printf("\t\t\t\t\t\t==========================\n");
                                for(i = 0; i < TAM; i++) {
                                    printf("\t\t\t\t\t\t       ");
                                    for(j = 0; j < TAM; j++) {
                                        if(i == pl && j == pc) {
                                            printf("_ ");
                                        }
                                        else {
                                            printf("%c ", tab[i][j]);
                                        }
                                    }
                                    printf("\t\t\t\t\t\t\n");
                                }
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t    [%c] Selecionado!     \n", mtz[pl1][pc1]);
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                                for(i = 0; i < TAM; i++) {
                                    printf("\t\t\t\t\t\t       ");
                                    for(j = 0; j < TAM; j++) {
                                        printf("%c ", memoria[i][j]);
                                    }           
                                    printf("\t\t\t\t\t\t\n");
                                }
                                fflush(stdin);
                                jogada++;
                            }else{//segunda jogada
                                pl2 = pl;
                                pc2 = pc;
                                tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2];

                                if(mtz[pl1][pc1] == mtz[pl2][pc2]){//acertou
                                    
                                    ponto1++;
                                    system("cls");
                                    printf("\n\n\n\n");
                                    printf("\t\t\t\t\t\t=========================\n");
                                    printf("\t\t\t\t\t\t    %s ACERTOU!        \n", nome1);
                                    printf("\t\t\t\t\t\t=========================\n");
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            if(i == pl && j == pc) {
                                                printf("_ ");
                                            }
                                            else {
                                                printf("%c ", tab[i][j]);
                                            }
                                        }
                                    printf("\t\t\t\t\t\t\n");
                                    }
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t [%c] e [%c] Selecionado!\n", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                    printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            printf("%c ", memoria[i][j]);
                                        }           
                                        printf("\t\t\t\t\t\t\n");
                                    }
                                    fflush(stdin);
                                }else{//errou
                                    system("cls");
                                    printf("\n\n\n\n");
                                    printf("\t\t\t\t\t\t=========================\n");
                                    printf("\t\t\t\t\t\t       %s ERROU!       \n", nome1);
                                    printf("\t\t\t\t\t\t=========================\n");
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                        
                                            printf("%c ", tab[i][j]);
                                            
                                        }
                                    printf("\t\t\t\t\t\t\n");
                                    }
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t [%c] e [%c] Selecionado!\n", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                    printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            printf("%c ", memoria[i][j]);
                                        }           
                                        printf("\t\t\t\t\t\t\n");
                                    }
                                    fflush(stdin);
                                    
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                }//errou
                                jogada--;
                                jogador--;
                            }//jogada 
                            getchar();
                            fflush(stdin);
                        }//op valida
                    }//enter
                    
                }else{// 2 jogador

                    system("cls");
                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t==========================\n");
                    printf("\t\t\t\t\t\t      VEZ DE MAQUINA      \n", nome1);
                    printf("\t\t\t\t\t\t==========================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            printf("%c ", tab[i][j]);
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
                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                    printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            printf("%c ", memoria[i][j]);
                        }           
                        printf("\t\t\t\t\t\t\n");
                    }
                    getchar();
                    fflush(stdin);
                    
                    
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
                        printf("\t\t\t\t\t\t      VEZ DE MAQUINA      \n");
                        printf("\t\t\t\t\t\t==========================\n");
                        for(i = 0; i < TAM; i++) {
                            printf("\t\t\t\t\t\t       ");
                            for(j = 0; j < TAM; j++) {
                                printf("%c ", tab[i][j]);
                            }           
                        printf("\t\t\t\t\t\t\n");
                        }
                        printf("\t\t\t\t\t\t==========================\n");
                        printf("\t\t\t\t\t\t     [%c] Selecionado!    \n", mtz[pl1][pc1]);
                        printf("\t\t\t\t\t\t==========================\n");
                        printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                        printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                        for(i = 0; i < TAM; i++) {
                            printf("\t\t\t\t\t\t       ");
                            for(j = 0; j < TAM; j++) {
                                printf("%c ", memoria[i][j]);
                            }           
                            printf("\t\t\t\t\t\t\n");
                        }
                        getchar();
                        fflush(stdin);
                        //sleep(2);
                        
                        jogada++;
                    }else{// segunda jogada
                        
                        //verifica se posição ja esta salva na memoria
                        for ( i = 0; i < TAM; i++){
                            for ( j = 0; j < TAM; j++, k++){
                                if (mtz[pl1][pc1] == memoria[i][j] && !(pl1 == i && pc1 == j)){
                                    sabe = 1;
                                    pl2 = i;
                                    pc2 = j;
                                    i = TAM;
                                    printf("\t\t\t\t\t\t sabe");
                                    getchar();
                                }
                            }
                        }  
                        if(sabe == 0){
                            printf("\t\t\t\t\t\t nao sabe");
                            getchar();
                        }
                    
                        
                        if(sabe == 1){
                            lembra = rand() % 2;
                            if (lembra == 1){
                                //memoria[pl1][pc1] = '#';
                                do{
                                    pl2 = rand() % 6; 
                                    pc2 = rand() % 6;
                                }while(tab[pl2][pc2] != '@' && !(pl2 == pl1 && pc2 == pc1));
                            }
                            sabe = 0;
                        }else{
                            do{
                                pl2 = rand() % 6; 
                                pc2 = rand() % 6;
                            }while(tab[pl2][pc2] != '@' && !(pl2 == pl1 && pc2 == pc1));
                        }

                        tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2]; //mostra

                        if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                            ponto2++;
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t    MAQUINA ACERTOU!      \n", nome1);
                            printf("\t\t\t\t\t\t==========================\n");
                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    printf("%c ", tab[i][j]);
                                }           
                            printf("\t\t\t\t\t\t\n");
                            }
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t [%c] e [%c] Selecionado! \n", mtz[pl1][pc1], mtz[pl2][pc2]);
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                            printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);

                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    printf("%c ", memoria[i][j]);
                                }           
                                printf("\t\t\t\t\t\t\n");
                            }
                                
                            fflush(stdin);
                            //sleep(2);

                            jogador++;
                        }else{
                                
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t     MAQUINA ERROU!       \n", nome1);
                            printf("\t\t\t\t\t\t==========================\n");
                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    printf("%c ", tab[i][j]);
                                }           
                            printf("\t\t\t\t\t\t\n");
                            }
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t [%c] e [%c] Selecionado! \n", mtz[pl1][pc1], mtz[pl2][pc2]);
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                            printf("\t\t\t\t\t\t - MAQUINA: %d             \n", ponto2);
                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    printf("%c ", memoria[i][j]);
                                }           
                                printf("\t\t\t\t\t\t\n");
                            }
                            
                            fflush(stdin);
                            //sleep(2);
                            tab[pl2][pc2] = '@';
                            tab[pl1][pc1] = '@';
                                
                            jogador++;  
                        }
                        printf("\n");
                        //sleep(2);
                        getchar();
                        fflush(stdin);
                            
                        jogada--; 
                    }//jogada     
                }// jogador
                terminar = ponto1 + ponto2;
                if(terminar == 18){
                    system ("cls");
                    if(ponto1 > ponto2 || ponto1 == 10){
                        printf("\t\t\t\t\t\t\n\n\n %s VENCEU!", nome1);
                    }else if(ponto2 > ponto1 || ponto2 == 10){
                        printf("\t\t\t\t\t\t\n\n\n MAQUINA VENCEU!");
                    }else
                        printf("\t\t\t\t\t\t\n\n\n EMPATE!");
                    sleep(3);
                    fim = 1;
                }
            }//jogo
                break;

        case 1:   
            geraNumerosAleat( MIN, MAX, letras, numElement);
            Agrupar(numElement, REPT, letras, grupo);
            embaralhaVetor(grupo, TAM * TAM);

            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t - Digite nome do primeiro jogador: ");

            //PEGA NOME DO PRIMEIRO PLAYER
            nome1 = malloc(1 * sizeof(char));
                
            fflush(stdin);
            
            do {
                c = getche();
                if(c >= 'a' && c <= 'z'){
                    c -= 32;
                }
                if(c != 13) {
                    nome1[pos] = c;
                    pos++;
                    nome1 = realloc(nome1, (pos+1) * sizeof(char));
                }
            }while(c != 13);
 
            nome1[pos] = '\0';

            //PEGA NOME DO SEGUNDO PLAYER
            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t - Digite nome do segundo jogador: ");
            
            nome2 = malloc(1 * sizeof(char));
                
            fflush(stdin);
            
            do {
                d = getche();
                if(d >= 'a' && d <= 'z'){
                    d -= 32;
                }
                if(d != 13) {
                    nome2[pos1] = d;
                    pos1++;
                    nome2 = realloc(nome2, (pos1+1) * sizeof(char));
                }
            }while(d != 13);
 
            nome2[pos1] = '\0';

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
                printf("\t\t\t\t\t\t     GAME DA MEMORIA     \n");
                printf("\t\t\t\t\t\t=========================\n");

                for(i = 0; i < TAM; i++) {
                    printf("\t\t\t\t\t\t       ");
                    for(j = 0; j < TAM; j++) {
                        printf("%c ", mtz[i][j]);
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

                if(jogador == 0){

                    system("cls");
                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t==========================\n");
                    printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome1);
                    printf("\t\t\t\t\t\t==========================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            if(i == pl && j == pc) {
                                printf("_ ");
                            }
                            else {
                                printf("%c ", tab[i][j]);
                            }
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
                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            printf("%c ", memoria[i][j]);
                        }           
                        printf("\t\t\t\t\t\t\n");
                    }
                    
                    fflush(stdin);

                    tecla = getche();
                    if(tecla >= 'A' && tecla <= 'Z' ){
                        tecla += 32;
                    }
                    // CIMA
                    if(tecla == 119) {
                        if(pl > 0) pl--;
                    }
                    // BAIXO
                    else if(tecla == 115) {
                        if(pl < TAM-1) pl++;
                    }
                    // DIREITA
                    else if(tecla == 100) {
                        if(pc < TAM-1) pc++;
                    }
                        
                    // ESQUERDA
                    else if(tecla == 97) {
                        if(pc > 0) pc--;
                    }
                        
                    else if(tecla == ENTER) {
                        
                        if(tab[pl][pc] != '@'){
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome1);
                            printf("\t\t\t\t\t\t==========================\n");
                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    if(i == pl && j == pc) {
                                        printf("_ ");
                                    }
                                    else {
                                        printf("%c ", tab[i][j]);
                                    }
                                }
                                printf("\t\t\t\t\t\t\n");
                            }
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t    Pocisao invalida!     \n", mtz[pl1][pc1]);
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t - %s: %d                 \n", nome1, ponto1);
                            printf("\t\t\t\t\t\t - %s: %d                \n", nome2, ponto2);
                            fflush(stdin);
                            sleep(1);
                        }else{
                            tab[pl][pc] = memoria[pl][pc] = mtz[pl][pc];
                            if(jogada == 0){
                                pl1 = pl;
                                pc1 = pc;
                                system("cls");
                                printf("\n\n\n\n");
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome1);
                                printf("\t\t\t\t\t\t==========================\n");
                                for(i = 0; i < TAM; i++) {
                                    printf("\t\t\t\t\t\t       ");
                                    for(j = 0; j < TAM; j++) {
                                        if(i == pl && j == pc) {
                                            printf("_ ");
                                        }
                                        else {
                                            printf("%c ", tab[i][j]);
                                        }
                                    }
                                    printf("\t\t\t\t\t\t\n");
                                }
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t    [%c] Selecionado!     \n", mtz[pl1][pc1]);
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                                for(i = 0; i < TAM; i++) {
                                    printf("\t\t\t\t\t\t       ");
                                    for(j = 0; j < TAM; j++) {
                                        printf("%c ", memoria[i][j]);
                                    }           
                                    printf("\t\t\t\t\t\t\n");
                                }
                                
                                fflush(stdin);
                                jogada++;
                            }else{
                                pl2 = pl;
                                pc2 = pc;
                                tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2];
                                if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                                    
                                    ponto1++;
                                    system("cls");
                                    printf("\n\n\n\n");
                                    printf("\t\t\t\t\t\t=========================\n");
                                    printf("\t\t\t\t\t\t    %s ACERTOU!        \n", nome1);
                                    printf("\t\t\t\t\t\t=========================\n");
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            if(i == pl && j == pc) {
                                                printf("_ ");
                                            }
                                            else {
                                                printf("%c ", tab[i][j]);
                                            }
                                        }
                                    printf("\t\t\t\t\t\t\n");
                                    }
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t [%c] e [%c] Selecionado!\n", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            printf("%c ", memoria[i][j]);
                                        }           
                                        printf("\t\t\t\t\t\t\n");
                                    }
                                    fflush(stdin);
                                }else{
                                    system("cls");
                                    printf("\n\n\n\n");
                                    printf("\t\t\t\t\t\t=========================\n");
                                    printf("\t\t\t\t\t\t       %s ERROU!       \n", nome1);
                                    printf("\t\t\t\t\t\t=========================\n");
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                        
                                            printf("%c ", tab[i][j]);
                                            
                                        }
                                    printf("\t\t\t\t\t\t\n");
                                    }
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t [%c] e [%c] Selecionado!\n", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            printf("%c ", memoria[i][j]);
                                        }           
                                        printf("\t\t\t\t\t\t\n");
                                    }
                                    
                                    fflush(stdin);
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                }
                                jogada--;
                                jogador++;
                            }
                            getchar();
                            fflush(stdin);
                        }
                        
                    }
                    
                }else{// 2 jogador

                    system("cls");
                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t==========================\n");
                    printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome2);
                    printf("\t\t\t\t\t\t==========================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            if(i == pl && j == pc) {
                                printf("_ ");
                            }
                            else {
                                printf("%c ", tab[i][j]);
                            }
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
                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                    for(i = 0; i < TAM; i++) {
                        printf("\t\t\t\t\t\t       ");
                        for(j = 0; j < TAM; j++) {
                            printf("%c ", memoria[i][j]);
                        }           
                        printf("\t\t\t\t\t\t\n");
                    }
                    
                    fflush(stdin);

                    tecla = getche();
                    if(tecla >= 'A' && tecla <= 'Z' ){
                        tecla += 32;
                    }
                    // CIMA
                    if(tecla == 119) {
                        if(pl > 0) pl--;
                    }
                    // BAIXO
                    else if(tecla == 115) {
                        if(pl < TAM-1) pl++;
                    }
                    // DIREITA
                    else if(tecla == 100) {
                        if(pc < TAM-1) pc++;
                    }
                        
                    // ESQUERDA
                    else if(tecla == 97) {
                        if(pc > 0) pc--;
                    }
                        
                    else if(tecla == ENTER) {
                        
                        if(tab[pl][pc] != '@'){
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome2);
                            printf("\t\t\t\t\t\t==========================\n");
                            for(i = 0; i < TAM; i++) {
                                printf("\t\t\t\t\t\t       ");
                                for(j = 0; j < TAM; j++) {
                                    if(i == pl && j == pc) {
                                        printf("_ ");
                                    }
                                    else {
                                        printf("%c ", tab[i][j]);
                                    }
                                }
                                printf("\t\t\t\t\t\t\n");
                            }
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t    Pocisao invalida!     \n", mtz[pl1][pc1]);
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t - %s: %d                 \n", nome1, ponto1);
                            printf("\t\t\t\t\t\t - %s: %d                \n", nome2, ponto2);
                            fflush(stdin);
                            sleep(1);
                        }else{
                            if(jogada == 0){
                                pl1 = pl;
                                pc1 = pc;
                                tab[pl1][pc1] = memoria[pl1][pc1] = mtz[pl1][pc1];
                                system("cls");
                                printf("\n\n\n\n");
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t     VEZ DE %s            \n", nome2);
                                printf("\t\t\t\t\t\t==========================\n");
                                for(i = 0; i < TAM; i++) {
                                    printf("\t\t\t\t\t\t       ");
                                    for(j = 0; j < TAM; j++) {
                                        if(i == pl && j == pc) {
                                            printf("_ ");
                                        }
                                        else {
                                            printf("%c ", tab[i][j]);
                                        }
                                    }
                                    printf("\t\t\t\t\t\t\n");
                                }
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t    [%c] Selecionado!     \n", mtz[pl1][pc1]);
                                printf("\t\t\t\t\t\t==========================\n");
                                printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                                for(i = 0; i < TAM; i++) {
                                    printf("\t\t\t\t\t\t       ");
                                    for(j = 0; j < TAM; j++) {
                                        printf("%c ", memoria[i][j]);
                                    }           
                                    printf("\t\t\t\t\t\t\n");
                                }
                                
                                fflush(stdin);
                                jogada++;
                            }else{
                                pl2 = pl;
                                pc2 = pc;
                                tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2];

                                if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                                    
                                    ponto2++;
                                    system("cls");
                                    printf("\n\n\n\n");
                                    printf("\t\t\t\t\t\t=========================\n");
                                    printf("\t\t\t\t\t\t    %s ACERTOU!        \n", nome2);
                                    printf("\t\t\t\t\t\t=========================\n");
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            if(i == pl && j == pc) {
                                                printf("_ ");
                                            }
                                            else {
                                                printf("%c ", tab[i][j]);
                                            }
                                        }
                                    printf("\t\t\t\t\t\t\n");
                                    }
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t [%c] e [%c] Selecionado!\n", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t - %s: %d                  \n", nome1, ponto1);
                                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            printf("%c ", memoria[i][j]);
                                        }           
                                        printf("\t\t\t\t\t\t\n");
                                    }
                                    fflush(stdin);
                                }else{
                                    system("cls");
                                    printf("\n\n\n\n");
                                    printf("\t\t\t\t\t\t=========================\n");
                                    printf("\t\t\t\t\t\t       %s ERROU!       \n", nome2);
                                    printf("\t\t\t\t\t\t=========================\n");
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                        
                                            printf("%c ", tab[i][j]);
                                            
                                        }
                                    printf("\t\t\t\t\t\t\n");
                                    }
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t [%c] e [%c] Selecionado! \n", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    printf("\t\t\t\t\t\t==========================\n");
                                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome1, ponto1);
                                    printf("\t\t\t\t\t\t - %s: %d                 \n", nome2, ponto2);
                                    for(i = 0; i < TAM; i++) {
                                        printf("\t\t\t\t\t\t       ");
                                        for(j = 0; j < TAM; j++) {
                                            printf("%c ", memoria[i][j]);
                                        }           
                                        printf("\t\t\t\t\t\t\n");
                                    }
                                    
                                    fflush(stdin);
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                    
                                }
                                jogada--;
                                jogador--;
                            }
                            getchar();
                            fflush(stdin);
                        }
                        
                    }     
                }// jogador
                terminar = ponto1 + ponto2;
                if(terminar == 18){
                    system ("cls");
                    printf("\n\n\n\n");
                    if(ponto1 > ponto2 ){
                        printf("\t\t\t\t\t\t\t %s VENCEU!", nome1);
                    }else if(ponto2 > ponto1){
                        printf("\t\t\t\t\t\t\t %s VENCEU!", nome2);
                    }else
                        printf("\t\t\t\t\t\t\t EMPATE!");
                    
                    fim = 1;
                }
            }//jogo
                break;

        case 2:
            return 0;
            break;
    }
    printf("\n\n\n\n\n");
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
