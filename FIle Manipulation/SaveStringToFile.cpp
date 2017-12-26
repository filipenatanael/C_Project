/*
Manipulação de arquivos;

- fazer um programa para gravar textos(string) em arquivo teste;
- Seu programa deve permitir a incluçâo da string,Pesquisar se uma determinadar string esta(ou nâo)
  no arquivo e listar todos registros do arquivo;
- Modularize, ou seja, crie funções, seu programa.
- Elabore um menu de opções;

- Segetão de menu:
      bool inserir(char *s, file *p); 
  [1] Inserir string no arquivo;
  [2] Pesquisar string no arquivo;
  [3] Imprimir conteudo do arquivo;
  [4] Encerrar o programa;

- Função abrir arquivo;

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Tamanho Maximo String;
#define TMXS 80
//Tamanho Maximo Contandor de String;
#define MMXC  5

int main(void){
    /*
    STRS[TMXS] - Vetor de strings;
    OPC - Opcao de funcoes;
    */
    char STRS[TMXS];
    
    //----------------
    char STR7[TMXS];
    
    
    char OPC;
          printf("[A] - Inserir\n");
          printf("[B] - Pesquisar\n");
          printf("[C] - Imprimir\n");
          printf("[D] - Finalizar\n");
          printf("\n\nInforme Opcao: ");
    scanf("%c",&OPC);
    switch(OPC){
        case 'a':
          char FuncaoInserir(char INSTRs[TMXS]);
          FuncaoInserir(STRS);
          break;
        case 'b':
          char FuncaoPesquiar(char FPSTRs[TMXS]);
          printf("Pesquisar: ");
          gets(STR7);
          FuncaoPesquiar(STR7);
          break;     
        case 'c':
          char FuncaoImprimir(char IMPSTRs[TMXS]);
          FuncaoImprimir(STRS);
          break;
        case 'd':
          //FILE *Arquivo;
          //fclose(Arquivo);
          printf("\n\n");
          printf("Arquivo Finalizado!");
          printf("\nPress <ENTER> to Quit..."); 
          printf("\n\n");
          break;
          }

 system("pause");
 return 0;
 }
 
 char FuncaoInserir(char INSTRs[TMXS]){
     /*
    INSTRs - Paramentro Inserir Argumentos;
    TMXS - Tamanho Maximo String;
    STR1 - String Local Auxiliar;
    MMXC - Tamanho Maximo do Contador;
    fflush(stdin) - Limpar buffer do teclado;
    */
    FILE *Arquivo = fopen("C:\\Users\\Filipe\\Desktop\\Estudando\\testes.txt","w");
    char STR1[TMXS];
    printf("\n\n");
    for(int cont=0; cont<MMXC; cont++){
        printf("Informe String[S%i]: ",cont+1);
        fflush(stdin);
        gets(STR1);
        fprintf(Arquivo,"%s",STR1);
        }
      return 0;
      }
  
     //============================================ 
     char FuncaoImprimir(char IMPSTRs[TMXS]){
            /*
            INSTRs - Paramentro Imprimir Argumentos;
            STR2 - String Local Auxiliar;
            */   
            FILE *Arquivo = fopen("C:\\Users\\Filipe\\Desktop\\Estudando\\testes.txt","r");   
            char STR2[TMXS];
            fscanf(Arquivo,"%s",&STR2);
            printf("%s",STR2);
            printf("\n\n");
            return 0;
            }
