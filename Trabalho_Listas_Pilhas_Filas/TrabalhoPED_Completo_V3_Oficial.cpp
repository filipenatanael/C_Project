//https://www.youtube.com/watch?v=uFJwI45Ktbg
//https://www.youtube.com/watch?v=Mb9AQdPGeJI
//https://www.youtube.com/watch?v=dkQt7OrzFlg
//https://www.youtube.com/watch?v=6m7MsOxAyGQ
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Type_Listas{
       int Telefone;
       struct Type_Listas *Proximo;
       };

struct Type_Listas *Primeiro;
struct Type_Listas *Ultimo; 

void CreateListas(){
     struct Type_Listas *Auxiliar;
     Auxiliar = (struct Type_Listas *)malloc(sizeof(struct Type_Listas));
     Primeiro = Auxiliar;
     Ultimo = Primeiro;
     }

int InserirDados(int Elemento){
    struct Type_Listas *Auxiliar;
    Auxiliar = (struct Type_Listas *)malloc(sizeof(struct Type_Listas));
    Auxiliar->Telefone = Elemento;
    Ultimo->Proximo = Auxiliar;
    Ultimo = Ultimo->Proximo;
    Auxiliar->Proximo = NULL;
    }
  
void ImprimindoDados(){
     struct Type_Listas *Auxiliar;
     Auxiliar = Primeiro->Proximo;
     while(Auxiliar != NULL){
            printf("Telefone: %d",Auxiliar->Telefone);
            Auxiliar = Auxiliar->Proximo;
            }
     }

void PesquisandoDados(int P_Elemento){
     struct Type_Listas *Auxiliar;
     int FlaG = 0;
     Auxiliar = Primeiro->Proximo;
     while(Auxiliar != NULL){
           if(Auxiliar->Telefone == P_Elemento){
               printf("Elemento Encontrado: %d",P_Elemento); 
               FlaG = 1;
               //Auxiliar = NULL;
               break;
               }
               else
               Auxiliar = Auxiliar->Proximo; 
           }
           if(!FlaG)
           printf("Elemento Não Encontrado.");
     
     }

void RemovendoDados(int R_Elemento){
     struct Type_Listas *Auxiliar;
     struct Type_Listas *DeadPool;
     int FlaG = 0;
     Auxiliar = Primeiro->Proximo;
     DeadPool = Primeiro;
     while(Auxiliar != NULL){
           if(Auxiliar->Telefone == R_Elemento){
               printf("O Elemento %d Foi Removido.",R_Elemento); 
               DeadPool->Proximo = Auxiliar->Proximo;
               FlaG = 1;
               //Auxiliar = NULL;
               break;
               }
               else
               Auxiliar = Auxiliar->Proximo;
               DeadPool = DeadPool->Proximo;
           }
           //if(FlaG == 0)
           if(!FlaG)
           printf("Elemento Não Encontrado.");
     
     }





main(){

  char op = '2';
  int i ,fone;
  
  CreateListas();
  while(op != '0'){
       printf("Informe Telefone: ");
       scanf("%d",&fone);
       InserirDados(fone);
       printf("Continue Inserindo[0/1]:");
       op = getch();
       }
       ImprimindoDados();
       printf("\n\nInforme o Elemento de Pesquisar: ");
       scanf("%d",&fone);
       PesquisandoDados(fone);
       printf("\n\nRemovendo Elemento: ");
       scanf("%d",&fone);
       RemovendoDados(fone);
       
       getch();

       return 0;
       }
