#include "math.h"
#include "arm_math.h"

float digital_system1(float input1, float input2){
	return input1+input2;
}

float digital_system2(float input){
	return pow(input,2);
}

float digital_system3(float b0, float b1, float a1, float input0, float input1, float output1){
	return b0*input0+b1*input1+a1*output1;
}

float digital_system4(float b0, float b1, float input0, float input1){
	return b0*input0+b1*input1;
}


#define N 20				//cantidad de muestras

int n;
float w0=PI/5;
float a=0.8;
//señales de entrada
float ramp[N], e[N];

//señales de salida
float y1[N],y2[N],y3[N],y4[N];

int main(void)
{

	//unit ramp signal
	for(n=0;n<N;n++)
		ramp[n]=n;

	//exponential signal
	for(n=0;n<N;n++)
		e[n]=pow(a,(float)n);	


	//y[n] = x1[n] + x2[n]
	for(n=0;n<N;n++)
		y1[n]=digital_system1(ramp[n], e[n]);

	//y[n] = x^2[n]
	for(n=0;n<N;n++)
		y2[n]=digital_system2(ramp[n]);

	//y[n] = b0 x[n] + b1 x[n-1] + a1 y[n-1]
	for(n=0;n<N;n++){
		if (n==0)
			y3[n]=digital_system3(2.2,-1.1,0.7,y1[n],0,0);
		else
			y3[n]=digital_system3(2.2,-1.1,0.7,y1[n],y1[n-1],y3[n-1]);
	}
	//y[n] = b0 x[n+1] + b1 x[n]
	for(n=0;n<N;n++){
		if (n<N)
			y4[n]=digital_system4(2.2,-1.1,y2[n+1],y2[n]);
	}
	
	while(1);
}
