/* 
# Discipline: Programação e Estrutura de Dados
# Author: Filipe Natanael de Morais Gomes
# Date: 23/11/2014

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/*---Declarações de Estruturas---*/

struct Type_Listas{
       int Telefone;
       struct Type_Listas *Proximo;
       };

/*---Declarações de Funcoes---*/

void MenuPrincipal();
void MenuListas();
void MenuPilhas();
void MenuFilas();
void Finalizando();

void CreateListas();
int InserirDados(int Elemento);
void ImprimindoDados();
void PesquisandoDados(int P_Elemento);
void ZerandoListas();
void RemovendoDados(int R_Elemento);
void CreatePilhas();
void InserirDadosPilhas(int Elemento);
void ZerandoPilhas();
void ImprimindoDadosPilhas();
void CreateFilas();

/*---Declarações de Apontadores---*/

struct Type_Listas *Primeiro;
struct Type_Listas *Ultimo; 
struct Type_Listas *Topo;
struct Type_Listas *Novo;


/*---Comandos relacionado as listas---*/

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
     if(Primeiro == NULL){
                 printf("\nListas Nao Existe.");
                 printf("\n\nPresione <enter> para retornar ao Menu\n");
                 getch();
                 MenuListas();
                 }
                 else{
     Auxiliar = Primeiro->Proximo;
     printf("\nTelefone Armazenandos.\n");
     while(Auxiliar != NULL){
            printf("\nTelefone: %d",Auxiliar->Telefone);
            Auxiliar = Auxiliar->Proximo;
            }
        if(Auxiliar == NULL){
              printf("\n\nPresione <enter> para retornar ao Menu\n");
              getch();
              MenuListas();
             }
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
   
void ZerandoListas(){
     struct Type_Listas *Auxiliar;
     Auxiliar = Primeiro->Proximo;
     //while(Auxiliar->Telefone != NULL){
     while(Auxiliar != NULL){
          //Auxiliar->Telefone = NULL;
            Auxiliar = Auxiliar->Proximo;
                 //if(Auxiliar->Telefone == NULL){
                 if(Auxiliar == NULL){
                 free(Primeiro);
                 printf("Processo Concluido.");
                 break;
                 }
            }
     }

void RemovendoDados(int R_Elemento){
     struct Type_Listas *Auxiliar;
     struct Type_Listas *DeadPool;
     int FlaG = 0;
     Auxiliar = Primeiro->Proximo;
     DeadPool = Primeiro;
     while(Auxiliar != NULL){
           if(Auxiliar->Telefone == R_Elemento){
               printf("\nO Elemento %d Foi Removido.",R_Elemento);
               printf("\nPresione <enter> para retornar ao Menu");
               getch();
               MenuPrincipal();
               DeadPool->Proximo = Auxiliar->Proximo;
               FlaG = 1;
              
               break;
               }
               else
               Auxiliar = Auxiliar->Proximo;
               DeadPool = DeadPool->Proximo;
           }
           
           if(!FlaG)
           printf("\nElemento Não Encontrado.");
           printf("\nPresione <enter> para retornar ao Menu\n");
           getch();
           MenuListas();
     
     }
     
void CreatePilhas(){
     struct Type_Listas *Aux_Pilhas;
     Aux_Pilhas = Primeiro; 
     Topo = Aux_Pilhas;
     ImprimindoDadosPilhas();
     }   
        
void InserirDadosPilhas(int Elemento){
    struct Type_Listas *Aux_Pilhas;
    Aux_Pilhas = Topo;
    while(Aux_Pilhas != NULL){
    //if(Aux_Pilhas->Telefone == NULL){
    if(Aux_Pilhas == NULL){
         Aux_Pilhas->Telefone = Elemento;
         break;
         }     
    }
}

void ZerandoPilhas(){
     struct Type_Listas *Auxiliar;
     Auxiliar = Topo;
     //while(Auxiliar != NULL){
    //Auxiliar->Telefone = NULL;
     while(Auxiliar != NULL){
          //Auxiliar->Telefone = NULL;
          Auxiliar = NULL;
          Auxiliar = Auxiliar->Proximo;
                 //if(Auxiliar->Telefone == NULL){
                 if(Auxiliar == NULL){
                 free(Topo);
                 printf("Processo Concluido.");
                 break;
                 }
            }
     }


void ImprimindoDadosPilhas(){
     struct Type_Listas *Pilhas;
     Pilhas = Topo;
     printf("\nDados Empilhandos:\n");
     while(Pilhas != NULL){
            printf("\nTelefone: %d",Pilhas->Telefone);
            Pilhas = Pilhas->Proximo;
            if(Pilhas != NULL){
                 printf("\n\nPresione <enter> para retornar ao Menu\n");
                 getch();
                 MenuPilhas();
            }
            
                 }
     }

/*---Comandos relacionado as Filas---*/

void CreateFilas(){
     struct Type_Listas *Aux_Filas;
     Aux_Filas = Primeiro; 
     Novo = Aux_Filas;
     }  



   int main(){
   
   MenuPrincipal();




          
          getch();
          return 0;
          }
          


/*---Funcao Menu Listas--*/  

void MenuListas(){
                system("cls");
                printf("\n[1] Inserir Dados\n");
                printf("[2] Remover Dados\n");
                printf("[3] Imprimir Dados\n");
                printf("[4] Zerar Listas\n");
                printf("[5] Retornar ao Menu Principal\n");
                char op = '2';
                int fone, Opcao;
                printf("\n>> ");
                scanf("%d",&Opcao);
                if((Opcao <= 0 )||( Opcao >= 6)){
                printf("\n\nErro: Opcao Inesistente!");
                getch();
                system("cls");
                MenuPrincipal();
                }
                switch(Opcao){
                      case 1:
                      CreateListas();
                      while(op != '0'){
                      printf("Informe Telefone: ");
                      scanf("%d",&fone);
                      InserirDados(fone);
                      printf("Continue Inserindo [1] SIM || [0] NAO :\n");
                      op = getch();
                      if(op == '0'){
                           MenuListas();
                           }
                      }
                      
                      break;
                      case 2:
                      printf("\nInforme Elemento: ");
                      scanf("%d",&fone);
                      RemovendoDados(fone);
                      break;
                      case 3:
                      ImprimindoDados();
                      break;
                      case 4:
                      ZerandoListas();
                      break;
                      case 5:
                      MenuPrincipal();
                      break;
                }     
     }
     
/*---Funcao Menu Pilhas---*/  

void MenuPilhas(){
                system("cls");
                int Opcao, fone;
                char op = '2';
                printf("\n[1] Gerar Pilhas|Listas\n");
                printf("[2] Empilhar\n");
                printf("[3] Desempilhar\n");
                printf("[4] Imprimir\n");
                printf("[5] Zerar Pilhas\n");
                printf("[6] Retonar ao Menu Prinncipal\n");
                printf("\n>> ");
                scanf("%d",&Opcao);
                if((Opcao <= 0 )||( Opcao >= 7)){
                printf("\n\nErro: Opcao Inesistente!");
                getch();
                system("cls");
                MenuPrincipal();
                }
                switch(Opcao){
                      case 1:
                      CreatePilhas();
                      
                      break; 
                      case 2:
                      while(op != '0'){
                      printf("Informe Telefone: ");
                      scanf("%d",&fone);
                      InserirDadosPilhas(fone);
                      printf("\nContinue Inserindo [1] SIM || [0] NAO :\n");
                      op = getch();
                      if(op == '0'){
                           MenuListas();
                           }
                      }
                      break;
                      case 3:
                      //Desempilhando Dados...
                      break;
                      case 4:
                      ImprimindoDadosPilhas();
                      break;
                      case 5:
                      ZerandoPilhas();
                      break;
                      case 6:
                      MenuPrincipal();
                      break;
                      }             
     
     }

/*---Funcao Menu Filas---*/  
    
void MenuFilas(){
                system("cls");
                char op = '2';
                int Opcao, fone;
                printf("\n[1] Gerar Fila\n");
                printf("[2] Inserir\n");
                printf("[3] Remover\n");
                printf("[4] Imprimir\n");
                printf("[5] Zerar Fila\n");
                printf("[6] Retonar ao Menu Prinncipal\n");
                printf("\n>> ");
                scanf("%d",&Opcao);
                if((Opcao <= 0 )||( Opcao >= 7)){
                printf("\n\nErro: Opcao Inesistente!");
                getch();
                system("cls");
                MenuPrincipal();
                }
                switch(Opcao){
                      case 1:
                      CreateFilas();
                      break;
                      case 2:
                      //Inserir
                      break;
                      case 3:
                      //Remover
                      break;
                      case 4:
                      //Imprimir
                      break;
                      case 5:
                      //Zerar Fila
                      break;
                      case 6:
                      MenuPrincipal();
                      break;
                      }         
      }

/*---Funcao Finalizando Software---*/  

void Finalizando(){
     exit(1);
     }

/*---Funcao Menu Principal---*/  
    
void MenuPrincipal(){
     system("cls");
     char op = '2';
     int fone, Opcao;
     printf("\n[1] LISTA\n");
     printf("[2] PILHA\n");
     printf("[3] FILA\n");
     printf("[4] SAIR\n");
     printf("\n>> ");
     scanf("%d",&Opcao);
     if((Opcao <= 0 )||( Opcao >= 5)){
                printf("\n\nErro: Opcao Inesistente!");
                getch();
                system("cls");
                MenuPrincipal();
                }
     switch(Opcao){
            case 1:
            MenuListas();
            break;
            case 2:
            MenuPilhas();
            break;
            case 3:
            MenuFilas();
            break;
            case 4:
            Finalizando();
            break;
            }         
     }
