
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include"gnutest.h"
#include "fast_atan2f.h"

static float d_gain = 0.002122;

#define MYCOUNT  8
static double taps[155] = { 0.00004801760588	, -0.00007127169374	, -0.00015557580628	, -0.00016055021842	, -0.00008158741548	, 0.00004278294000	, 0.00014927044685	, 0.00018144934438	, 0.00011914555944	, -0.00000945342163	, -0.00014000367082	, -0.00020357579342	, -0.00016244665312	, -0.00003183816443	, 0.00012463537860	, 0.00022525878740	, 0.00021222006762	, 0.00008408562280	, -0.00009915599367	, -0.00024333830515	, -0.00026778053143	, -0.00014963364811	, 0.00005908817911	, 0.00025324634043	, 0.00032673988608	, 0.00022965090466	, 0.00000000000000	, -0.00024925271282	, -0.00038485584082	, -0.00032364428625	, -0.00008190503286	, 0.00022487013484	, 0.00043604517123	, 0.00042906127055	, 0.00018916388217	, -0.00017340117483	, -0.00047257813276	, -0.00054102297872	, -0.00032244450995	, 0.00008859649097	, 0.00048545747995	, 0.00065222498961	, 0.00048000202514	, 0.00003461547385	, -0.00046497289441	, -0.00075303140329	, -0.00065725046443	, -0.00019937696925	, 0.00040140660712	, 0.00083177670604	, 0.00084649486234	, 0.00040618091589	, -0.00028585540713	, -0.00087527534924	, -0.00103686051443	, -0.00065223750426	, 0.00011112079665	, 0.00086952449055	, 0.00121444417164	, 0.00093098089565	, 0.00012738478836	, -0.00080057117157	, -0.00136269780342	, -0.00123176013585	, -0.00043077606824	, 0.00065550167346	, 0.00146304338705	, 0.00153975340072	, 0.00079593411647	, -0.00042350223521	, -0.00149569357745	, -0.00183612213004	, -0.00121490121819	, 0.00009693008178	, 0.00144064868800	, 0.00209841830656	, 0.00167447549757	, 0.00032766532968	, -0.00127881590743	, -0.00230122450739	, -0.00215603737161	, -0.00084863294614	, 0.00099319149740	, 0.00241700396873	, 0.00263562053442	, 0.00145847408567	, -0.00057004101109	, -0.00241709826514	, -0.00308421836235	, -0.00214330153540	, 0.00000000000000	, 0.00227281544358	, 0.00346829369664	, 0.00288252183236	, 0.00072097236989	, -0.00195650593378	, -0.00375041994266	, -0.00364873977378	, -0.00159085332416	, 0.00144251843449	, 0.00388995208777	, 0.00440783658996	, 0.00260108732618	, -0.00070789724123	, -0.00384356360883	, -0.00511913513765	, -0.00373642914928	, -0.00026736696600	, 0.00356540596113	, 0.00573547463864	, 0.00497512612492	, 0.00150078407023	, -0.00300650694408	, -0.00620290776715	, -0.00628944765776	, -0.00300890789367	, 0.00211277091876	, 0.00645947689191	, 0.00764654530212	, 0.00481066806242	, -0.00082040886628	, -0.00643209880218	, -0.00900961644948	, -0.00693382974714	, -0.00095351040363	, 0.00602953461930	, 0.01033931691200	, 0.00942746177316	, 0.00333045888692	, -0.00512698898092	, -0.01159535255283	, -0.01238726079464	, -0.00651211757213	, 0.00353117636405	, 0.01273818872869	, 0.01601212844253	, 0.01087844930589	, -0.00089391093934	, -0.01373075507581	, -0.02074968814850	, -0.01725423894823	, -0.00353625230491	, 0.01454010419548	, 0.02775634452701	, 0.02781471237540	, 0.01182719785720	, -0.01513889338821	, -0.04092928767204	, -0.05061084032059	, -0.03266235440969	, 0.01550663728267	, 0.08518035709858	, 0.15838518738747	, 0.21382068097591	, 0.23445974290371};
static float shift[309];

static float a1 = 0.928849;
static float b0 = 0.964424;
static float b1 = 0.964424;

static float prev_input = 0.0;
static float prev_output = 0.0;

void FIR_filter(float * result, float input, unsigned short do_filter)
{
  float dotProduct = 0, temp = 0, temp1 = 0, temp2 = 0, temp3 = 0;
  unsigned int number;

  for(number=308; number>0; number--) {
#pragma HLS PIPELINE
	  temp=shift[number-1];
	  shift[number]=temp;
  }
  shift[0] = input;

  if(!do_filter)//its mod by 4
  {
	  for(number=0; number<154 ; number++)
	  {
#pragma HLS PIPELINE
		  temp1 = shift[number];
		  temp2 = shift[308-number];
		  temp3 = taps[number];
		  dotProduct += temp3*(temp1+temp2);
	  }
	  dotProduct += taps[154]*shift[154];
  }
  *result = dotProduct;
}


void my_volk_32fc_x2_multiply_conjugate_32fc(
		float outputVector[MYCOUNT],
		float inputVector[MYCOUNT]){

  float* cPtr = outputVector;
  float* aPtr = &inputVector[2];
  float* bPtr=  &inputVector[0];
  float tempa0, tempa1, tempb0, tempb1, tempc0, tempc1;
  unsigned int number = 0, idx = 0;
  int counter = (MYCOUNT>>1)-2;

  for(number = 0, idx = 0; number < counter; number++, idx+=2){
#pragma HLS PIPELINE
	tempa0 = aPtr[idx];
	tempa1 = aPtr[idx+1];
	tempb0 = bPtr[idx];
	tempb1 = bPtr[idx+1];

	tempc0 = (tempa0 * tempb0) + (tempa1 * tempb1);
	tempc1 = -(tempa0 * tempb1) + (tempa1 * tempb0);
	cPtr[idx] = tempc0; cPtr[idx+1] = tempc1;
  }
}


void IIR_filter(float input, float *output, int size)
{
	int i = 0;

	*output = b0*input + b1*prev_input + a1*prev_output;
	prev_input = input;
	prev_output = *output;
}

void xillybus_wrapper(int *in, int *out)
{
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return

	int x1, y1;
	int i = 0, j = 0;
	float inf[MYCOUNT];
#pragma HLS ARRAY_PARTITION variable=inf complete dim=1

	float outf[MYCOUNT];
#pragma HLS ARRAY_PARTITION variable=outf complete dim=1

	float y11;
	/* arc tan inputs */
	float c, d, result, tempb;

	for( i = 0; i < MYCOUNT; i++) {
		x1 = *in++;
		inf[i] = *((float *)&x1);
	}

	my_volk_32fc_x2_multiply_conjugate_32fc(outf, inf);

	for( i = 0, j = 0; i < MYCOUNT-1; i=i+2, j++) {
		c = fast_atan2f(outf[i+1], outf[i]); //image, real
		d = d_gain * c;
		FIR_filter(&tempb, d, j%4);
		if (j%4 == 0) {
		  IIR_filter(tempb, &result, 1);
		  y11 = result;
		  y1 = *((int *) &y11);
		  *out++ = y1;
		}
	}
}
