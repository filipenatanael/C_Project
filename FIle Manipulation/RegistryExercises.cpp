#include <stdio.h>
#include <stdlib.h>
#define TAM 50

typedef struct{
        int codigo;
        char nome[TAM];
        int ativo;
        }Cliente;
        
void cabecalho(char *titulo){
     printf("\n\n>>>>>[%s]<<<<<<\n\n",titulo);
     }
     
int main(){
    FILE *arq;
    Cliente cli;
    int op ,pos;
    char resp = 's';
    char resp1; //Auxiliar
    
    arq = fopen("C:\\Cliente.dat", "w+r+b");
    if(arq == NULL)
    printf("\nER01 - Erro ao tentar abrir arquivo.");
    else{
         do{
                   cabecalho("Menu");
                   printf("\n1 - Incluir");
                   printf("\n2 - Alterar");
                   printf("\n3 - Excluir");
                   printf("\n4 - Consultar");
                   printf("\n5 - Relatorio");
                   printf("\n6 - Sair");
                   scanf("%d",&op);
                   getchar();
                   
                   switch(op){
                   case 1:
                          cabecalho("Inclusao");
                          cli.ativo = 1;
                          printf("\nDigite o codigo do cliente: ");     
                          scanf("%d",&cli.codigo);
                          fflush(stdin);
                          printf("\nDigite o nome do Cliente: ");
                          gets(cli.nome);
                          
                          fwrite(&cli, sizeof(cli),1,arq);
                          
                          if(ferror(arq))
                              printf("Erro de gravacao no arquivo.");
                          else
                              printf("\nCliente cadastrado com sucesso.");
                          break;
                    case 2:
                          cabecalho("Alteracao");
                          printf("\nInforme posicao de alteracao: ");
                          scanf("%d",&pos);
                          getchar();
                          
                          fseek(arq, sizeof(Cliente)*(pos - 1),SEEK_SET);
                          
                          if(ferror(arq))
                              printf("Erro no posicionamente do Arquivo.");
                              else{
                              fread(arq, sizeof(Cliente),1,arq);
                              if(ferror(arq))
                              printf("Erro de leitura do arquivo."); 
                              else{
                                   printf("\nCliente codigo: ",cli.codigo);
                                   printf("\nCliente nome: ",cli.nome);
                                   printf("\nCliente ativo: ",cli.ativo);
                              }
                                   
                    }
                    printf("\nDigite o novo codigo do cliente: ");         
                    scanf("%d",&cli.codigo);
                    getchar();     
                    printf("\nDigite o novo nome do Cliente: ");
                    gets(cli.nome);
                    
                    fseek(arq, sizeof(Cliente)*(pos - 1),SEEK_SET);
                    break;
                    
                    case 3:
                         cabecalho("Exclusao");
                         printf("Informe o posicionamente do Arquivo de exclusao: "); 
                         scanf("%d",&pos);
                         getchar();
                         
                         fseek(arq, sizeof(Cliente)*(pos - 1),SEEK_SET);
                         
                         if(ferror(arq))
                              printf("Erro no posicionamente do Arquivo.");
                              else{
                              fread(arq, sizeof(Cliente),1,arq);
                              if(ferror(arq))
                              printf("Erro de leitura do arquivo."); 
                              else{
                                   printf("\nCliente codigo: ",cli.codigo);
                                   printf("\nCliente nome: ",cli.nome);
                                   printf("\nCliente ativo: ",cli.ativo);
                              }
                                   
                    }
                    do{
                    printf("Confirma exclusao? (s/n): "); 
                    scanf("%c",resp1);
                    resp =  resp1;

                    }while(resp != 's' && resp != 'n');
                    
                    if(resp == 's'){
                            fseek(arq, sizeof(Cliente)*(pos - 1),SEEK_SET);
                            
                            cli.ativo = 0;
                            fwrite(&cli, sizeof(Cliente),1,arq);
                            if(ferror(arq))
                              printf("\nErro ao excluir dados.");
                              else
                              printf("\nSucesso ao excluir dados.");
                              }
                              else
                              printf("\n\nExclusao não efetuado.");
                              break;
                    case 4:
                         cabecalho("Consultando");
                         printf("\n\nDigite a posicao de pesquisa: ");
                         scanf("%d",&pos);
                         getchar();
                         
                         fseek(arq, sizeof(Cliente)*(pos - 1),SEEK_SET);
                         
                         if(ferror(arq))
                              printf("Erro no posicionamente do Arquivo.");
                              else{
                              fread(arq, sizeof(Cliente),1,arq);
                              if(ferror(arq))
                              printf("Erro de leitura do arquivo."); 
                              else{
                                   printf("\nCliente codigo: ",cli.codigo);
                                   printf("\nCliente nome: ",cli.nome);
                                   printf("\nCliente ativo: ",cli.ativo);
                              }
                                   
                    }
                    
                    getchar();
                    break;
                    
                    case 5:
                         cabecalho("Imprimindo");
                         
                         rewind(arq);
                         if(ferror(arq))
                              printf("Erro no posicionamente do Arquivo.");
                              else{
                                   while(!feof(arq)){
                                   fread(arq, sizeof(Cliente),1,arq);
                                   if(ferror(arq))
                                   printf("Erro no posicionamente do Arquivo.");
                                   else{
                                        if(!feof(arq)){
                                                       if(cli.ativo){
                                                       printf("\nCliente codigo: ",cli.codigo);
                                                       printf("\nCliente nome: ",cli.nome);
                                                       }
                                        }
                                   }
                              }
                         }
                         getchar();
                                                       
                          }
                    }
     while(op != 6);
}
fclose(arq);
                                                       
                                                       
system("pause");
return 0;
}
                                                                                                 

