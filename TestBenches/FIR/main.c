#include "fir.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double  out;
	double  input;
	double  gold;

	FILE *fpi, *fpo;
	fpi=fopen("fir_in.txt", "r");
	if(fpi==NULL)
	{
		printf("cannot open fir_in.txt\n");
		return -1;
	}

	fpo=fopen("fir_out.txt", "r");
	if(fpo==NULL)
	{
		printf("cannot open fir_out.txt\n");
		return -1;
	}

	int j;
	gold=0;

	for(j= 0; j<1000; j++){
		fscanf(fpi, "%lf", &input);
		FIR_filter(&out, input, j%4);

		if(!(j%4))
		{
			//send to IIR
			if(j>307)
				fscanf(fpo, "%lf", &gold);
			printf("j=%d: out=%lf, golden=%lf\n", j, out, gold);
		}
	}

	fclose(fpi);
	fclose(fpo);

	printf("\n\nsuccess!!\n\n");

	return 0;
}
