#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

  //inicializando srand
  srand(time(NULL)); 

  //declaramos array
  int array[3][3];

  //criamos o array com um loop for simples
  int i;
  int j;
  for (i = 1; i <= 3; ++i)
  {
    for (j = 1; j <= 3; ++j)
      {
        array[i-1][j-1] = rand() % 10;
      }
  }

  //lemos o array, com uma variavel temp para o menor numero
  //usamos uma variavel temp2 para armazenar a linha
  int temp = array[0][0];
  int temp2;

  printf("Array: \n");
  for(i=0; i<3; i++){
    for(j=0;j<3;j++){
      printf("%d ", array[i][j]);
      if (array[i][j] < temp){
        temp = array[i][j];
        temp2 = i+1;
      }
      if (j==2){
        printf("\n");
      }
    }
  }

  printf("Menor numero do array: %d, na linha %d.",temp,temp2);
}
