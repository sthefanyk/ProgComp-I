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

    op[0] = '>';
    op[1] = op[2] = ' ';
  
    // seleciona contra quem quer jogar
    do{
        system("cls");
        printf("===================\n");
        printf("=== %c1) VS CPU ===\n", op[0]);
        printf("=== %c2) VS P2 ====\n", op[1]);
        printf("=== %c3) SAIR =====\n", op[2]);
        printf("===================\n");

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
            if(i < 3){
                op[i] = ' ';
                i++;
                op[i] = '>';
            }
        }

    }while(tecla != ENTER);

    switch(i){
        case 0:         
            geraNumerosAleat( MIN, MAX, letras, numElement);
            Agrupar(numElement, REPT, letras, grupo);
            embaralhaVetor(grupo, TAM * TAM);

            system("cls");
            printf("- Digite o nome do jogador: ");
            
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
                    memoria[i][j] = '#';   
                }  
            }
            
            fim = pc1 = pl1 = 0;

            while(fim == 0) {

                if(jogador == 0){

                    system("cls");

                    printf("===================\n");
                    printf("= GAME DA MEMORIA =\n");
                    printf("===================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("   ");
                        for(j = 0; j < TAM; j++) {
                            printf(" %c", tab[i][j]);
                        }           
                        printf("\n");
                    }

                    printf("\n\n");

                    printf("===================\n");
                    printf("    segundo(s)   \n");
                    printf("===================\n");
                    fflush(stdin);
                    
                    //verifica se é a primeira ou a segunda jogada
                    if(jogada == 0){
                        //seleciona posição aleatória
                        do{
                            pl1 = rand() % 6; 
                            pc1 = rand() % 6;
                        }while(tab[pl1][pc1] != '@');

                        tab[pl1][pc1] = memoria[pl1][pc1] = mtz[pl1][pc1];
                        
                        printf("\n [%c] Selecionado!", mtz[pl1][pc1]);
                        fflush(stdin);
                        sleep(1);
                        jogada++;
                    }else{
                        
                        //verifica se posição ja esta salva na memoria
                        for ( i = 0; i < TAM; i++){
                            for ( j = 0; j < TAM; j++, k++){
                                if (mtz[pl1][pc1] == memoria[i][j]){
                                    if (pl1 == i && pc1 == j){
                                        mesma = 1;
                                    }
                                    if (mesma == 0){
                                        sabe = 1;
                                        pl2 = i;
                                        pc2 = j;
                                        i = TAM;
                                        printf("(%c)", mtz[pl2][pc2]);
                                    }
                                    mesma = 0;
                                }
                            }  
                        }
                        
                        
                        if(sabe == 1){
                        
                            lembra = rand() % 2;
                            if (lembra == 1){
                                tab[pl2][pc2] = mtz[pl2][pc2];//mostra
                            }else{
                                memoria[pl1][pc1] = '#';
                                do{
                                    pl2 = rand() % 6; 
                                    pc2 = rand() % 6;
                                }while(tab[pl2][pc2] != '@' && pl2 == pl1 && pc2 == pc1);
                                tab[pl2][pc2] = mtz[pl2][pc2];//mostra
                            }
                            
                            sabe = 0;
                        }else{
                            do{
                                pl2 = rand() % 6; 
                                pc2 = rand() % 6;
                            }while(tab[pl2][pc2] != '@' && pl2 == pl1 && pc2 == pc1);
                            tab[pl2][pc2] = mtz[pl2][pc2]; //mostra

                            system("cls");

                            printf("===================\n");
                            printf("= GAME DA MEMORIA =\n");
                            printf("===================\n");
                            for(i = 0; i < TAM; i++) {
                                printf("   ");
                                for(j = 0; j < TAM; j++) {
                                    printf(" %c", tab[i][j]);
                                }           
                                printf("\n");
                            }

                            printf("===================\n");
                            printf("    segundo(s)   \n");
                            printf("===================\n");
                            fflush(stdin);
                        }

                        if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                            printf("    [ACERTOU!]");
                            printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                            jogador++;
                            sleep(1);
                        }else{
                            tab[pl2][pc2] = '@';
                            tab[pl1][pc1] = '@';
                            printf("     [ERROU!]");
                            printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                            jogador++;
                            sleep(1);    
                        }
                        printf("\n");
                        sleep(1);
                        fflush(stdin);
                        
                        jogada--;      
                    }

                }else if(jogador == 1){
                    system("cls");

                    printf("===================\n");
                    printf("= GAME DA MEMORIA =\n");
                    printf("===================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("   ");
                        for(j = 0; j < TAM; j++) {
                            if(i == pl && j == pc) {
                                printf("_ ");
                            }
                            else {
                                printf("%c ", tab[i][j]);
                            }
                        }
                        printf("\n");
                    }
                    printf("===================\n");
                    printf("    segundo(s)   \n");
                    printf("===================\n");
                    fflush(stdin);

                    tecla = getche();
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
                            printf("Pocisao invalida!");
                            sleep(1);
                        }else{
                            tab[pl][pc] = mtz[pl][pc];
                            if(jogada == 0){
                                pl1 = pl;
                                pc1 = pc;
                                printf("\n [%c] Selecionado!", mtz[pl1][pc1]);
                                jogada++;
                            }else{
                                pl2 = pl;
                                pc2 = pc;
                                jogada--;
                                
                                if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                                    printf("    [ %s ACERTOU!]", nome1);
                                    ponto++;
                                    jogador--;
                                    printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                                }else{
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                    printf("     [ %s ERROU!]", nome1);
                                    printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    jogador--;
                                }
                                
                            }
                            
                            fflush(stdin);
                            getchar();
                        }
                    }
                    
                }
            }
            printf("\n\n");
            break;

        case 1:   
            geraNumerosAleat( MIN, MAX, letras, numElement);
            Agrupar(numElement, REPT, letras, grupo);
            embaralhaVetor(grupo, TAM * TAM);

            //monta matriz
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
                    memoria[i][j] = '#';   
                }  
            }
            
            fim = pc1 = pl1 = 0;

            while(fim == 0) {

                if(jogador == 0){
                    system("cls");

                    printf("===================\n");
                    printf("= GAME DA MEMORIA =\n");
                    printf("===================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("   ");
                        for(j = 0; j < TAM; j++) {
                            if(i == pl && j == pc) {
                                printf("_ ");
                            }
                            else {
                                printf("%c ", tab[i][j]);
                            }
                        }
                        printf("\n");
                    }
                    printf("===================\n");
                    printf("    segundo(s)   \n");
                    printf("===================\n");
                    fflush(stdin);


                    tecla = getche();
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
                            printf("Pocisao invalida!");
                            sleep(1);
                        }else{
                            tab[pl][pc] = mtz[pl][pc];
                            if(jogada == 0){
                                pl1 = pl;
                                pc1 = pc;
                                jogada++;
                            }else if(jogada == 1){
                                pl2 = pl;
                                pc2 = pc;
                                jogada--;
                                
                                if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                                    printf("    [PLAYER 1 ACERTOU!]");
                                    ponto++;
                                    jogador++;
                                    printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                                }else{
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                    printf("     [PLAYER 1 ERROU!]");
                                    printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    jogador++;
                                }
                                
                            }
                            
                            fflush(stdin);
                            getchar();
                        }
                    }
                    
                }else if(jogador == 1){
                    system("cls");

                    printf("===================\n");
                    printf("= GAME DA MEMORIA =\n");
                    printf("===================\n");
                    for(i = 0; i < TAM; i++) {
                        printf("   ");
                        for(j = 0; j < TAM; j++) {
                            if(i == pl && j == pc) {
                                printf("_ ");
                            }
                            else {
                                printf("%c ", tab[i][j]);
                            }
                        }
                        printf("\n");
                    }
                    printf("===================\n");
                    printf("    segundo(s)   \n");
                    printf("===================\n");
                    fflush(stdin);


                    tecla = getche();
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
                            printf("Pocisao invalida!");
                            sleep(1);
                        }else{
                            tab[pl][pc] = mtz[pl][pc];
                            if(jogada == 0){
                                pl1 = pl;
                                pc1 = pc;
                                jogada++;
                            }else if(jogada == 1){
                                pl2 = pl;
                                pc2 = pc;
                                jogada--;
                                
                                if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                                    printf("    [PLAYER 2 ACERTOU!]");
                                    ponto++;
                                    jogador--;
                                    printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                                }else{
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                    printf("     [PLAYER 2 ERROU!]");
                                    printf("\n [%c] e [%c] Selecionado!", mtz[pl1][pc1], mtz[pl2][pc2]);
                                    jogador--;
                                }
                                
                            }
                            
                            fflush(stdin);
                            getchar();
                        }
                    }
                    
                }
            }
            printf("\n\n");
            break;

        case 2:
            return 0;
            break;
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
