#include <stdio.h>

int main(){

    int v[7], i, j, aux, x;
     
    for(i = 0;i < 7; i++){
        printf("Digite %i numeros: ", i + 1);
        scanf("%i", &v[i]);
    }  

    for(i = 0;i < 7; i++){
        for(j = i + 1;j < 7; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                
            }
        }
    }
    for(x = 0;x < 7; x++){
        printf("\n- Ordem crescente: %i", v[x]);
    }

    return 0;
}
