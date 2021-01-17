#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){

  char * c;

  if (argc < 2) {
    printf("ERROR: Introduce el comando que deseas ejecutar.\n");
    return -1;
  }

  //Ejecutamos el comando correspondiente a la entrada por argumentos
  if (execvp(argv[1], argv) == -1) {
    printf("ERROR: No se ha ejecutado el comando correctamente.\n");
    perror(c);
  }
  else{
      printf("El comando terminó de ejecutarse.\n");
  }



  return 0;
}
