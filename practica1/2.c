#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
  	int res;
   res=setuid(0);
   if(res==-1){

   	printf("Error en setuid con strerror:%s, el numero es %i\n", strerror(errno), errno);
   }
   return 1;
}
