
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv) {


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}


  int fd = open(argv[1], O_CREAT | O_RDWR, 0777);
  char * c;
  if (fd == -1) {
    perror(c);
    return -1;
  }



  int fd2 = dup2(fd, 1);

   printf("Esto se ha reedirigido a %s\n", argv[1]);
   printf("Comenzamos con la prueba en %s\n", argv[1]);
   printf("Fin \n");

  return 1;
}
