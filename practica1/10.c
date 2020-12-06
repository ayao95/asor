#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

int main(){

    uid_t uid = getuid();

    printf("UID Real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());

    struct passwd * p= getpwuid(uid);
    if(&p==NULL){
  		printf("ERROR en getpwuid : no encuentra usuario\n");
     	return -1;
    }else{
    	char *name = p->pw_name;
   	    char *dir = p->pw_dir;
        char *des = p->pw_gecos;

        printf("Username: %s\n", name);
        printf("Home: %s\n", dir);
        printf("Descripcion: %s\n",des);
    }

    

  return 1;
}


