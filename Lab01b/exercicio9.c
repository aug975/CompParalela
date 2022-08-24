#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void modulo(int nlinhas,int ncolunas,int matriz[nlinhas][ncolunas]){
  int matr2[nlinhas][ncolunas];
  
  //convertemos todos os valores para modulo
  for(int i = 0; i < nlinhas; ++i){
    for(int j = 0; j < ncolunas; ++j){
      matr2[i][j] = abs(matriz[i][j]);
    }
  }

  printf("Transformando em modulo...\n\n");

  //mostramos a matriz convertida
  for(int i = 0; i < nlinhas; ++i){
    for(int j = 0; j < ncolunas; ++j){
      printf("%d\t",matr2[i][j]);
     }
    printf("\n");
  }
}

int main() {
  //inicializando srand
  srand(time(NULL));
  
  int nlinhas,ncolunas,i,j;
  
  //geramos matriz
  ncolunas = 1+rand()%9;
  nlinhas = 1+rand()%9;
  printf("\nGerando matriz...\n");

  int matr[nlinhas][ncolunas];
  
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

  modulo(nlinhas,ncolunas,matr);
  
}
