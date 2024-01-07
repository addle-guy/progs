#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	FILE* logf = fopen("log.txt", "w"); 
	
	while (1) {
		int a1, a2, a3;
		
		printf("\nEnter a numbers: \n");
		if (scanf("%d", &a1) != 1) { printf("Incorrect input!\n"); scanf("%*[^\n]"); continue; }
		if (scanf("%d", &a2) != 1) { printf("Incorrect input!\n"); scanf("%*[^\n]"); continue; }
		if (scanf("%d", &a3) != 1) { printf("Incorrect input!\n"); scanf("%*[^\n]"); continue; }
		if (!a1 && !a2 && !a3) { printf("Exit...\n"); break; }
		
		int* bg = &a1; int bgi = 1;
		if (a2 > *bg) { bg = &a2; bgi = 2; };
		if (a3 > *bg) { bg = &a3; bgi = 3; };
		
		if (*bg % 2 == 0) {
			printf("Biggest number is even.\n");
			printf("Biggest number: %d\n", bgi);
			float result = (double)abs(*bg) / (abs(a1) + abs(a2) + abs(a3)) * 100;
			printf("Result is: %.2f%%\n", result);
			fprintf(logf, "a1 = %d a2 = %d a3 = %d res = %.2f\n", a1, a2, a3, result);

		} else {
			printf("Biggest number is not even.\n");
			int* sml = &a1; int smli = 1;
			if (a2 < *sml) { sml = &a2; smli = 2; };
			if (a3 < *sml) { sml = &a3; smli - 3; };
			int result = *bg - *sml;
			printf("Biggest number: %d, smallest number: %d\n", bgi, smli);
			printf("Result is: %d\n", result);
			fprintf(logf, "a1 = %d a2 = %d a3 = %d res = %d\n", a1, a2, a3, result);
		}
	}
	fclose(logf);
	return 0;	
}
