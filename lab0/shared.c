#include <stdio.h>

int fn_shared() {
	printf("This function had called from shared library.\n");
	return 0;
};
