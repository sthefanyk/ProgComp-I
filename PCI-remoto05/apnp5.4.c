#include <stdio.h>

int main(){

    int num, i = 1, x, count = 0;

    printf("Digite valor: ");
    scanf("%i", &num);

    if(num != 1){
        do{
            x = num % i;
            i++;
            if(x == 0){
                count++;
            }

        }while(i <= num);
    }
    if(count == 2){
        printf("- [PRIMO]");
    }else
        printf("- [NAO PRIMO]");
    
    return 0;
}
