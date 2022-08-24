#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOMES 29
#define NOMES_LEN 20

//definimos o tipo pessoa
typedef struct {
  char *nome;
  int idade;
  int peso;
  int altura;
} pessoa;

//criamos funcao para imprimir dados de uma pessoa
void printp(pessoa p){
  printf("NOME: %s\n",p.nome);
  printf("IDADE: %d\n",p.idade);
  printf("PESO: %d\n",p.peso);
  printf("ALTURA: %d\n",p.altura);
}

int main(void) {
  
  //inicializando srand
  srand(time(NULL)); 

  //criamos um vetor de pessoas
  pessoa pessoas[29];
  char escolhas[3][NOMES_LEN];
  pessoa pessoasr[3];

  //criamos uma pessoa placeholder
  pessoa erro;
  erro.nome = "Nao encontrado";
  erro.idade = 0;
  erro.peso = 0;
  erro.altura = 0;
  
  //criamos um array com nomes
  char nomes[NOMES][NOMES_LEN] = { "Antonio", "Beatriz", "Caio", "Denis", "Enzo", "Felipe", "Gabriel", "Henrique", "Isaac", "Joao", "Kris", "Lucas", "Murilo", "Nicole", "Otavio", "Pedro", "Quintela", "Raimundo", "Sophia", "Teresa", "Ulisses", "Valdir", "William", "Xavier", "Yuri", "Zayn","Antenor","Jose","Vanessa"};

  //geramos dados para os individuos no vetor
  for(int i=0;i<29;i++){
    pessoas[i].nome = nomes[i];
    pessoas[i].idade = (rand()%90)+10;
    pessoas[i].peso = (rand()%141)+60;
    pessoas[i].altura = (rand()%60)+140;
  }

  printf("Pessoas na base de dados: Antonio, Beatriz, Caio, Denis, Enzo, Felipe, Gabriel, Henrique, Isaac, Joao, Kris, Lucas, Murilo, Nicole, Otavio, Pedro, Quintela, Raimundo, Sophia, Teresa, Ulisses, Valdir, William, Xavier, Yuri, Zayn, Antenor, Jose, Vanessa\n\n");
  
  //pedimos input do usuario
  printf("Escolha tres nomes.\n");
  printf("Nome 1: "); 
  scanf(" %s", escolhas[0]);
  printf("Nome 2: "); 
  scanf(" %s", escolhas[1]);
  printf("Nome 3: "); 
  scanf(" %s", escolhas[2]);
  int error = 0;

  //verificamos se os nomes estao na base de dados
  //se estiverem, passamos para um array auxiliar
  //se nao estiverem, avisamos o usuario e colocamos no seu lugar um placeholder
  for(int j=0;j<3;j++){
    for(int i=0;i<29;i++){
      if(!strcmp(pessoas[i].nome, escolhas[j])){
        pessoasr[j] = pessoas[i];
        break;
      }
      else{error++;}
    }
    if(error>=29){printf("Um nome nao foi encontrado.\n");pessoasr[j] = erro;}
    error=0;
  }
  printf("\n");

  //mostramos o array auxiliar de resultados por meio da funcao printp
  for(int j=0;j<3;j++){printf("Pessoa %d--- ''%s''\n",j+1,escolhas[j]);printp(pessoasr[j]);printf("\n");}
}
