#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


int main(){

    uid_t uid = getuid();

    printf("UID Real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());

  return 1;
}