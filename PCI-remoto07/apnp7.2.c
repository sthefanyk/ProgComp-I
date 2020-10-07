#include <stdio.h>

int main(){

    int final, jogador;
    char jogar, jogada;
    char a, b, c, d, e, f, g, h, i;
    

    jogar = 's';
    while(jogar == 's' || jogar == 'S') {

        jogador = 1;
        final = 0;
        a = b = c = d = e = f = g = h = i = ' ';

        do{
            system("cls");  
            printf("======================================\n");
            printf("=========== JOGO DA VELHA ============\n");
            printf("======================================\n");
            printf("=== Tabuleiro ====== Jogo da Velha ===\n\n");

            printf("    a | b | c           %c | %c |%c     \n", a, b, c);
            printf("   ___|___|___          __|___|__     \n");
            printf("    d | e | f           %c | %c |%c     \n", d, e, f);
            printf("   ___|___|___          __|___|__     \n");
            printf("    g | h | i           %c | %c |%c     \n", g, h, i);
            printf("      |   |               |   |       \n");

            printf("======================================\n");
            printf(" Jogador 01-> [O]    Jogador 02-> [X] \n");
            printf("======================================\n\n");

            if(jogador == 1)
                printf("JOGADOR 01 - Escolha uma jogada: ");
                fflush(stdin);
                scanf("%c", &jogada);

                // verifica jogada
            
                switch(jogada){

                    case 'a':
                        a = 'O';
                        break;

                    case 'b':
                        b = 'O';
                        break;

                    case 'c':
                        c = 'O';
                        break;

                    case 'e':
                        e = 'O';
                        break;

                    case 'f':
                        f = 'O';
                        break;

                    case 'g':
                        g = 'O';
                        break;

                    case 'h':
                        h = 'O';
                        break;

                    case 'i':
                        i = 'O';
                        break;
                }
                jogador = 2;

            }else{

                printf("JOGADOR 02 - Escolha uma jogada: ");
                fflush(stdin);
                scanf("%c", &jogada);

                //verifica jogada
            
                switch(jogada){

                    case 'a':
                        a = 'X';
                        break;

                    case 'b':
                        b = 'X';
                        break;

                    case 'c':
                        c = 'X';
                        break;

                    case 'e':
                        e = 'X';
                        break;

                    case 'f':
                        f = 'X';
                        break;

                    case 'g':
                        g = 'X';
                        break;

                    case 'h':
                        h = 'X';
                        break;

                    case 'i':
                        i = 'X';
                        break;
                }
                jogador = 1;
            }
        }while(final != 1);

        printf("Quer jogar novamente (s) ou (n)? ");
        fflush(stdin);
        scanf("%c", &jogar);
        system("cls");         
    }
    printf("\n\n");
    return 0;
}
