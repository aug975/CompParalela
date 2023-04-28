// Começamos essa atividade antes dela ser definida para o dia 20/04
// e, como ambos não comparecemos à aula do dia em questão, provavelmente
// estamos implementando com uma lógica diferente da que foi dada em sala de aula,
// mas está funcionando e esperamos que não haja problema devido a isso.

// Augusto Rassi Scrideli 42023092
// Amanda Laís Xavier Fontes - 31949436

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// Funcao que recebe um vetor de float e retorna o maior elemento
float maior(float vet[], int size) {
	float aux = vet[0];
	for (int i = 1; i < (size); ++i) {
    if (aux < vet[i]) {
      aux = vet[i];
    }
  }
	return aux;
}

int main(int argc, char** argv) {
	// conjunto de dados
	float data[] = {25.5, 53.17, 53.65, 75.8, 75.9, 24.67, 11.98, 50.70, 75.84, 45.22, 98.11, 67.55, 82.76, 39.99, 54.33, 91.02};
	
  // Inicializar o MPI
  MPI_Init(&argc, &argv);
  // Descobrir rank e worldsize
  int my_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Pelo menos 2 processos
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Finalize();
  }
	
  float number;
  float number2;
  if (my_rank == 0) {
		// Receber parte do conjunto de dados
		float vet0[] = {data[0],data[1],data[2],data[3]};
		// Determinar maior
		number = maior(vet0,(sizeof vet0 / sizeof *vet0));
		// Enviar para o rank final
    MPI_Send(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_FLOAT, 
      /* destination  = */ 3, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD);
  } else if (my_rank == 1) {
		// Receber parte do conjunto de dados
		float vet1[] = {data[4],data[5],data[6],data[7]};
		// Determinar maior
		number = maior(vet1,(sizeof vet1 / sizeof *vet1));
    // Enviar para o rank final
    MPI_Send(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_FLOAT, 
      /* destination  = */ 3, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD);
	} else if (my_rank == 2) {
		// Receber parte do conjunto de dados
		float vet2[] = {data[8],data[9],data[10],data[11]};
		// Determinar maior
		number = maior(vet2,(sizeof vet2 / sizeof *vet2));
    // Enviar para o rank final
    MPI_Send(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_FLOAT, 
      /* destination  = */ 3, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD);
	} else if (my_rank == 3) {
		float vetfinal[4];
		// Receber parte do conjunto de dados
		float vet3[] = {data[12],data[13],data[14],data[15]};
		// Determinar maior
		vetfinal[0] = maior(vet3,(sizeof vet3 / sizeof *vet3));
    // Receber dos outros ranks
    MPI_Recv(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_FLOAT, 
      /* source       = */ 0, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD, 
      /* status       = */ MPI_STATUS_IGNORE);
		vetfinal[1] = number;
		MPI_Recv(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_FLOAT, 
      /* source       = */ 1, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD, 
      /* status       = */ MPI_STATUS_IGNORE);
		vetfinal[2] = number;
		MPI_Recv(
      /* data         = */ &number, 
      /* count        = */ 1, 
      /* datatype     = */ MPI_FLOAT, 
      /* source       = */ 2, 
      /* tag          = */ 0, 
      /* communicator = */ MPI_COMM_WORLD, 
      /* status       = */ MPI_STATUS_IGNORE);
		vetfinal[3] = number;
		// Soma final e imprimir resultado
		number2 = maior(vetfinal,(sizeof vetfinal / sizeof *vetfinal));
		printf("Maior numero: %.2f",number2);
	}
  MPI_Finalize();
}