
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char **argv) {
  char * c;
	if (argc != 2) {
    printf("ERROR: Introduce los segundos!\n");
    return -1;
  }

  sigset_t set;

  //Inicializamos un conjunto de señales y añadimos las señales de int y tstp
  if(sigemptyset(&set)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigemptyset.\n");
    perror(c);
    return -1;
  }
  if(sigaddset(&set, SIGTSTP)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigaddset SIGTSTP.\n");
    perror(c);
    return -1;
  }
  if(sigaddset(&set, SIGINT)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigaddset SIGTINT.\n");
    perror(c);
    return -1;
  }

  //Protegemos la región de código contra la recepción de las señales
  if(sigprocmask(SIG_BLOCK, &set, NULL)==-1){
     printf("ERROR: No se ha ejecutado correctamente sigprocmask.\n");
    perror(c);
    return -1;
  }

  //Obtenemos la variable de entorno
  char *sleep_secs = getenv("SLEEP_SECS");
  int secs = atoi(sleep_secs);
  printf("Se va a dormir el proceso durante %d segundo(s)\n", secs);
  //Dormimos el proceso
  sleep(secs);

  //Comprobamos las señales pendientes
  sigset_t pending;
  if(sigpending(&pending)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigpending.\n");
    perror(c);
    return -1;
  }

  if (sigismember(&pending, SIGINT) == 1) {
    printf("Se ha recibido la señal SIGINT\n");

    //Eliminamos la señal del conjunto anterior
    sigdelset(&set, SIGINT);

  } else {
      printf("No se ha recibido la señal SIGINT\n");
  }
  if (sigismember(&pending, SIGTSTP) == 1) {
    printf("Se ha recibido la señal SIGTSTP\n");

    //Eliminamos la señal del conjunto anterior
    sigdelset(&set, SIGTSTP);
  } else {
    printf("No se ha recibido la señal SIGTSTP\n");
  }

  sigprocmask(SIG_UNBLOCK, &set, NULL);
   printf("Finish\n");

  return 0;
}
