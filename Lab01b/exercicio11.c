#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void soma(int nlinhas, int ncolunas, int matriz[nlinhas][ncolunas]){
  int matr2[nlinhas][ncolunas];

  //preenchemos a matriz auxiliar
  for(int i = 0; i < nlinhas; ++i){
    for(int j = 0; j < ncolunas; ++j){
      matr2[i][j] = matriz[i][j];
    }
  }
  
  //colocamos soma na linha 2
  for(int j = 0; j < ncolunas; ++j){
      matr2[1][j] = matriz[0][j]+matriz[1][j];
  }

  printf("Somando linha 1 e linha 2...\n\n");

  //mostramos a matriz resultante
  for(int i = 0; i < nlinhas; ++i){
    for(int j = 0; j < ncolunas; ++j){
      printf("%3d\t",matr2[i][j]);
     }
    printf("\n");
  }
}

void multip(int nlinhas, int ncolunas, int matriz[nlinhas][ncolunas]){
  int matr3[nlinhas][ncolunas];

  //preenchemos a matriz auxiliar
  for(int i = 0; i < nlinhas; ++i){
    for(int j = 0; j < ncolunas; ++j){
      matr3[i][j] = matriz[i][j];
    }
  }
  
  //colocamos produto na linha 2
  for(int j = 0; j < ncolunas; ++j){
      matr3[1][j] = matriz[0][j]*matriz[1][j];
  }

  printf("Multiplicando linha 1 por linha 2...\n\n");

  //mostramos a matriz resultante
  for(int i = 0; i < nlinhas; ++i){
    for(int j = 0; j < ncolunas; ++j){
      printf("%5d",matr3[i][j]);
     }
    printf("\n");
  }
}

int main() {
  //inicializando srand
  srand(time(NULL));
  
  int i,j,nlinhas,ncolunas;;
  
  //geramos matriz
  ncolunas = 1+rand()%9;
  nlinhas = 2;
  printf("\nGerando matriz...\n");

  int matr[nlinhas][ncolunas];
  
  //preenchemos a matriz gerada
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      matr[i][j] = 1+rand()%101;
    }
  }

  printf("\n");

  //mostramos a matriz preenchida
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      printf("%3d\t",matr[i][j]);
     }
    printf("\n");
  }
  printf("\n");

  soma(nlinhas,ncolunas,matr);
  printf("\n");
  multip(nlinhas,ncolunas,matr);
}
