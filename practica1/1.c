#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main() {
	char * c;
  int res;
   res=setuid(0);
   if(res==-1){
   	perror(c);
   }
   return 1;
}
