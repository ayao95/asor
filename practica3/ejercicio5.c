#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {

  char * c;

  printf("identificador de proceso: %i\n", getpid());
  printf("identificador de proceso padre: %i\n", getppid());
  printf("identificador de grupo de procesos: %i\n", getpgid(getpid()));
  printf("identificador de sesion: %i\n", getsid(getpid()));
  struct rlimit limit;
  if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
    printf("Unable to get the resource limits");
    perror(c);
    return -1;
  }
  printf("número máximo de ficheros que puede abrir el proceso: %li\n", limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("directorio de trabajo actual: %s\n", path);
  free (path);

  return 1;
}
