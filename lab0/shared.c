#include <stdio.h>

int fn_shared() {
	printf("This function has called from shared library.\n");
	return 0;
};
