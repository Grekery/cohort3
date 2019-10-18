#include "iir.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
	double out[1001] = {0, };
	double input[1000] = {0, };
	double j_out;

	FILE *fpi, *fpo;
	fpi=fopen("iir_in.dat", "r");
	if(fpi==NULL)
	{
		printf("cannot open iir_in.dat\n");
		return -1;
	}

	fpo=fopen("iir_out.dat", "r");
	if(fpo==NULL)
	{
		printf("cannot open iir_out.dat\n");
		return -1;
	}

	int j;
	for(j= 0; j<1001; j++){
		fscanf(fpi, "%lf", &input[j]);
	}

	IIR_filter(input, out, 995);

	for(j = 0; j<1000; j++){
		fscanf(fpo, "%lf", &j_out);
		if(abs(out[j] - j_out) > 0.000001)
		{
			printf("j=%d: out=%lf, golden=%lf\n", j, out[j], j_out);
			return -1;
		}
	}

	fclose(fpi);
	fclose(fpo);

	printf("\n\nsuccess!!\n\n");

	return 0;
}
