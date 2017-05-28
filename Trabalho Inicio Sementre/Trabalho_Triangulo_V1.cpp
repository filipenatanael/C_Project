#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int triangulo(int x, int y, int z);
    int a,b,c;
    bool resp;
    char caracter[3] = {'A','B','C'};
    
    for(int cont=0; cont<=2; ++cont){
            printf("Digite o valor de %c: ",caracter[cont]);
            
            switch(cont){
               case 0:
               scanf("%i",&a);
               break;
               case 1:
               scanf("%i",&a);
               break;
               case 2:
               scanf("%i",&a);
               break;
               }//Fim do switch/Case;
            }
    
    //Imprimindo resultado final
    resp = triangulo(a,b,c);
    if(resp == true){
            printf("\nE um triangulo!");
            }
            else{
                 printf("\nNão e um triangulo!");
                 }
    
    //Teste;
    //printf("Resp: %B\n",resp);
    
    system("pause");
    return 0;
    }
    //Sub-Rotinas(Funcoes) verificando se formam um triangulo;
    int triangulo(int x, int y, int z){
        bool result = false;
        if(x==y || x==z || y==z){
             result = true;
             }
        return result;
        }
