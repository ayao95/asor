#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main(){
	//char p[]="/ejemplos";
   printf("Número máximo de enlaces: %li\n", pathconf("/ejemplos",_PC_LINK_MAX));
	printf("Tamaño máximo de una ruta: %li\n", pathconf("/ejemplos",_PC_PATH_MAX));
	printf("Tamaño máximo de nombre de ficheros: %li\n", pathconf("/ejemplos",_PC_LINK_MAX));
  return 1;
}