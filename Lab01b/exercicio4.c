#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NOMES 26
#define NOMES_LEN 20
#define PICKNOME 2
#define PICKNOME_LEN 20

int checkPos(const char nome[]){
  const char l = nome[0];
  int n;
  switch(l){
    case 'A': n = 1;
    case 'B': n = 2;
    case 'C': n = 3;
    case 'D': n = 4;
    case 'E': n = 5;
    case 'F': n = 6;
    case 'G': n = 7;
    case 'H': n = 8;
    case 'I': n = 9;
    case 'J': n = 10;
    case 'K': n = 11;
    case 'L': n = 12;
    case 'M': n = 13;
    case 'N': n = 14;
    case 'O': n = 15;
    case 'P': n = 16;
    case 'Q': n = 17;
    case 'R': n = 18;
    case 'S': n = 19;
    case 'T': n = 20;
    case 'U': n = 21;
    case 'V': n = 22;
    case 'W': n = 23;
    case 'X': n = 24;
    case 'Y': n = 25;
    case 'Z': n = 26;   
  }

  return n;
}

int main() {

  //inicializando srand
  srand(time(NULL)); 

  //criamos um array com nomes
  char nomes[NOMES][NOMES_LEN] = { "Antonio", "Beatriz", "Caio", "Denis", "Enzo", "Felipe", "Gabriel", "Henrique", "Isaac", "Joao", "Kris", "Lucas", "Murilo", "Nicole", "Otavio", "Pedro", "Quintela", "Raimundo", "Sophia", "Teresa", "Ulisses", "Valdir", "William", "Xavier", "Yuri", "Zayn"};

  //escolhemos dois nomes
  const char *picknome[PICKNOME],*temp[PICKNOME];
  int n1,n2;
  int flag = 0;
  while (flag == 0){
    n1 = (rand() % (25 - 1 + 1)) + 1;
    n2 = (rand() % (25 - 1 + 1)) + 1;
    if (n1 != n2){flag = 1;}
  }
  picknome[0] = nomes[n1];
  picknome[1] = nomes[n2];
  printf("Nomes a ordenar: %s e %s",picknome[0],picknome[1]);

  //ordenamos os nomes
  int pos1, pos2;
  temp[0] = picknome[0];
  temp[1] = picknome[1];
  pos1 = checkPos(picknome[0]);
  pos2 = checkPos(picknome[1]);

  if (pos1 > pos2){picknome[0] = temp[1];picknome[1] = temp[0]}
  printf("Nomes ordenados: %s, %s",picknome[0],picknome[1]);
}
