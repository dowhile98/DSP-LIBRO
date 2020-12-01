#include "math.h"
#include "arm_math.h"

void digital_system1(float input1[], float input2[], float output[],int size){
	int n;
	for(n=0;n<size;n++)
		output[n]=input1[n]+input2[n];
}

void digital_system2(float input[], float output[], int size){
	int n;
	for(n=0;n<size;n++)
		output[n]=pow(input[n],2);
}


void digital_system3(float b[], float a, float input[], float output[], int size){
	int n;
	for(n=0;n<size;n++){
		if (n==0)
			output[n]=b[0]*input[n];
		else
			output[n]=b[0]*input[n]+b[1]*input[n-1]+a*output[n-1];
	}
}

void digital_system4(float b[], float input[], float output[], int size){
	int n;
	for(n=0;n<size;n++){
		if (n<size)
			output[n]=b[0]*input[n+1]+b[1]*input[n];
	}
}


#define N 10

int n;
float w0=PI/5;
float b[2];
float a;
float a1=0.8;
//señales de entrada
float ramp[N], e[N];
//señales de salida
float y1[N],y2[N],y3[N],y4[N];


int main (void){

	//unit ramp signal
	for(n=0;n<N;n++)
		ramp[n]=n;

	//exponential signal
	for(n=0;n<N;n++)
		e[n]=pow(a1,(float)n);	

	//y[n] = x1[n] + x2[n]
	digital_system1(ramp,e,y1,N);

	//y[n] = x^2[n]
	digital_system2(ramp,y2,N);


	//y[n] = b0 x[n] + b1 x[n-1] + a1 y[n-1]
	b[0]=2.2;
	b[1]=-1.1;
	a=0.7;
	digital_system3(b,a,y1,y3,N);

	//y[n] = b0 x[n+1] + b1 x[n]
	b[0]=2.2;
	b[1]=-1.1;
	digital_system4(b,y2,y4,N);

	while(1);
}
