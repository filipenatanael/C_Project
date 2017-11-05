#include <stdio.h>

int main(){
    
    bool x = false;
    int i=0;
    char nome[50];
    printf("Digite seu nome: ");
    gets(nome);
    
    while(!x){
              if(nome[i]=='A' || i == strlen(nome)){
              x=true;
              i++;
              }
              printf("O valor de X e: %d",i);
    
    }
