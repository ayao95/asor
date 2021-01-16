#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char **argv) {
	if (argc != 2) {
    printf("ERROR: parametro incorrecto,introduce PID\n");
    return -1;
  }

  //atoi:converts the string argument str to an integer
  int pid = atoi(argv[1]);
  int scheduler = sched_getscheduler(pid);


  //Planificación
  switch (scheduler) {
    case SCHED_OTHER:
      printf("SCHEDULER: OTHER\n");
    break;
    case SCHED_FIFO:
      printf("SCHEDULER: FIFO\n");
    break;
    case SCHED_RR:
      printf("SCHEDULER: RR\n");
    break;
    default:
      printf("SCHEDULER: ERROR en averiguar la politica\n");
    break;
  }

  //Prioridad
  struct sched_param p;
  sched_getparam(pid,&p);
  printf("PRIORIDAD: %i\n", p.sched_priority);

  //Max y min
  int max = sched_get_priority_max(scheduler);
  int min = sched_get_priority_min(scheduler);
  printf("MAX: %i\n", max);
  printf("MIN: %i\n", min);

  /*ejercicio 3
  usuarioso@ssoo:~/asor/practica3$ ./test 8981
  SCHEDULER: FIFO
  PRIORIDAD: 12
  MAX: 99
  MIN: 1
  */

  return 1;
}
