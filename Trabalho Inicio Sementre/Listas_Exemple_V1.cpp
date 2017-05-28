#include <stdio.h>
#include <stdlib.h>

struct Registro{
       int Valor;
       Registro *Proximo;
       Registro *Anterior;
       };

int main(void){
    char OP;
    
    struct Registro L1,L2,L3;
    struct Registro *Principal = &L1;
    
    L1.Valor = 10;
    L2.Valor = 20;
    L3.Valor = 30;
    
    L1.Anterior = (struct Registro *)0;
    L1.Proximo = &L2;
    L2.Anterior = &L1;
    L2.Proximo = &L3;
    L3.Anterior = &L2;
    L3.Proximo = (struct Registro *)0;
    
    printf("\nInfome Opcao:[P/A] ");
    scanf("%c",OP);
    
    while(Principal != (struct Registro *)0){
            switch(OP){
                  case 'p':
                  printf("\n%i",Principal->Valor);
                  Principal = Principal->Proximo;
                  break;
                  case 'a':
                  //if(Principal >= Principal.Proximo(struct Registro *)0;){
                  printf("\n%i",Principal->Valor);
                  Principal = Principal->Anterior;
                  //}
                  break;                
                  }
            
            
           }
        
    system("pause");
    return 0;
    }
