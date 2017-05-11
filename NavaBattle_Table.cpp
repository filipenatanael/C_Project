#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int Maximo = 10;
static const int Controle = 100;

//void Inicializando(char *GameBoard);
//void Imprimindo(char Table[Maximo][Maximo]);


int main(){
  
  char Tabuleiro1[10][10];
  
  for(int x=0; x<=10; x++){
	 	for(int y=0; y<=10; y++){
	 		Tabuleiro1[x][y] = 's';
	 	}
	 	printf("\n");
	 } 
  
  
  
   for(int x=0; x<=10; x++){
	 	for(int y=0; y<=10; y++){
	 		printf("  |%c|",Tabuleiro1[x][y]);
	 	}
	 	printf("\n");
	 } 
    printf("\n\n");
 
  /*
  char Tabuleiro2[Maximo][Maximo];
  Inicializando((char*)Tabuleiro1);
  Imprimindo(Tabuleiro1);
  
  */



}

//---------------------------------
//--- Inicializando Tabuleiro -----
//---------------------------------
void Inicializando(char *GameBoard){
     char *ponteiro;
	 ponteiro = GameBoard;
	 for(int cont=0; cont<=Controle; cont++){
	 	 *ponteiro = '~';
	 	  ponteiro++;
	 }	
	
}

//---------------------------------
//----- Imprimindo Tabuleiro ------
//---------------------------------

void Imprimindo(char Table[Maximo][Maximo]){
	 
	 for(int x=0; x<=Maximo; x++){
	 	for(int y=0; y<=Maximo; y++){
	 		printf("  | %c |",Table[Maximo][Maximo]);
	 	}
	 	printf("\n");
	 } 
}


