
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//fir
void my_volk_32f_x2_dot_prod_32f(float * result, float input,
		unsigned int tap, unsigned int num_points);

//demod
void my_volk_32fc_x2_multiply_conjugate_32fc(
		float* outputVector,
		float* inputVector);

//arc tan
float fast_atan2f(float y, float x);

typedef struct {
  float *i;
  float *q;
} complex_input_t;
