#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  //inicializando srand
  srand(time(NULL));

  //gerar str100
  char str[100] = "aaAAbbBBccCCddDDeeEEffFFggGGhhHHiiIIjjJJkkKKllLLmmMMnnNNooOOppPPqqQQrrRRssSSttTTuuUUvvVVwwWWxxXXyyY";
  char str2[101];

  int pos;
  //gerar caracter aleatoria para insercao
  char caract = 'a' + (random() % 26);
  
  //pedir posicao do usuario
  printf("String inicial: %s\n",str);
  printf("Caractere gerado: %c\n\n",caract);
  printf("Informe posicao para insercao (0-98): ");
  scanf("%d",&pos);
  putchar('\n');

  //copiar caracteres ate a posicao para a string auxiliar
  //inserir caracter gerada na posicao
  //caracteres depois puxam da anterior
  for(int i=0;i<pos;i++){
    str2[i] = str[i];
  }

  str2[pos] = caract;
  
  for(int i=pos+1;i<101;i++){
    str2[i] = str[i-1];
  }

  printf("String resultante: %s\n\n",str2);
  
}
