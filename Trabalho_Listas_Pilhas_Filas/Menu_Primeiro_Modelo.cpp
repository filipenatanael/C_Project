#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void MenuPrincipal();
void MenuListas();
void MenuPilhas();
void MenuFilas();
void Finalizando();

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
                      //CreateListas();
                      while(op != '0'){
                      printf("Informe Telefone: ");
                      scanf("%d",&fone);
                      //InserirDados(fone);
                      printf("Continue Inserindo[0/1]:");
                      op = getch();
                      }
                      break;
                      case 2:
                      printf("\n\nInforme Elemento: ");
                      //scanf("%d",&fone);
                      //RemovendoDados(fone);
                      break;
                      case 3:
                      //ImprimindoDados();
                      break;
                      case 4:
                      //ZerandoListas();
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
                      //CreatePilhas();
                      break; 
                      case 2:
                      while(op != '0'){
                      printf("Informe Telefone: ");
                      scanf("%d",&fone);
                      //InserirDadosPilhas(fone);
                      printf("Continue Inserindo[0/1]:");
                      op = getch();
                      }
                      break;
                      case 3:
                      //Desempilhando Dados...
                      break;
                      case 4:
                      //ImprimindoDadosPilhas();
                      break;
                      case 5:
                      //ZerandoPilhas();
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
                      //CreateFilas();
                      break;
                      case 2:
                      //comandos...
                      break;
                      case 3:
                      //comandos...
                      break;
                      case 4:
                      //comandos...
                      break;
                      case 5:
                      //comandos...
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

main(){
       
       MenuPrincipal();


          
          getch();
          return 0;
          }
