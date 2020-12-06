#include <stdio.h>
#include <errno.h>
#include <unistd.h>
int main(){
   printf("Longitud máxima de aqrgumentos: %li\n", sysconf(_SC_ARG_MAX));
	printf("Número máximo de hijos: %li\n", sysconf(_SC_CHILD_MAX));
	printf("Número máximo de ficheros: %li\n", sysconf(_SC_OPEN_MAX));
  return 1;
}