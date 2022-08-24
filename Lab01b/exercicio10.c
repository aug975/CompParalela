#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void multip(int size,int matr[size][size]){
  int matr2[size][size];
  int choic,choic2;
  char opt;
  
  //perguntamos ao usuario qual linha ou coluna a multiplicar
  input:
  printf("Multiplicar linha ou coluna? [l/c]: ");
  scanf(" %c",&opt);
  switch(opt){
    case 'l': inputl:printf("Qual linha? ");break;
    case 'c': inputc:printf("Qual coluna? ");break;
    default: printf("Escolha 'l' ou 'c'!\n");goto input;
  }

  //verificamos escolha
  scanf("%d",&choic);
  if((choic <1 || choic > size)&&(opt == 'l')){printf("Informe uma linha valida!\n");goto inputl;}
  else if((choic <1 || choic > size)&&(opt == 'c')){printf("Informe uma coluna valida!\n");goto inputc;}

  printf("\n");

  //passamos os valores para uma matriz auxiliar
  int num;
  gerar:
  
  for (int i=0;i < size;i++){
    for (int j=0;j < size;j++){
      matr2[i][j] = matr[i][j];
    }
  }
  
  //geramos um numero aleatorio ate 100 para a multiplicacao
  num = rand() % 100;
  printf("Multiplicando por %d...\n",num);

  //multiplicamos a linha ou coluna escolhida
  if(opt == 'l'){for(int j=0;j<size;j++){matr2[choic-1][j] *= num;}}
  else if(opt == 'c'){for(int j=0;j<size;j++){matr2[j][choic-1] *= num;}}

  //mostramos a matriz resultante
  for (int i=0;i < size;i++){
    for (int j=0;j < size;j++){
      printf("%d ",matr2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  //inicializando srand
  srand(time(NULL));
  
  int size,i,j,val;
  
  //definimos a matriz por input do usuario
  printf("Informe tamanho da matriz: ");
  scanf("%d",&size);
  printf("A matriz sera em %d x %d.\n\n",size,size);

  int matr[size][size];
  
  //preenchemos a matriz com input do usuario
  for (i=0;i < size;i++){
    for (j=0;j < size;j++){
      printf("Insira valores. Linha %d, coluna %d: ",i+1,j+1);
      scanf("%d",&val);
      matr[i][j] = val;
    }
  }
  printf("\n");

  //mostramos a matriz preenchida
  for (i=0;i < size;i++){
    for (j=0;j < size;j++){
      printf("%d ",matr[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  multip(size,matr);
  
}
