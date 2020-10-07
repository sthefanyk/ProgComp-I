#include <stdio.h>

int main(){

    char l1, l2;
    int i = 0;

    printf("Digite duas letra: ");
    fflush(stdin);
    scanf("%c %c", &l1, &l2);
	
    while(l1 <= l2){
        printf("%c ", l1 - 32); 
		l1++;
    }
    
    return 0;
}
