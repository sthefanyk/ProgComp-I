#include <stdio.h>

int main(){

    srand(time(NULL));

    int v[10], menor, maior, aux, num, num_p, i;

    printf("\n\tDigite o intervalo: ");
    scanf("%d %d", &menor, &maior);
    if (menor > maior){
        aux = menor;
        menor = maior;
        maior = aux;
    }
    
    for ( i = 0; i < 10; i++){
        v[i] = menor + (rand() % (maior - menor));
    }
    
    printf("\n\tDigite um numero a ser procurado: ");
    scanf("%d", &num);

    printf("\n\tVetor:");
    for ( i = 0; i < 10; i++){
        printf(" %d", v[i]);
        if (num == v[i]){
            num_p = i;
        }
    }
    if (num_p == NULL){
        printf("\n\tValor nao encontrado.");
    }else
        printf("\n\tValor encontrado na posicao: %d", num_p);

    return 0;
}
