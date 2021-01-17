
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define PIPE_W 1
#define PIPE_R 0

int main(int argc, char** argv){

  char * c;

  if (argc < 3) {
    printf("Error: Introduce los comandos\n");
  }
  //creamos tuberia
  int fd[2];
  int pip = pipe(fd);

  switch (fork()) {
    case -1:
      printf("ERROR al hacerl el fork");
      perror(c);
      return -1;
      break;
    case 0:
    //Hijo
      dup2(fd[PIPE_R],0); //Cambiamos el descriptor a la entrada.
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      if(execlp(argv[3],argv[3],argv[4])==-1){
        printf("ERROR al hacer execlp\n");
        perror(c);
        return -1;
      }
    break;
    default:
    //Padre
      dup2(fd[PIPE_W],1); //Cambiamos el descriptor a la entrada.
      close(fd[PIPE_W]);
      close(fd[PIPE_R]);
      if(execlp(argv[1],argv[1],argv[2])==-1){
        printf("ERROR al hacer execlp\n");
        perror(c);
        return -1;
      }
    break;
  }

  return 0;

}
