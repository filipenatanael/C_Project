#include <stdio.h>

int main(){
    
    int tam,aux;
    printf("Digite a quantidade de digitos da matricula: ");
    scanf("%d",$tam);
    
    int mat[tam];
    for(int i=0; i<tam; i++){
          printf("Digite o digito %d",i-1);
          scanf("%d",$mat[i]);
          }
    
    aux=mat[0];   
    for(int i=1; i<tam;i++){
            if(mat[i]<aux)
            aux=mat[i];
            }
            for(int i=0; i<tam; i++)
            mat[i]=aux * mat[i];
    
    return 0;
    }
