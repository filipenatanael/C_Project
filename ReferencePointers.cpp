#include<stdio.h>
#include<stdlib.h>
/* Fazer uma função que recebe como argumento o preço de um produto e o percentual de reajuste de produto.
A função deve retornar o novo preço  */

void NOVO_PRECO(float *Preco,float *Percentual){
	*Preco = *Preco +(*Preco * *Percentual)/100;	
}
/* Utilizando referência deve ser impresso apenas o preço reajustado, utilizando menos variáveis e assim
utilizando ponteiros para dar referência do endereço apontado */
int main(){
	float Preco,Percentual;
	printf("Digite um preco para o produto: ");
	scanf("%f",&Preco);
	printf("Digite um percentual para reajuste do preco do produto: ");
	scanf("%f",&Percentual);
	NOVO_PRECO(&Preco,&Percentual);
	printf("O preco reajustado e: %.2f",Preco);
}

