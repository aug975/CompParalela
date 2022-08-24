#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRINGS 10
#define STRINGS_MAX 15

void procch(char *string,char caract){
  char *chara;
  int index;

  //checar por caract em string por meio do comando strchr
  //passar para inteiro em index indicando a posicao
  chara = strchr(string, caract);
  index = (int)(chara - string);

  //retorna posicao caso encontrada
  if(chara == NULL){printf("Nenhuma ocorrencia da letra %c na string.",caract);}
  else{printf("Primeira ocorrencia da letra %c na posicao %d.",caract,index+1);}
}

int main(void) {
  //inicializando srand
  srand(time(NULL));

  //gerar array de strings
  char frases[STRINGS][STRINGS_MAX] = {"centrifugamos", "denticularmos", "deslumbrativo", "fundilharemos", "obscurantizem", "subclaviforme", "penduricalhos", "genuflictamos", "improfundavel", "encruzilhamos"};

  //gerar caracter para busca aleatoriamente
  //escolher string do array aleatoriamente
  char caract = 'a' + (random() % 26);
  int r = random()%10;
  char *string = frases[r];
  
  printf("String gerada: '%s'\n",string);
  printf("Caracter a ser encontrada: '%c'\n\n",caract);

  //chamar funcao
  procch(string,caract);
}
