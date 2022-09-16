#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//var globais
int numthreads,tam1,tam2;
double* matriz;
double* vetor;
double* resultado;

//funcoes para criar vetor/matriz com numeros aleatorios
void criarvetor(double *res,int tam){
   int i,j;
   for (i=0;i<tam;++i){
    res[i] = random()%100;
  }
}
void criarmatriz(double *res,int tam1,int tam2){
   int i,j;
   for (i=0;i<tam1;++i){
      for (j=0;j<tam2;j++){
        res[i*tam2+j] = random()%100;
      }
   }
}

//funcoes para imprimir vetor/matriz
void mostrarMatriz(double matriz[],int tam1,int tam2){
  int i,j;
  for (i = 0; i < tam1; i++){
    for (j = 0; j < tam2; j++){
      printf("%2.1f ", matriz[i*tam2+j]);}
    printf("\n");
  }
}
void mostrarVetor(double vetor[], double tam1){
  int i;
  for (i = 0; i < tam1; i++){
    printf("%2.1f ", vetor[i]);}
  printf("\n");
}

//funcao mat_vect
void *Pth_mat_vect(void* rank){
  int i,j;
  long my_rank = (long) rank;
  int local_tam1 = tam1/numthreads;
  int local_tam2 = tam2/numthreads;
  int my_first_row,my_last_row,my_first_column,my_last_column;
  double* local_resultado;
  double* local_matriz;
  
  if(my_rank<(tam1%numthreads)){
	local_tam1++;
	my_first_row = my_rank*local_tam1;
  my_last_row = (my_rank+1)*local_tam1-1;
  }
    
  else{
    my_first_row = my_rank*local_tam1+(tam1%numthreads);
    my_last_row = (my_rank+1)*local_tam1-1+(tam1%numthreads);
  }

  if(my_rank < (tam2 % numthreads)){
	  local_tam2++;
	  my_first_column = my_rank*local_tam2;
    my_last_column = (my_rank+1)*local_tam2-1;
  }
  
  else{ 
    my_first_column = my_rank*local_tam2+(tam2%numthreads);
    my_last_column = (my_rank+1)*local_tam2-1+(tam2%numthreads);
  }
  
  local_matriz = malloc(local_tam1*tam2*sizeof(double));
  local_resultado = malloc(local_tam2*sizeof(double));

  for(i=0;i<local_tam1;i++){
    for(j=0;j<tam2;j++){
	    local_matriz[i*tam2+j] = matriz[my_first_row*tam2+j];}
    my_first_row++; 
  }
  for(i=0;i<local_tam1;i++){
    local_resultado[i]=0.0;
    for(j=0;j<local_tam2;j++){
      local_resultado[i] +=local_matriz[i*tam2+j]*vetor[j];}
  }

  for(i=0;i<local_tam2;i++){
	  resultado[my_first_column] = local_resultado[i];
    my_first_column++;
  }
  return NULL;
}

int main(int argc, char* argv[]) {
  long thread;
  pthread_t* threadh;
  numthreads = atoi(argv[1]);
  threadh = malloc(numthreads*sizeof(pthread_t));

  printf("Digite dois numeros para ordem da matriz\n");
  scanf("%d%d", &tam1, &tam2);

  matriz = malloc(tam1*tam2*sizeof(double));
  vetor = malloc(tam2*sizeof(double));
  resultado = malloc(tam1*sizeof(double));
   
  criarmatriz(matriz,tam1,tam2);
  criarvetor(vetor,tam2);

  for(thread=0;thread<numthreads;thread++){
    pthread_create(&threadh[thread],NULL,Pth_mat_vect,(void*) thread);}
  for(thread=0;thread<numthreads;thread++){
    pthread_join(threadh[thread],NULL);}

  printf("Matriz: \n");
  mostrarMatriz(matriz,tam1,tam2);
  printf("\nVetor: \n");
  mostrarVetor(vetor,tam1);
  printf("\nResultado: \n");
  mostrarVetor(resultado,tam1);
  free(matriz);
  free(vetor);
  free(resultado);
  return 0;
}
