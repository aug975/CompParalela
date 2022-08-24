#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  //inicializando srand
  srand(time(NULL));
  
  int nlinhas,ncolunas,i,j;
  
  //geramos matriz
  ncolunas = 1+rand()%9;
  nlinhas = 1+rand()%9;
  printf("\nGerando matriz...\n");

  int matr[nlinhas][ncolunas],matr2[ncolunas][nlinhas];
  
  //preenchemos a matriz gerada
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      matr[i][j] = 50-rand()%101;
    }
  }

  printf("\n");

  //mostramos a matriz preenchida
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      printf("%d\t",matr[i][j]);
     }
    printf("\n");
  }
  printf("\n");

 //convertemos todos os valores para modulo
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      matr2[i][j] = abs(matr[i][j]);
    }
  }

  printf("Transformando em modulo...\n\n");

  //mostramos a matriz convertida
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      printf("%d\t",matr2[i][j]);
     }
    printf("\n");
  }
}
