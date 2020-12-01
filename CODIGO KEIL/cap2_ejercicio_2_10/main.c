#include "stm32f4xx.h"
#include "arm_math.h"

/* Implementation of sample-based digital systems in code form*/
/***********DEFINICION DE SISTEMAS****************/
static float digital_system1(float b,float input){
	return b*input;
}

static float digital_system2(float input1, float input2){ 
	return (input1+input2);
} 

static float digital_system3(float input){ 
	return pow(input,2);
} 

static float digital_system4(float b0, float b1, float input0, float input1){ 
	return (b0*input0+b1*input1);
}

static float digital_system5(float b0, float b1, float a1, float input0, input1, float output1){ 
	return b0*input0+b1*input1+a1*output1;
} 

static float digital_system6(float b0, float b1, float input0, float input1){ 
	return b0*input0+b1*input1;
}
static float digital_system7(float b0, float a1, float input0, float output1){ 
	return b0*input0+a1*output1;
}

static float digital_system8(int n, float input0){ 
	return (float)n*input0;
}

#define N 20				//cantidad de muestras

int n;
float d[N], u[N], s[N];
float w0=PI/5;
float y1[N],y2[N],y3[N],y4[N],y5[N],y6[N],y7[N],y8[N];

int main(void){
	// IMPULSO
	for(n = 0;n<N; n++){
		if(n == 0) d[n] = 1;
		else d[n] = 0;
	}
	// escalon
	for(n = 0;n<N; n++){
		u[n] = 1;
	}
	// señal sinusoidal
	for(n = 0;n<N; n++){
		s[n] = (float)sin(w0*(float)n);
	}
	
	/********** RESPUESTA DE  LOS SISTEMAS A ENTRADAS***************/
	//y[n] = b x[n]
	for(n = 0;n<N; n++){
		y1[n] = digital_system1(2.2,u[n]);
	}
	//y[n] = x1[n] + x2[n]
	for(n = 0;n<N; n++)
		y2[n] = digital_system2(u[n],s[n]);
	//y[n] = x^2[n]
	for(n = 0;n<N; n++)
		y3[n] = digital_system3(s[n]);
	//y[n] = b0 x[n] + b1 x[n-1] 
	for(n = 0;n<N; n++){
		if(n == 0)
			y4[n] = digital_system4(2.2,-1.1,s[n],0);
		else
			y4[n] = digital_system4(2.2,-1.1,s[n],u[n-1]);
		
	}
	//y[n] = b0 x[n] + b1 x[n-1] + a1 y[n-1] 
	for(n = 0;n<N; n++){
		if(n == 0)
			y5[n] = digital_system5(2.2,-1.1,0.7,s[n],0,0);
		else
			y5[n] = digital_system5(2.2,-1.1,0.7,s[n],s[n-1],y5[n-1]);
	}
	//y[n] = b0 x[n+1] + b1 x[n]
	for(n = 0;n<N; n++){
		if(n<N){
			y6[n] = digital_system6(2.2,-1.1,u[n+1],u[n]);
		}
	}
	//y[n] = b0 x[n] + a1 y[n-1] 
	for(n = 0;n<N; n++){
		if(n == 0)
			y7[n] = digital_system7(1.0,2.0,d[n],0);
		else
			y7[n] = digital_system7(1.0,2.0,d[n],y7[n-1]);
	}
	//y[n] = n x[n]
	for(n = 0;n<N; n++){
		y8[n] = digital_system8(n,s[n]);
	}
	while(1);
}
