//IIR Filter with predetermined taps

#include <stdio.h>

void IIR_filter(double *input, double *output, int size)
{

	//this assumes that I have been given the pointer to a full set of data that I'm allowed to traverse and process
	double a1 = 0.928849;
	double b0 = 0.964424;
	double b1 = 0.964424;
	double input_minus_one = 0.0;
	double output_minus_one = 0.0;

	int i = 0;

	for (i = 0; i < size; i++)
	{
		output[i] = b0*input[i] + b1*input_minus_one + a1*output_minus_one;
		input_minus_one = input[i];
		output_minus_one = output[i];
	}

}
