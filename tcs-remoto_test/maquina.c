#include <stdio.h>

#define TAM 6

int main(){

    int i, j, k, lin, col;
    char tab[TAM][TAM], mtz[TAM][TAM], memoria[TAM][TAM];
    int fim = 0, pc, pl, plc, pcc, sabe = 0, k = 0;
    int jogada = 0 , comp[2], lembra;

    for ( i = 0; i < TAM; i++){
        for ( j = 0; j < TAM; j++, k++){
            tab[i][j] = '@';   
        }  
    }
    for ( i = 0; i < TAM; i++){
        for ( j = 0; j < TAM; j++, k++){
            mtz[i][j] = '#';   
        }  
    }
    for ( i = 0; i < TAM; i++){
        for ( j = 0; j < TAM; j++, k++){
            memoria[i][j] = 0;   
        }  
    }

    do{
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
		

        
        //verifica se é a primeira ou a segunda jogada
        if(jogada == 0){
            //seleciona posição aleatória
            do{
                pl = rand() % 7; 
                pc = rand() % 7;
            }while(tab[pl][pc] != '@');

            tab[pl][pc] = memoria[pl][pc] = comp[0] = mtz[pl][pc];
            plc = pl;
            pcc = pc;
            jogada++;
        }else if(jogada == 1){
            //verifica se posição ja esta salva na memoria
            for ( i = 0; i < TAM; i++){
                for ( j = 0; j < TAM; j++, k++){
                    if(mtz[plc][pcc] == memoria[i][j]){
                        if (i != )
                        {
                            /* code */
                        }
                        
                        sabe++;
                        if (sabe == 1){
                            lembra = rand() % 2;
                            if (lembra == 1){
                                tab[i][j] = mtz[i][j];
                                comp[1] = mtz[i][j];
                                i = TAM;
                            }else{
                                memoria[i][j] = memoria[plc][pcc] = 0;
                                do{
                                    pl = rand() % 7; 
                                    pc = rand() % 7;
                                }while(tab[pl][pc] != '@');
                                tab[pl][pc] = mtz[pl][pc];
                                comp[1] = mtz[pl][pc];
                            }
                            sabe--;
                            k++;
                        }
                    }else if(i = 5 && k != 0){
                        k--;
                        do{
                            pl = rand() % 7; 
                            pc = rand() % 7;
                        }while(tab[pl][pc] != '@');
                        tab[pl][pc] = memoria[pl][pc] = mtz[pl][pc];
                        comp[1] = mtz[pl][pc];
                    }
                }  
            }
            if(comp[0] != comp[1]){
                tab[plc][pcc] = '@';
                    tab[pl][pc] = '@';
                    printf("     [ERROU!]");
            }else if(comp[0] == comp[1]){
                printf("    [ACERTOU!]");
                sleep(2);
            }
            jogada--;      
        }

            
    }while(fim == 0);
}
