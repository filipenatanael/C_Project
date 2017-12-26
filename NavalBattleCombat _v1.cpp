#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

void menu();

char tab1[10][10];
char tab2[10][10];
   
  for(int x=0; x<10; x++){
        for(int y=0; y<10; y++){
        tab1[x][y]='~'; 
        tab2[x][y]='~';		
        }
     }
     

   int LINHA,COLUNA,POSICAO;
   char TIPONAVIO;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
//--------------------JOGADOR NUMERO 1----------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  
   for(int z=0; z<2; z++){
   printf("\n\nJOGADOR: 1 || NAVIOS: %i\n",z+1);	
   printf("\nLINHA: ");
   scanf("%i",&LINHA);
   printf("\nCOLUNA: "); 
   scanf("%i",&COLUNA);
   
   printf("\n(1)Vertical\n(2)Horizontal"); 
   printf("\n\n>> "); 
   scanf("%i",&POSICAO);
   

   
   switch(POSICAO){
   case 1:
   menu();
   scanf("%s",&TIPONAVIO);
   
   
   for(int k=0; k<6; k++){
   if(tab1[LINHA][COLUNA] != '~'){
            printf("\n\nDesdeculpe! Existe um navio neste local.");
            printf("\nInforme Novo Posicinamento:");
            printf("\nLINHA:");
            scanf("%i",&LINHA);
            printf("\nCOLUNA:"); 
            scanf("%i",&COLUNA);
            }
   
   }
   switch(TIPONAVIO){
        	case 'a':
        	for(int x=0; x<6; x++){
            tab1[LINHA][COLUNA] = 'A';
            LINHA ++;
            }
			break;
			case 'b':
        	for(int x=0; x<4; x++){
            tab1[LINHA][COLUNA] = 'B';
            LINHA ++;
            }
			break;
			case 'c':
        	for(int x=0; x<2; x++){
            tab1[LINHA][COLUNA] = 'C';
            LINHA ++;
            }
			break;
		}
   break;
   
   case 2:
   menu();
   scanf("%s",&TIPONAVIO);
   for(int k=0; k<6; k++){
   if(tab1[LINHA][COLUNA] != '~'){
            printf("\n\nDesdeculpe! Existe um navio neste local.");
            printf("\nInforme Novo Posicinamento:");
            printf("\nLINHA:");
            scanf("%i",&LINHA);
            printf("\nCOLUNA:"); 
            scanf("%i",&COLUNA);	
            }
   
   }
   switch(TIPONAVIO){
        	case 'a':
        	for(int x=0; x<6; x++){
            tab1[LINHA][COLUNA] = 'A';
            COLUNA ++;
            }
			break;
			case 'b':
        	for(int x=0; x<4; x++){
            tab1[LINHA][COLUNA] = 'B';
            COLUNA ++;
            }
			break;
			case 'c':
        	for(int x=0; x<2; x++){
            tab1[LINHA][COLUNA] = 'C';
            COLUNA ++;
            }
			break;
		}
   break;
   }
   
   system("cls");
   }


 printf("\n\n");
   for(int x=0; x<10; x++){
      for(int y=0; y<10; y++){
	  printf("%c",tab1[x][y]);
      }
    printf("\n");
    }


LINHA = 0;
COLUNA = 0;
POSICAO = 0; 

printf("\n\nIniciando Jogo...");
system("TIMEOUT /T 5");

  for(int x=0; x<10; x++){
      for(int y=0; y<10; y++){
	  if(tab1[x][y] != '~'){
      printf("\n %i %i",x,y);
      }
    printf("\n");
    }

}


 for(int z=0; z<5; z++){
   
   printf("\n\nJOGADOR: 1 || NAVIOS: %i\n",z+1);
   printf("\nLINHA: ");
   scanf("%i",&LINHA);
   printf("\nCOLUNA: "); 
   scanf("%i",&COLUNA);
   
   if(tab1[LINHA][COLUNA] != '~'){
   printf("\nAcertou um navio inimigo!");
   	
   }
   
}

   printf("\n\n");
   
   for(int x=0; x<10; x++){
      for(int y=0; y<10; y++){
	  printf("%c",tab1[x][y]);
      }
    printf("\n");
    }


   printf("Dois\n\n");
   
   for(int x=0; x<10; x++){
      for(int y=0; y<10; y++){
	  printf("%c",tab2[x][y]);
      }
    printf("\n");
    }


  return 0;
  }


void menu(){
	printf("\nNavio.s Disponiveis:");
	printf("\n\n(A)Battleship");
	printf("\n(B)Submarine");
	printf("\n(C)Minesweeper");
	printf("\n\n>> "); 
	
}

