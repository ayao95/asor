#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>



int main(){
  struct utsname buf;
  if (uname (&buf) == -1){
	   //perror(s);
     printf("ERROR %d en uname : %s\n", errno, strerror(errno));
     return -1;
	} else {
    printf("Nombre del Sistema: %s\n", buf.sysname);
    printf("Nodename(Name within some implementation-defined network): %s\n", buf.nodename);
    printf("Release: %s\n", buf.release);
    printf("Version: %s\n", buf.version);
    printf("Machine(Hardware identifier ): %s\n", buf.machine);
   
    
  }
  return 1;
}
