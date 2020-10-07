/*
CRIADO POR STHEFANY KIMBERLY VITORIA DA SILVA MENDES (ALUNA DE TADS20)
DIRETORES CRIATIVO POR GIL EDUARDO DE ANDRADE, DIEGO JONATHAN HOSS,
RUHAN PHELIPE DA SILVA MENDES (ALUNO DE INFO18).
*/
#include "jm.h"

int main(){

    int letras[NUM_ELEMENT], grupo[TAM * TAM];
    int i = 0, j, k = 0, t;
    int fim, terminar, pc1, pl1, pc2, pl2, tecla, lembra;
    int  ponto1 = 0, ponto2 = 0, sabe = 0, jogador = 0, jogada = 0;
    int pc = 0, pl = 0, pos = 0, pos1 = 0;
    char mtz[TAM][TAM], tab[TAM][TAM], memoria[TAM][TAM], op[2];
    char *nome1, *nome2, c, d;

    op[0] = '>';
    op[1] = op[2] = ' ';
  
    // SELECIONA QUANTOS JOGADORES
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
        case 0:         
            geraNumerosAleat( MIN, MAX, letras, NUM_ELEMENT);
            Agrupar(NUM_ELEMENT, REPT, letras, grupo);
            embaralhaVetor(grupo, TAM * TAM);

            //PEGA NOME DO PLAYER
            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t - Digite seu nome: ");

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

            nome2 = malloc(4*sizeof(char));

            nome2[0] = 'C';
            nome2[1] = 'P';
            nome2[2] = 'U';
            nome2[3] = '\0';


            // POVOA MATRIZES
            for ( i = 0; i < TAM; i++){
                for ( j = 0; j < TAM; j++, k++){
                    mtz[i][j] = grupo[k];
                    tab[i][j] = '@';
                    memoria[i][j] = '#';
                }  
            }            
              
            // TEMPO PARA MEMORIZAR
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
                fflush(stdout);
                sleep(1);
                
            }
            
            fim = pc1 = pl1 = 0;
            //INICIA JOGO
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
                    printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);
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
                            printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);
                            fflush(stdout);
                            sleep(1);
                        }else{
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
                                printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);
                                jogada++;
                            }else{//SEGUNDA JOGADA
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
                                    printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);
                                    
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
                                    printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);

                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                }
                                jogada--;
                                jogador--;
                            }//jogada 
                            fflush(stdin);
                            getchar();
                        }
                    }
                    
                }else{// SEGUNDO JOGADOR

                    system("cls");
                    printf("\n\n\n\n");
                    printf("\t\t\t\t\t\t==========================\n");
                    printf("\t\t\t\t\t\t      VEZ DE %s      \n", nome2);
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
                    printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);
                    fflush(stdin);
                    getchar();
                    
                    if(jogada == 0){
                        do{
                            pl1 = rand() % 6; 
                            pc1 = rand() % 6;
                        }while(tab[pl1][pc1] != '@');

                        tab[pl1][pc1] = memoria[pl1][pc1] = mtz[pl1][pc1];
                        system("cls");
                        printf("\n\n\n\n");
                        printf("\t\t\t\t\t\t==========================\n");
                        printf("\t\t\t\t\t\t      VEZ DE %s      \n", nome2);
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
                        printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);
                        fflush(stdin);
                        getchar();
                        
                        jogada++;
                    }else{// SEGUNDA JOGADA
                        
                        //verifica se posição ja esta salva na memoria
                        for ( i = 0; i < TAM; i++){
                            for ( j = 0; j < TAM; j++, k++){
                                if (mtz[pl1][pc1] == memoria[i][j] && !(pl1 == i && pc1 == j)){
                                    sabe = 1;
                                    pl2 = i;
                                    pc2 = j;
                                    i = TAM;
                                    getchar();
                                }
                            }
                        }
                        
                        if(sabe == 1){
                            lembra = rand() % 2;
                            if (lembra == 1){
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

                        tab[pl2][pc2] = memoria[pl2][pc2] = mtz[pl2][pc2]; 

                        if(mtz[pl1][pc1] == mtz[pl2][pc2]){
                            ponto2++;
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t    %s ACERTOU!      \n", nome2);
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
                            printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);

                            jogador++;
                        }else{
                                
                            system("cls");
                            printf("\n\n\n\n");
                            printf("\t\t\t\t\t\t==========================\n");
                            printf("\t\t\t\t\t\t     %s ERROU!       \n", nome2);
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
                            printf("\t\t\t\t\t\t - %s: %d             \n", nome2, ponto2);

                            tab[pl2][pc2] = '@';
                            tab[pl1][pc1] = '@';
                                
                            jogador++;  
                        }
                        printf("\n");
                        fflush(stdin);
                        getchar();
                        jogada--; 
                    }    
                }
                terminar = ponto1 + ponto2;
                if(terminar == 18 || ponto1 == 10 || ponto2 == 10){
                    system ("cls");
                    printf("\n\n\n\n");
                    if(ponto1 > ponto2 ){
                        if (ponto1 == 10 && terminar != 18)
                            printf("\t\t\t\t\t SEM CHANCE DE VIRADA PARA %s\n\n", nome2);
                        printf("\t\t\t\t\t\t %s VENCEU!", nome1);
                    }else if(ponto2 > ponto1){
                        if (ponto2 == 10 && terminar != 18)
                            printf("\t\t\t\t\t\t SEM CHANCE DE VIRADA PARA %s\n\n", nome1);
                        printf("\t\t\t\t\t\t\t %s VENCEU!", nome2);
                    }else
                        printf("\t\t\t\t\t\t\t EMPATE!");
                    getchar();
                    fim = 1;
                }
            }
            break;

        case 1:   
            geraNumerosAleat( MIN, MAX, letras, NUM_ELEMENT);
            Agrupar(NUM_ELEMENT, REPT, letras, grupo);
            embaralhaVetor(grupo, TAM * TAM);

            //PEGA NOME DO PRIMEIRO PLAYER
            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t - Digite nome do primeiro jogador: ");

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
            
            // POVOA MATRIZES
            for ( i = 0; i < TAM; i++){
                for ( j = 0; j < TAM; j++, k++){
                    mtz[i][j] = grupo[k];
                    tab[i][j] = '@';
                    memoria[i][j] = '#';
                }  
            }            
              
            // TEMPO PARA MEMORIZAR
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
                fflush(stdout);
                sleep(1);
                
            }
            
            fim = pc1 = pl1 = 0;
            //INICIA JOGO
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
                            fflush(stdout);
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
                                    
                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';

                                }
                                jogada--;
                                jogador++;
                            }
                            fflush(stdin);
                            getchar();
                        }
                        
                    }
                    
                }else{// SEGUNDO JOGADOR

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
                            fflush(stdout);
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

                                    tab[pl1][pc1] = '@';
                                    tab[pl2][pc2] = '@';
                                    
                                }
                                jogada--;
                                jogador--;
                            }
                            fflush(stdin);
                            getchar();
                        }
                        
                    }     
                }
                terminar = ponto1 + ponto2;
                if(terminar == 18 || ponto1 == 10 || ponto2 == 10){
                    system ("cls");
                    printf("\n\n\n\n");
                    if(ponto1 > ponto2 ){
                        if (ponto1 == 10)
                            printf("\t\t\t\t\t SEM CHANCE DE VIRADA PARA %s\n\n", nome2);
                        printf("\t\t\t\t\t\t %s VENCEU!", nome1);
                    }else if(ponto2 > ponto1){
                        if (ponto2 == 10)
                            printf("\t\t\t\t\t\t SEM CHANCE DE VIRADA PARA %s\n\n", nome1);
                        printf("\t\t\t\t\t\t\t %s VENCEU!", nome2);
                    }else
                        printf("\t\t\t\t\t\t\t EMPATE!");
                    getchar();
                    fim = 1;
                }
            }
            break;

        case 2:
            return 0;
            break;
    }
    printf("\n\n\n\n\n");
    return 0;
}