#include <stdio.h>
#include <string.h>

int main(){
    
    char nome[50];
    char vet[5] = {'A','E','I','O','U'};
    int cont = 0;
    
    printf("Digite seu nome: ");
    gets(nome);
    
    for(int i=0; i< strlen(nome); i++){
            for(int j=0; j<5; j++){
                  if(nome[i] == vet[j]){
                       cont++;
                       break;
                       }
                  }
            
            }
            printf("O valor de cont e %d",cont);
            
    
    return 0;
    }
