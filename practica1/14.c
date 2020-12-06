#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>


int main(){

  time_t t;
  time(&t);
  struct tm *inf = localtime(&t);

  int year = inf->tm_year+1900;

  printf("Estamos en el año: %i\n", year);
  return 1;
}
