#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ECadastro{
        char Nome[50];
        char Email[50];
        struct ECadastro *Next;
        }T_ECadastro;


int main(){
    char resp;
    
    T_ECadastro *Ponto_Inicial;
    T_ECadastro *Proximo_Ponto;
    
    Ponto_Inicial = (T_ECadastro *)malloc(sizeof(T_ECadastro)); 
     
       if(Ponto_Inicial == NULL)
       exit(1);
    
         Proximo_Ponto = Ponto_Inicial;
         
         while(1){
                  printf("Infome Nome: ");
                  gets(Proximo_Ponto->Nome);
                  printf("Infome Email: ");
                  gets(Proximo_Ponto->Email);
                  
                  
                  printf("Deseja contunuar informando[Y/N]: ");
                  scanf("%c",&resp);
                  if(resp == 'y'){
                  fflush(stdin);
                  Proximo_Ponto->Next = (T_ECadastro *)malloc(sizeof(T_ECadastro));
                  Proximo_Ponto = Proximo_Ponto->Next;
                  
                  }else{
                   printf("\nSair do laço de repeticao!");
                   break;
                   }
                   
         }
         
         Proximo_Ponto->Next = NULL;
         Proximo_Ponto = Ponto_Inicial;
         
         while(Proximo_Ponto != NULL){
         printf("\nNome: %s",Proximo_Ponto->Nome);
         printf("\nEmail: %s",Proximo_Ponto->Email);
         Proximo_Ponto = Proximo_Ponto->Next;      
         }
    
    
    system("pause");
    return 0;
    }

