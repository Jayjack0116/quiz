#include <stdlib.h>
#include <stdio.h>
#define BUF_SIZE 1000

int main(){
	FILE *fin1, *fin2, *fout;
	fin1 = fopen("iterative.txt","r");
	fin2 = fopen("recursive.txt","r");
	fout = fopen("time.dat","aw");
	char buf[256];
	double val;
	double total_sum1 = 0;
	double total_sum2 = 0;
	for (int i = 0; i < BUF_SIZE ; i++){
		fscanf(fin1, "%s", buf);
		val = atof(buf);
		total_sum1 += val;
		fscanf(fin2, "%s", buf);
		val = atof(buf);
		total_sum2 += val;
	}

	fprintf(fout, "Method\tTime\n");
	fprintf(fout, "iterative\t%.9lf\n",total_sum1);
	fprintf(fout, "recursive\t%.9lf\n",total_sum2);

    fclose(fin1);
    fclose(fin2);
    fclose(fout);
	return 0;
}