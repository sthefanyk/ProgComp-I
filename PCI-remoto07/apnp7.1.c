#include <stdio.h>

#define CIRCLE 0
#define CROSS 1

int main(){

    int jogador, jogada, local, vencedor = 0;
    char map[9], cont;
    

    //do{
        //inicializa a tabela
        for(local = 0; local < 9; local++){
            map[local] = ' ';
        }
        jogador = 1;
        jogada = 0;
        
        
        do{
            //system("cls");  
            printf("======================================\n");
            printf("=========== JOGO DA VELHA ============\n");
            printf("======================================\n");
            printf("=== Tabuleiro ====== Jogo da Velha ===\n\n");

            printf("    1 | 2 | 3           %c | %c |%c     \n", map[0], map[1], map[2]);
            printf("   ___|___|___          __|___|__     \n");
            printf("    4 | 5 | 6           %c | %c |%c     \n", map[3], map[4], map[5]);
            printf("   ___|___|___          __|___|__     \n");
            printf("    7 | 8 | 9           %c | %c |%c     \n", map[6], map[7], map[8]);
            printf("      |   |               |   |       \n");

            printf("======================================\n");
            printf(" Jogador 01-> [O]    Jogador 02-> [X] \n");
            printf("======================================\n\n");

            printf("JOGADOR 0%i - Escolha sua jogada: ", jogador);
            fflush(stdin);
            scanf("%i", &local);

            //Verifica se a jogada é valida
            if(map[local] == ' ' && local >= 0 && local < 10){

                //Define local
                if(jogador == 1){
                    map[local-1] = 'O';
                }else{
                    map[local-1] = 'X';
                }

                printf("%i", local);
                //Define vencedor
                if(map[0] == 'O' && map[3] == 'O' && map[6] == 'O'){
                    vencedor = jogador;
                }else if(map[1] == 'O' && map[4] == 'O' && map[7] == 'O'){
                    vencedor = jogador;
                }else if(map[2] == 'O' && map[5] == 'O' && map[8] == 'O'){
                    vencedor = jogador;
                }else if(map[0] == 'O' && map[1] == 'O' && map[2] == 'O'){
                    vencedor = jogador;
                }else if(map[3] == 'O' && map[4] == 'O' && map[5] == 'O'){
                    vencedor = jogador;
                }else if(map[6] == 'O' && map[7] == 'O' && map[8] == 'O'){
                    vencedor = jogador;
                }else if(map[0] == 'O' && map[4] == 'O' && map[8] == 'O'){
                    vencedor = jogador;
                }else if(map[2] == 'O' && map[4] == 'O' && map[6] == 'O'){
                    vencedor = jogador;
                }else if(map[0] == 'X' && map[3] == 'X' && map[6] == 'X'){
                    vencedor = jogador;
                }else if(map[1] == 'X' && map[4] == 'X' && map[7] == 'X'){
                    vencedor = jogador;
                }else if(map[2] == 'X' && map[5] == 'X' && map[8] == 'X'){
                    vencedor = jogador;
                }else if(map[0] == 'X' && map[1] == 'X' && map[2] == 'X'){
                    vencedor = jogador;
                }else if(map[3] == 'X' && map[4] == 'X' && map[5] == 'X'){
                    vencedor = jogador;
                }else if(map[6] == 'X' && map[7] == 'X' && map[8] == 'X'){
                    vencedor = jogador;
                }else if(map[0] == 'X' && map[4] == 'X' && map[8] == 'X'){
                    vencedor = jogador;
                }else if(map[2] == 'X' && map[4] == 'X' && map[6] == 'X'){
                    vencedor = jogador;
                }else if(jogada == 8){
                    vencedor = 3;
                }
                printf("\n\n%i\n\n", vencedor);
                
                //Alterna jogador
                if(jogador == 1){
                    jogador = 2;
                }else{
                    jogador = 1;
                }
            }else{
                printf("Jogada Invalida");
            }

            jogada++;

        }while(jogada < 9 || vencedor == 0);
        
        if(vencedor != 3){
            printf("- Parabens jogador 0%i!", vencedor);
        }else
            printf("- Nao houve vencedor!");
        
        /*printf("\n\nDeseja jogar novamente (s) ou (n): ");
        scanf("%c", &cont);

    }while(cont == 's' || cont == 'S');*/
    return 0;
}
