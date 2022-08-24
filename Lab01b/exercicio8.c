#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void transposta(int nlinhas, int ncolunas, int matriz[nlinhas][ncolunas]){
  int matr2[ncolunas][nlinhas];
  
  //fazemos a matriz transposta
  for(int i = 0; i < ncolunas; ++i){
    for(int j = 0; j < nlinhas; ++j){
      matr2[i][j] = matriz[j][i];
    }
  }  

  printf("Encontrando matriz transposta...\n\n");

  //mostramos a matriz transposta
  for(int i = 0; i < ncolunas; ++i){
    for(int j = 0; j < nlinhas; ++j){
      printf("%d\t",matr2[i][j]);
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
  nlinhas = 1+rand()%9;
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
      printf("%d\t",matr[i][j]);
     }
    printf("\n");
  }
  printf("\n");

  transposta(nlinhas,ncolunas,matr);
}
