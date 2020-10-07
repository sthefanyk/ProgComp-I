#include <stdio.h>

int main(){

    int d1, d2;
    
    printf("Dias da semana: ");
    scanf("%i %i", &d1, &d2);

    printf("- [");
    
    if(d1 < 1 || d1 > 7){
        
        if(d2 == 1){
            printf("Domingo");
        }else if(d2 == 2){
            printf("Segunda");
        }else if(d2 == 3){
            printf("Terca");
        }else if(d2 == 4){
            printf("Quarta");
        }else if(d2 == 5){
            printf("Quinta");
        }else if(d2 == 6){
            printf("Sexta");
        }else if(d2 == 7){
            printf("Sabado");
        }
    }else if(d2 < 1 || d2 > 7){
        
        if(d1 == 1){
            printf("Domingo");
        }else if(d1 == 2){
            printf("Segunda");
        }else if(d1 == 3){
            printf("Terca");
        }else if(d1 == 4){
            printf("Quarta");
        }else if(d1 == 5){
            printf("Quinta");
        }else if(d1 == 6){
            printf("Sexta");
        }else if(d1 == 7){
            printf("Sabado");
        }
    }else{
        if(d1 == 1){
            printf("Domingo");
        }else if(d1 == 2){
            printf("Segunda");
        }else if(d1 == 3){
            printf("Terca");
        }else if(d1 == 4){
            printf("Quarta");
        }else if(d1 == 5){
            printf("Quinta");
        }else if(d1 == 6){
            printf("Sexta");
        }else if(d1 == 7){
            printf("Sabado");
        }

        printf(", ");

        if(d2 == 1){
            printf("Domingo");
        }else if(d2 == 2){
            printf("Segunda");
        }else if(d2 == 3){
            printf("Terca");
        }else if(d2 == 4){
            printf("Quarta");
        }else if(d2 == 5){
            printf("Quinta");
        }else if(d2 == 6){
            printf("Sexta");
        }else if(d2 == 7){
            printf("Sabado");
        }
    }

    
    printf("]");

    return 0;
}
