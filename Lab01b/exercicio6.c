#include <stdio.h>

int main() {
  //inicializando srand
  srand(time(NULL));
  
  int nlinhas,ncolunas,i,j,val;
  
  //definimos a matriz por input do usuario
  printf("Informe numero de colunas da matriz: ");
  scanf("%d",&ncolunas);
  printf("Informe numero de linhas da matriz: ");
  scanf("%d",&nlinhas);
  printf("A matriz sera em %d x %d.\n\n",ncolunas,nlinhas);

  int matr[nlinhas][ncolunas],matr2[ncolunas][nlinhas];
  
  //preenchemos a matriz com input do usuario
  for(i = 0; i < nlinhas; ++i){
    for(j = 0; j < ncolunas; ++j){
      printf("Insira valores. Linha %d, coluna %d: ",i+1,j+1);
      scanf("%d",&val);
      matr[i][j] = val;
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

 //fazemos a matriz transposta
  for(i = 0; i < ncolunas; ++i){
    for(j = 0; j < nlinhas; ++j){
      matr2[i][j] = matr[j][i];
    }
  }  

  printf("Encontrando matriz transposta...\n\n");

  //mostramos a matriz transposta
  for(i = 0; i < ncolunas; ++i){
    for(j = 0; j < nlinhas; ++j){
      printf("%d\t",matr2[i][j]);
     }
    printf("\n");
  }
}
