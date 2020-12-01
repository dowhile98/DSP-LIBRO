#include "stm32f4xx.h"
#include "arm_math.h"

/*Implementation of frame-based digital systems in code form.*/
/***********DEFINICION DE SISTEMAS****************/
void digital_system1(float b, float input[], float output[], int size){
	int n;
	for(n = 0;n<size;n++)
		output[n] = b*input[n];
}

void digital_system2(float input1[], float input2[], float output[],int size){ 
	int n;
	for(n = 0;n<size;n++){
		output[n] = input1[n] + input2[n];
	}
} 


static void digital_system3(float input[], float output[], int size){ 
	int n;
	for(n = 0;n<size; n++){
		output[n] = (float)pow(input[n],2);
	}
} 

static void digital_system4(float b[], float input[], float output[], int size){
	int n;
	for(n = 0;n<size ;n++){
		if(n == 0)
			output[n] = b[0]*input[n];
		else
			output[n] = b[0]*input[n]+b[1]*input[n-1];
	}
}

static void digital_system5(float b[], float a, float input[], float output[], int size){ 
	int n;
	for(n = 0;n<size; n++){
		if(n == 0)
			output[n] = b[0]*input[n];
		else
			output[n] = b[0]*input[n] + b[1]*input[n-1]+a*output[n-1];
		
	}
} 

static void digital_system6(float b[], float input[], float output[], int size){ 
	int n;
	for(n = 0;n<size ; n++){
		if(n<size){
			output[n] = b[0]*input[n+1] + b[1]*input[n];
		}
	}
}


static void digital_system7(float b, float a, float input[], float output[],int size){ 
	int n;
	for(n = 0;n<size; n++){
		if(n==0)
			output[n] = b*input[n];
		else
			output[n] = b*input[n] + a*output[n-1];
	}
}

static void digital_system8(float input[], float output[], int size){
	int n;
	for(n = 0;n<size ;n++)
		output[n] = (float)n*input[n];
}

#define N 20				//cantidad de muestras

int n;
float b[2];
float a;

//entradas
float d[N], u[N], s[N];
float w0=PI/5;

//salidas
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
	b[0] = 2.2;
	digital_system1(b[0],u,y1,N);
	
	//y[n] = x1[n] + x2[n] 
	digital_system2(u,s,y2,N);
	
	//y[n] = x^2[n]
	digital_system3(s,y3,N);
	
	//y[n] = b0 x[n] + b1 x[n-1]
	b[0] = 2.2;
	b[1] = -1.1;
	digital_system4(b,s,y4,N);
	
	//y[n] = b0 x[n] + b1 x[n-1] + a1 y[n-1]
	b[0] = 2.2;
	b[1] = -1.1;
	a = 0.7;
	digital_system5(b,a,s,y5,N);
	
	//y[n] = b0 x[n+1] + b1 x[n] 
	b[0] = 2.2;
	b[1] = -1.1;
	digital_system6(b,u,y6,N);
	
	//y[n] = b0 x[n] + a1 y[n-1]
	b[0]  = 1.0;
	a = 2.0;
	digital_system7(b[0],a,d,y7,N);
	
	//y[n] = n x[n] 
	digital_system8(s,y8,N);
	
	while(1);
}
