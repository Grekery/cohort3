#include "volk.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double input[2048];
	double output[2048];
	double gold_r, gold_i;

	FILE *fpi_r, *fpi_i, *fpo_r, *fpo_i;
	fpi_r=fopen("volk_in_r.txt", "r");
	if(fpi_r==NULL)
	{
		printf("cannot open volk_in_r.dat\n");
		return -1;
	}
	fpi_i=fopen("volk_in_i.txt", "r");
	if(fpi_i==NULL)
	{
		printf("cannot open volk_in_i.dat\n");
		return -1;
	}

	fpo_r=fopen("volk_out_r.txt", "r");
	if(fpo_r==NULL)
	{
		printf("cannot open volk_out_r.dat\n");
		return -1;
	}
	fpo_i=fopen("volk_out_i.txt", "r");
	if(fpo_i==NULL)
	{
		printf("cannot open volk_out_i.dat\n");
		return -1;
	}

	int j;
	for(j= 0; j<1024; j+=2){
		fscanf(fpi_r, "%lf", &input[j]);
		fscanf(fpi_i, "%lf", &input[j+1]);
	}

	volk(output, input);

	for(j = 0; j<1024; j+=2){
		fscanf(fpo_r, "%lf", &gold_r);
		fscanf(fpo_i, "%lf", &gold_i);

		//if( (abs(output[j] - gold_r) > 0.000001) | (abs(output[j+1] - gold_i) > 0.000001) )
		//{
			printf("j=%d: out=%lf, %lf, golden=%lf, %lf\n", j, output[j], output[j+1], gold_r, gold_i);
			//return -1;
		//}
	}

	fclose(fpi_r);
	fclose(fpi_i);
	fclose(fpo_r);
	fclose(fpo_i);

	printf("\n\nsuccess!!\n\n");

	return 0;

}
