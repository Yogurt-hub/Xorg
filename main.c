#include<stdio.h>
#define NUM_NAMES 500

int
main(){

	char *names = "asdas";

	char **ptr = &names;

	printf("%c", *ptr);

	return 0;
}
