#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>



void printAtributosProceso(char *type){
  char * c;

  printf("%s identificador de proceso: %i\n",type, getpid());
  printf("%s identificador de proceso padre: %i\n", type,getppid());
  printf("%s identificador de grupo de procesos: %i\n",type, getpgid(getpid()));
  printf("%s identificador de sesion: %i\n", type,getsid(getpid()));
  struct rlimit limit;
  if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
    printf("Unable to get the resource limits");
    perror(c);
  }else{
  printf("%s número máximo de ficheros que puede abrir el proceso: %li\n", type,limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("%s directorio de trabajo actual: %s\n", type,path);
  free (path);
  }
  
}

int main() {

  char * c;


  pid_t pid = fork();

  switch (pid) {
    case -1:
      perror("fork");
      exit(1);
    break;
    case 0:;
      pid_t mi_sid = setsid(); //Creamos una nueva sesión
      
      int n = chdir("/tmp"); //Cambiamos el directorio
      if(n==-1){
         printf("Unable to change the directory");
        perror(c);
        return -1;
      }
      printf("[Hijo] Proceso id %i (Su Padre id: %i)\n",getpid(),getppid());
      printAtributosProceso("Hijo");
      sleep(3);
      break;
    default:
      printf("[Padre] Proceso id %i (Su Padre id: %i)\n",getpid(),getppid());
      printAtributosProceso("Padre");
      sleep(3);
      break;
  }

  return 0;
}
