#include "atan.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float d_gain = 0.002122;
	float out;
	float input_real;
	float input_imag;
	float j_out;

	FILE *fpi_r, *fpi_i, *fpo;

	fpi_r=fopen("atan_real.txt", "r");
	if(fpi_r==NULL)
	{
		printf("cannot open atan_real.txt\n");
		return -1;
	}

	fpi_i=fopen("atan_imag.txt", "r");
	if(fpi_i==NULL)
	{
		printf("cannot open atan_imag.txt\n");
		return -1;
	}

	fpo=fopen("atan_out.txt", "r");
	if(fpo==NULL)
	{
		printf("cannot open atan_out.txt\n");
		return -1;
	}

	int j;
	for(j= 0; j<1000; j++){
		fscanf(fpi_r, "%f", &input_real);
		fscanf(fpi_i, "%f", &input_imag);
		out = fast_atan2f(input_imag, input_real);
		out = out*d_gain;
		fscanf(fpo, "%f", &j_out);
		if(abs(out - j_out) > 0.000001)
		{
			printf("j=%d: out=%f, golden=%f\n", j, out, j_out);
			return -1;
		}
	}

	fclose(fpi_r);
	fclose(fpi_i);
	fclose(fpo);

	printf("\n\nsuccess!!\n\n");

	return 0;
}
