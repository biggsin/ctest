//#include "myhead.h"
#include <stdio.h>
#include "FFT.h"
//#define X *((int*)0x40012000)
void chartest();
void prtin();
void FFTtest();
void array2D();

int main(){
	FFTtest();
	//array2D();
	return 1;
}

void chartest(){
	char *c[] = {"HI","FUCK"};
	char *d = "GG";
	printf("%s\n", c[1]);
};

void prtin(){
	int a[16];
	int i;
	FILE *fp = fopen("input.txt", "r");
	for(i=0 ; i<16 ; i++){
		fscanf(fp, "%d", &a[i]);
	}
	for(i=0 ; i<16 ; i++){
		printf("a[%d] is %x\n", i, *(a+i));
	}
}

void FFTtest(){
	int i;
	complex in[4] = {{1,0}, {2,0}, {3,0}, {4,0}};
	FFT1D(in, 4, 2 ,1);
	for(i=0 ; i<4 ; i++){
		printf("%f|%f\n", in[i].real, in[i].image);
	}
}

void array2D(){
	int (*a)[5] = malloc(sizeof(int)*5*10);
	int c = 999;
	int *b[5] = {&c};
	a[9][4] = 3;
	printf("%d\n", **b);
}
