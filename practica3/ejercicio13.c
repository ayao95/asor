
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int stop = 0;

void hler(int senial){
  if (senial == SIGUSR1) stop = 1;
}

int main(int argc, char **argv) {

  char  * c;
	if (argc != 2) {
    printf("ERROR: Introduce los segundos!\n");
    return -1;
  }

  sigset_t mask;
  if(sigemptyset(&mask)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigemptyset.\n");
    perror(c);
    return -1;
  }
	if(sigaddset(&mask, SIGUSR1)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigaddset SIGUSR1.\n");
    perror(c);
    return -1;
  }
  if(sigprocmask(SIG_UNBLOCK, &mask, NULL)==-1){
    printf("ERROR: No se ha ejecutado correctamente sigprocmask.\n");
    perror(c);
    return -1;
  }

  struct sigaction act;
  //Sigint
  sigaction(SIGUSR1, NULL, &act); //Get handler
  act.sa_handler = hler;
  sigaction(SIGUSR1, &act, NULL); //Set sa_handler

  int secs = atoi(argv[1]);

  int i = 0;
	while (i < secs && stop == 0) {
    i++;
    sleep(1);
  }

  if (stop == 0) {
    printf("Se va a borrar%s\n",argv[0]);
    unlink(argv[0]);
  } else {
    printf("Se ha detenido borrar!\n");
  }

  return 0;
}
