#include <stdio.h>
#include <math.h>

void plotData(int n) {
	FILE* pipe = popen("gnuplot -persistent", "w"); // create pipe to gnuplot (i guess)
	fprintf(pipe, "set xlabel \"x\"\n");
	fprintf(pipe, "set ylabel \"f(x)\"\n");
	fprintf(pipe, "set grid\n");
	fprintf(pipe, "title \"График функции f(x)\"\n");
	fprintf(pipe, "%s\n", "plot 'data.tmp' with lines title \"f(x)\"\n"); 	
	pclose(pipe);
}

int main() {
	float scale = 0.1;
	float crntAbsc = 0.0;
	printf("First cycle result (do-while)\n");
	do
	{
		float crntOrd;
		if (crntAbsc < 1 + scale) {
			crntOrd = sqrt(crntAbsc + 1) - sqrt(crntAbsc) - 0.5;
		}
		else {
			crntOrd = exp((-1) * crntAbsc - 1 / crntAbsc);
		}
		printf("%f\t%f\n", crntAbsc, crntOrd);
		crntAbsc += scale;
	} while (crntAbsc < 2 + scale);


	printf("Second cycle result (for)\n");
	FILE* fdata = fopen("data.tmp", "w"); // save pnts also
	for (float absc = 0; absc < 2 + scale; absc += scale)
	{
		float ord;
		if (absc < 1 + scale) {
			ord = sqrt(absc + 1) - sqrt(absc) - 0.5;
		}
		else {
			ord = exp((-1)*absc - 1 / absc);
		}
		printf("%f\t%f\n", absc, ord);
		fprintf(fdata, "%f %f\n", absc, ord);
	}	
	fclose(fdata);
	plotData(2 / scale + 1);
	return 0;
}


