#include <stdio.h>
#include <stdlib.h>

int main(void){
    int triangulo(int LA, int LB, int LC);
    char caracter[3] = {'X','Y','Z'};
    int X,Y,Z;
    for(int cont=0; cont<=2; ++cont){
            printf("Informe o valor de %c: ",caracter[cont]);
            
            switch(cont){
               case 0:
               scanf("%i",&X);
               break;
               case 1:
               scanf("%i",&Y);
               break;
               case 2:
               scanf("%i",&Z);
               break;
               }
            }
            
            int Auxiliar;
            Auxiliar = triangulo(X,Y,Z);
            switch(Auxiliar){
               case 0:
               printf("\nOs valores X:%i Y:%i Z:%i nao formam um triangulo!\n",X,Y,Z);
               break;
               case 1:
               printf("\nTriangulo Equilatero.\n");
               break;
               case 2:
               printf("\nTriangulo Escaleno.\n");
               break;
               case 3:
               printf("\nTriangulo Isosceles.\n");
               break;
               case 4:
               printf("\nTriangulo Isosceles.\n");
               break;
               case 5:
               printf("\nTriangulo Isosceles.\n");
               break;
               }
    printf("\n\n\n");
    system("pause");
    return 0;
    }
    int triangulo(int LA, int LB, int LC){
        
        /*
        LA - Lado A;
        LB - Lado B;
        LC - Lado C;
        result - resultado Final;
        
        Case 0 - Não formam triangulo;
        Case 1 - Triangulo Equilatero;
        Case 2 - Triangulo Escaleno;
        Case 3 - Triangulo Isosceles;
        Case 4 - Triangulo Isosceles;
        Case 5 - Triangulo Isosceles;
        */
        
        int result;
        if((LA+LB<LB)||(LA+LC<LB)||(LC+LB<LA)){
             result = 0;
             }
             else if((LA==LB)&&(LB==LC)){
             result = 1;
             }
             else if((LA!=LB)&&(LB!=LC)){
             result = 2;
             }
             else if((LA==LB)&&(LA!=LC)){
             result = 3;
             }
             else if((LA!=LB)&&(LB==LC)){
             result = 4;
             }
             else if((LA==LC)&&(LB!=LC)){
             result = 5;
             }     
        return result;
        }
