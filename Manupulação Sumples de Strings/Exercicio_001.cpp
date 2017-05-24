#include <stdio.h>

int main(){
    
    int tot,num;
    printf("Informe a quantidade de letras de seu nome: ");
    scanf("%d",$num);
    tot = 0;
    
    for(int i=1; i<=num; i++){
            if(i%2 == 0){
                   tot++;
                   }
            }
            printf("O Total é %d",tot);    
    
    return 0;
    }
