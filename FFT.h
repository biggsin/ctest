#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795
#define WEIGHT 4
#define HEIGHT 4
typedef struct complex1{
	double real;
	double image;
}complex;

complex c_add(complex a,complex b);
complex c_sub(complex a,complex b);
complex c_mul(complex a,complex b);
complex* createW(int fftn,int inv);
void FFT1D(complex *in,int fftn,int stage_num,int inv);
void reverse(complex *a,int fftn,int log2N);

