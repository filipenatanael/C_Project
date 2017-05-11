#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int vetor[3];
	int x=0;
	int y=0;
	int total =0;
	int PDMaisVendeu = 0;
	int LJVendeuMais = 0;
	
	//Zerando vetor;
	for(int z=0; z<3; z++){
	vetor[z]= 0;	
	}
	
	for( x=0; x<3; x++){
		for(y=0; y<3; y++){
        vetor[x]= vetor[x] + matriz[y][x];
        
		}
	}
	
	for(int z=0; z<3; z++){
	printf("\nLoja %d vendeu: %d",z+1,vetor[z]);
	total = total + vetor[z];
	if(vetor[z] > PDMaisVendeu){
	     PDMaisVendeu = vetor[z];
		 LJVendeuMais = z;
		 LJVendeuMais = LJVendeuMais +1;
		 //+1 para controlar o indice do vetor;
		 }
		
	}
	
	printf("\n\nTotal Vendido: %d",total);
	printf("\n\nProduto Mais Vendido: %d",PDMaisVendeu);
	printf("\n\nLoja que mais vendeu: %d",LJVendeuMais);
	

	
	
	
return 0;
}
