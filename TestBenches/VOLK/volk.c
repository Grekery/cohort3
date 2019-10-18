/* VOLK */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void volk(float outputVector[2048], float inputVector[2048])
{
  float* cPtr = outputVector;
  float* aPtr = &inputVector[2];
  float* bPtr=  &inputVector[0];
  unsigned int number = 0, idx = 0;

  for(number = 0, idx = 0; number < 2048/2-2; number++, idx+=2){
#pragma HLS PIPELINE

	cPtr[idx] = (aPtr[idx] * bPtr[idx]) + (aPtr[idx+1] * bPtr[idx+1]);
	cPtr[idx+1] = -(aPtr[idx] * bPtr[idx+1]) + (aPtr[idx+1] * bPtr[idx]);
  }
}
