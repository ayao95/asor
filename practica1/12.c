#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int main(){
	time_t t = time(NULL);

	printf("Seconds since Epoce(1/1/1970 00:00:00 UTC): %li\n", t);

	return 1;
}

