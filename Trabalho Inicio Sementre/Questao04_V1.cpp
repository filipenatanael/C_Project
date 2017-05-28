#include <stdio.h>
#include <stdlib.h>

int main(void){
    float mediano(int NP,int NS,int NT,int NQ);
    float situacao(float notas);
    int Aluno[10],NPS[10],NSS[10],NTS[10],NQS[10];
    //Aluno[10] - Numero do Aluno;
    //NPS[10] - Nota Primeira Avaliação;
    //NSS[10] - Nota Segunda Avaliação;
    //NTS[10] - Nota Terceiro Avaliação;
    //NQS[10] - Nota Terceiro Avaliação;
    float MEDIA[10];
    for(int x=0; x<=2; ++x){
          printf("\nInforme Numero do Aluno: ");
          scanf("%i",&Aluno[x]);
         
          printf("\n1 NOTA: ");
          scanf("%i",&NPS[x]);
          printf("\n2 NOTA: ");
          scanf("%i",&NSS[x]);
          printf("\n3 NOTA: ");
          scanf("%i",&NTS[x]);
          printf("\n4 NOTA: ");
          scanf("%i",&NQS[x]);
          MEDIA[x]= mediano(NPS[x],NSS[x],NTS[x],NQS[x]);
          }
          bool VR; //VR - Verificador;
          for(int y=2; y<=0; ++y){ 
          VR = situacao(MEDIA[y]);
          if(VR == true){
                 printf("\nAluno: %i Media: %f Situacao: Aprovado",Aluno[y],MEDIA[y]);
                 }
                 else{
                      printf("\nAluno: %i Media: %f Situacao: Reprovado",Aluno[y],MEDIA[y]);
                      }
         
          }
          
    printf("\n\n");
    system("pause");
    return 0;
    }
    float mediano(int NP,int NS,int NT,int NQ){
          //NP - Nota Primeira Avaliação;
          //NS - Nota Segunda Avaliação;
          //NT - Nota Terceiro Avaliação;
          //NQ - Nota Terceiro Avaliação;
          float MD; //MD - Abreviação de MEDIA
          MD =(NP+NS+NT+NQ)/4;
          return MD;
          }//----------------------------------------------
          float situacao(float notas){
               bool verificador;
               if(notas>=6){
                  verificador = true; //Então se o aluno for aprovado o auxiliar-verificador e verdadeiro;         
                  }
                  else{
                       verificador = false;
                       }
                return verificador;
                }
