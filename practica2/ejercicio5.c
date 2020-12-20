#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	const char PATH[]="/home/usuarioso/ej5.txt";
	char * c;
	//rw-r--r-x
	int res=open(PATH, O_CREAT, 0645);
	printf("Descriptor = %i\n", res);
	perror(c);

	return 1;
}