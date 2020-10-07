#include <stdio.h>

int main(){

    int op;

    do{
        system("cls");

        printf("\n\n================================\n");
        printf("=== 1) Saque ===================\n");
        printf("=== 2) Deposito ================\n");
        printf("=== 3) Transferencia ===========\n");
        printf("=== 4) Extrato =================\n");
        printf("=== 5) Sair ====================\n");
        printf("================================\n");
        printf("> ");
        fflush(stdin);
        scanf("%i", &op);

        if(op == 1){
            printf("\nOpcao escolhida: Saque ");
        }else if(op == 2){
            printf("\nOpcao escolhida: Deposito ");
        }else if(op == 3){
            printf("\nOpcao escolhida: Transferencia ");
        }else if(op == 4){
            printf("\nOpcao escolhida: Extrato ");
        }else if(op == 5){
            printf("\nOpcao escolhida: Sair ");
        }else{
            printf("\nOpcao invalida");
        }

        fflush(stdin);
        getchar();

    }while(op != 5 && op > 0 && op < 6 );
    return 0;
}
