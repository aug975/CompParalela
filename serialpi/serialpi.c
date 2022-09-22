#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

long thread_count = 8;
long long n = 8192*8;
int flag;
double sum;

void* Thread_sum(void* rank);
double Serial_pi(long long n);

int main() {
   long thread;  
   pthread_t* thread_handles;

   thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t)); 

   sum = 0.0;
   flag = 0;
   for (thread = 0; thread < thread_count; thread++)  
      pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);  

   for (thread = 0; thread < thread_count; thread++) 
      pthread_join(thread_handles[thread], NULL); 
  
   sum = Serial_pi(n);
  
   printf("Com n = %lld termos,\n", n);
   printf("   Estimativa de pi  = %.15f\n", sum);
   
   free(thread_handles);
   return 0;
}  /* main */


void* Thread_sum(void* rank) {
   long my_rank = (long) rank;
   double factor;
   long long i;
   long long my_n = n/thread_count;
   long long my_first_i = my_n*my_rank;
   long long my_last_i = my_first_i + my_n;

   if (my_first_i % 2 == 0)
      factor = 1.0;
   else
      factor = -1.0;

   for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
      while (flag != my_rank);
      sum += factor/(2*i+1);  
      flag = (flag+1) % thread_count;
   }

   return NULL;
}  


double Serial_pi(long long n) {
   double sum = 0.0;
   long long i;
   double factor = 1.0;

   for (i = 0; i < n; i++, factor = -factor) {
      sum += factor/(2*i+1);
   }
   return 4.0*sum;
} 
