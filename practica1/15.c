#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <locale.h>


int main(){

	

  time_t t;
  time(&t);
  struct tm *inf = localtime(&t);


  char buf[100];
  setlocale(LC_ALL,"es_ES");
  strftime(buf, 100, "%A, %d de %B de %G, %H:%M", inf);
  printf("%s\n", buf);
  return 1;
}
