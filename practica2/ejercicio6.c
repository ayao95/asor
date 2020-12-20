#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	//mode_t umask(mode_t mask);


	//rwxr-x---
	mode_t pre=umask(027);
	const char PATH[]="/home/usuarioso/ej611.txt";
	char * c;
	//rw-r--r-x
	int res=open(PATH, O_CREAT, 0675);
	printf("Descriptor = %i\n", res);
	perror(c);

	return 1;
}