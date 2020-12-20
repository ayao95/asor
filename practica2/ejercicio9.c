#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>


int main(int argc, char **argv){


	if (argc < 2) {
		 printf("ERROR: Se debe especeficar la ruta del archivo en los parámetros del programa.\n");
		 return -1;
	}

	struct stat st;
	int res=stat(argv[1],&st);
	char * c;
	perror(c);

	//Major y Minor

	printf("MAJOR: %li\n", (long) major(st.st_dev));
	printf("MINOR: %li\n", (long) minor(st.st_dev));

	//I-Node
	printf("I-Node: %li\n",st.st_ino);

	//Tipo de archivo
	printf("MODE: %i\n",st.st_mode);

	mode_t mode = st.st_mode;

	if (S_ISLNK(mode)){
		printf("%s es un enlace simbólico.\n", argv[1]);
	} else if (S_ISREG(mode)) {
		printf("%s es un archivo ordinario.\n", argv[1]);
	} else if (S_ISDIR(mode)) {
		printf("%s es un directorio.\n", argv[1]);
	}

	time_t t = st.st_atime;

	struct tm *tm= localtime(&t);

	printf("Últime acceso : %d:%d\n", tm->tm_hour, tm->tm_min);

	return 1;


}