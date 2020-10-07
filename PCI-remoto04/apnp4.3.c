#include <stdio.h>

int main(){

    int num, u, d, c;

    printf("Digite o valor (3 digitos): ");
    scanf("%i", &num);

    

    if(num < 1000 && num > 99){

        u = num % 10;
        d = (num / 10) % 10;
        c = (num / 10) / 10;

        if(u == d && u == c){
            printf("- Equilatero");
        }else if(u == d || u == c || d == c){
            printf("- Isosceles");
        }else
            printf("- Escaleno");
        
    }else
        printf("- Entrada invalida");
    

    return 0;
}
