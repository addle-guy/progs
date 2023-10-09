#include <stdio.h>

extern int fn_static() {
	printf("This function has called from static library.\n");
	return 0;
};
