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
  char str2[100];

  int pos;
  //pedir posicao do usuario
  printf("String inicial: %s\n\n",str);
  printf("Informe posicao a ser removida (0-98): ");
  scanf("%d",&pos);
  putchar('\n');

  //copiar caracteres ate a posicao para a string auxiliar
  //caracteres depois puxam da proxima
  for(int i=0;i<pos;i++){
    str2[i] = str[i];
  }
  for(int i=pos;i<100;i++){
    str2[i] = str[i+1];
  }

  printf("String resultante: %s\n\n",str2);
  
}
