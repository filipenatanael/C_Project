/* Fazer uma fun��o que recebe como argumento o pre�o de um produto e o percentual de reajuste de produto.
A fun��o deve retornar o novo pre�o */

/* Agora utilizando ponteiros e refer�ncias */

#include<stdio.h>
#include<stdlib.h>
//Fun��o para fazer o calculo do pre�o reajustado

void NOVO_PRECO(float *Preco,float *Percentual){

	*Preco = *Preco +(*Preco * *Percentual)/100;
	
	
}

/* Utilizando refer�ncia deve ser impresso apenas o pre�o reajustado, utilizando menos vari�veis e assim
utilizando ponteiros para dar refer�ncia do endere�o apontado */

int main(){
	
	float Preco,Percentual;
	printf("Digite um preco para o produto: ");
	scanf("%f",&Preco);
	printf("Digite um percentual para reajuste do preco do produto: ");
	scanf("%f",&Percentual);
	NOVO_PRECO(&Preco,&Percentual);
	printf("O preco reajustado e: %.2f",Preco);
	
}

