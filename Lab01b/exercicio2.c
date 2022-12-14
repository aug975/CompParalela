#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main() {

  //inicializando srand
  srand(time(NULL));
  
  //geramos aleatoriamente as notas do aluno
  float N1 = (fmod(rand(),10) + (fmod(rand(),10))/10);
  float N2 = (fmod(rand(),10) + (fmod(rand(),10))/10);
  float N3 = (fmod(rand(),10) + (fmod(rand(),10))/10);
  float ME = (fmod(rand(),10) + (fmod(rand(),10))/10);

  printf("Notas do aluno: \n N1 = %.2f \n N2 = %.2f \n N3 = %.2f \n ME = %.2f \n",N1,N2,N3,ME);
  
  //calculamos a media
  float MA = (N1 + N2*2 + N3*3 + ME)/7;

  printf("MA = %.2f\n",MA);
  
  //verificamos o conceito
  char conceito;
  if(MA >= 9){conceito = 'A';}
  else if(MA >= 7.5 && MA < 9){conceito = 'B';}
  else if(MA >= 6 && MA < 7.5){conceito = 'C';}
  else if(MA >= 4 && MA < 6){conceito = 'D';}
  else{conceito = 'E';}

  printf("Avaliacao final do aluno: %c",conceito);
}
