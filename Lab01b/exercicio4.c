#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NOMES 26
#define NOMES_LEN 20
#define PICKNOME 2
#define PICKNOME_LEN 20

//funcao para retornar ascii de um caractere
int ascii(const char ch){
  int aux,n;
  aux = tolower(ch);
  n = (int) aux;
  return n;
}

int main() {

  //inicializando srand
  srand(time(NULL)); 

  //criamos um array com nomes
  char nomes[NOMES][NOMES_LEN] = { "Antonio", "Beatriz", "Caio", "Denis", "Enzo", "Felipe", "Gabriel", "Henrique", "Isaac", "Joao", "Kris", "Lucas", "Murilo", "Nicole", "Otavio", "Pedro", "Quintela", "Raimundo", "Sophia", "Teresa", "Ulisses", "Valdir", "William", "Xavier", "Yuri", "Zayn"};

  //escolhemos dois nomes
  const char *picknome[PICKNOME],*temp[PICKNOME];
  int n1,n2,iter;
  int flag = 0;
  while (flag == 0){
    n1 = (rand() % (25 - 1 + 1)) + 1;
    n2 = (rand() % (25 - 1 + 1)) + 1;
    if (n1 != n2){flag = 1;}
  }
  picknome[0] = nomes[n1];
  picknome[1] = nomes[n2];
  printf("Nomes a ordenar: %s e %s\n",picknome[0],picknome[1]);

  //transferimos os nomes em forma de ascii para arrays
  int asc1[strlen(picknome[0])];
  int asc2[strlen(picknome[1])];
  
  for (iter=0;iter<=strlen(picknome[0])-1;iter++){
    asc1[iter] = ascii(picknome[0][iter]);
  }
  for (iter=0;iter<=strlen(picknome[1]-1);iter++){
    asc2[iter] = ascii(picknome[1][iter]);
  }

  //determinamos o menor array
  size_t len1 = sizeof(asc1)/sizeof(asc1[0]);
  size_t len2 = sizeof(asc2)/sizeof(asc2[0]);
  int flag2 = len1 > len2 ? 2 : 1;
  
  int menor = 1;
  if (flag2 == 2){
    for (int m = 0;m <= len2;m++){
      if (asc1[m] < asc2[m]){menor = 1;break;}
      else if(asc1[m] > asc2[m]){menor = 2;break;}
    }
  }
  else{
    for (int m = 0;m <= len1;m++){
      if (asc1[m] < asc2[m]){menor = 1;break;}
      else if(asc1[m] > asc2[m]){menor = 2;break;}
    }
  }

  //retornamos os nomes ordenados com base no menor determinado
  switch(menor){
    case 1: {printf("Nomes ordenados: %s e %s",picknome[0],picknome[1]);
      break;
      }
    case 2: printf("Nomes ordenados: %s e %s",picknome[1],picknome[0]);
  }
}
