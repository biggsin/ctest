#include "FFT.h"
void FFT1D(complex *in,int fftn,int log2N,int inv){
	int i,j,m,p,q,r,idx1,idx2;
	complex *W;
	W = createW(fftn,inv);
	reverse(in,fftn,log2N);
	complex temp1,temp2;
	// m:stage
	for(m=1;m<=log2N;m++){
		p = 2<<(m-1); // how many points in a butterfly in a stage
		q = p/2;
		r = fftn/p; // how many butterflys in a stage
		// j:butterflys in a stage
		for(j=0;j<r;j++){
			// i:points in a butterfly
			for(i=0;i<q;i++){
				idx1 = (j*p)+i;
				idx2 = (j*p)+i+q;
				temp1 = *(in+idx1);
				temp2 = *(in+idx2);
				in[idx1] = c_add(temp1,c_mul(temp2,W[i*fftn/p]));
				in[idx2] = c_sub(temp1,c_mul(temp2,W[i*fftn/p]));
			}
		}

	}
	if(inv==-1){
		for(i=0;i<fftn;i++){
			in[i].real = in[i].real/fftn;
			in[i].image = in[i].image/fftn;
		}
	}

	free(W);
}
complex* createW(int fftn,int inv){
	int i;
	complex *w = malloc(sizeof(complex)*fftn/2);
	for(i=0;i<fftn/2;i++){
		w[i].real = cos(2*PI/fftn*i*inv);
		w[i].image = -sin(2*PI/fftn*i*inv);
	}
	return w;
}

complex c_add(complex a,complex b){
	complex c;
	c.real = a.real+b.real;
	c.image = a.image+b.image;
	return c;
}
complex c_sub(complex a,complex b){
	complex c;
	c.real = a.real-b.real;
	c.image = a.image-b.image;
	return c;
}
complex c_mul(complex a,complex b){
	complex c;
	c.real = (a.real)*(b.real)-(a.image)*(b.image);
	c.image = (a.real)*(b.image)+(a.image)*(b.real);
	return c;
}
void reverse(complex *a,int fftn,int log2N){
	complex *b = malloc(sizeof(complex)*fftn);
	unsigned int i,j,k,t;
	for(i=0;i<fftn;i++){

		k=i;
		t=0;
		for(j=0;j<log2N;j++){
			t = t<<1;
			t = t|(k&1);
			k = k>>1;
		}
			b[i] = a[t];
	}
	for(i=0;i<fftn;i++){
		a[i] = b[i];
	}
}
