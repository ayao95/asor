#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>



int main(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
  int start = tv.tv_usec;

  
  for (int i = 0; i < 1000000; i++){}

  //Vuvelve a calcular el tiempo
  gettimeofday(&tv, NULL);
  int end = tv.tv_usec;

  printf("Ha tardado en hacer un bucle de 1 millon de iteraciones: %i (ms) \n", end - start);

  return 1;
}
