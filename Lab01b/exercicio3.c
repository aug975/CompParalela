#include <stdio.h>

int main() {

  //pedimos o numero maximo da piramide
  int Max;
  int flag = 0;
  //usamos um loop while para manter o input checando por impar
  while (flag == 0){
    printf("Informe numero maximo (impar): ");
    scanf("%d", &Max); 
    printf("\n");
    if (Max % 2 != 0){flag = 1;}
    else {printf("Informe um numero impar!\n");}
  }
 
  //geramos e populamos vetor
  int vetor[Max];
  int i;
  
  for (i = 0;i < Max;i++){vetor[i]=i+1;}
  
  //algoritmo gerador de piramide
  int j;
  int k;
  int l;

  for (j = 0;j < Max;j++){
    for (k = 0;k < Max-j*2;k++){
      printf("%d",vetor[k+j]);
    }
    if (Max-j*2 <= 0){break;}
    printf("\n");
    for (l = 0;l <= j;l++){printf(" ");}
  }
}
