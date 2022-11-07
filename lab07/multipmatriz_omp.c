#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int N = 2;
int M = 2;
int P = 2;

void mostrarMatriz(int matriz[],int tam1,int tam2){
  int i,j;
  for (i = 0; i < tam1; i++){
    for (j = 0; j < tam2; j++){
      printf("%d ", matriz[i*tam2+j]);}
    printf("\n");
  }
}

int main(int argc , char * argv []){
  srand(time(NULL));
  int thread_count;
  thread_count = strtol ( argv [1] , NULL , 10);
  unsigned long i, j, k;
  int A[N][P];
  int B[P][M];
  int matres[N][M];

  for (i = 0;i < N; i++)
    for (k = 0; k < P; k++)
      A[i][k] = rand()%100;
  for (k = 0;k < P; k++)
    for (j = 0; j < M; j++)
      B[k][j] = rand()%100;
  for (i = 0;i < N; i++)
    for (j = 0; j < M; j++)
      matres[i][j] = 0;

  
  #pragma omp shared(A,B,matres) private(i,j,k)
  #pragma omp parallel num_threads(thread_count)
  {
    #pragma omp for schedule (static)
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        for (k = 0; k < P; k++) {
          matres[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    
  }
  printf("Matriz A:\n");
  mostrarMatriz(*A,N,P);
  printf("Matriz B:\n");
  mostrarMatriz(*B,P,M);
  printf("Matriz resultado:\n");
  mostrarMatriz(*matres,N,M);
  return 0;
}
