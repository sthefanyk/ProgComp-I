#include <stdio.h>

int main(){

    float q_item, v_item;
    float preco, desconto, p_final;

    printf("Digite quantidade de itens: ");
    scanf("%f", &q_item);
    printf("Digite valor do item: ");
    scanf("%f", &v_item);

    preco = q_item * v_item;

    if(q_item > 0 && q_item < 11){
        desconto = (preco * 10) / 100;
        p_final = preco - desconto;
    }else if(q_item > 10 && q_item < 21){
        desconto = (preco * 15) / 100;
        p_final = preco - desconto;
    }else if(q_item > 20 && q_item < 51){
        desconto = (preco * 20) / 100;
        p_final = preco - desconto;
    }else if(q_item > 50){
        desconto = (preco * 30) / 100;
        p_final = preco - desconto;
    }
    
    printf("\nValor total da compra: %.2f", p_final);
    printf("\nValor do desconto: %.2f", desconto);

    return 0;
}
