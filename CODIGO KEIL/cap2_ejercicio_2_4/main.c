#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP

#define N 20


/***********VARIABLES GLABALES***************/
int n;
int d[N], u[N];
float e[N], s[N];
float a = 0.8;
float w0 = PI/5;

/*DATOS DE SALIDA*/
int x1[N], x3[N], x5[N];
float x2[N], x4[N], x6[N], x7[N], x8[N]; 

int main(void)
{
	/*señal impulso unitario*/
	for(n = 0;n<N;n++)
	{
		if(n == 0)
			d[n] = 1;
		else
			d[n] = 0;
	}
	
	/*señal escalon unitario*/
	for(n = 0; n<N; n++)
	{
		u[n] = 1;
	}
	
	/*señal exponencial*/
	for(n = 0; n<N ; n++)
	{
		e[n] = (float)pow(a,(float)n);
	}
	/* señal sinusoildal*/
	for(n = 0; n<N;n++)
	{
		s[n] = (float)sin(w0*(float)n);
	}
	
	/************* APLICAION DE PROPIEDADE DE SEÑALES DISCRETAS*********/
	//desplazamiento del impulso unitario
	for(n = 0; n<N;n++)
	{
		if(n < 10) x1[n] = 0;
		else x1[n] = d[n-10];
	}
	//señal sinusoidal elevada
	for(n = 0; n<N;n++)
		x2[n] = s[n] + 1;
	//negacion del pulso unitario
	for(n = 0; n<N;n++)
		x3[n] = -u[n];
	//aplicacion de todas las operaciones a la señal sinusoildal
	for(n = 0; n<N;n++)
	{
		if(n<2) 
			x4[n] = 0.0;
		else 
			x4[n] = (float)3.0*s[n-2] - (float)2.0;
	}
	//resta de dos señales escalon
	for(n = 0; n<N;n++)
	{
		if(n < 8) 
			x5[n] = u[n];
		else
		x5[n] = u[n]-u[n-8];
	}
	//multiplicacion de una señal exponencial por un impulso
	for(n = 0; n<N;n++)
		x6[n] = e[n]*(float)u[n];
	
	//multiplicacion de una selñal sinusoidal con una exponencial
	for(n = 0; n<N;n++)
		x7[n] = e[n] * s[n];
	//multiplicacion de una señal exponencial con u[n]-u[n-4]
	for(n = 0; n<N;n++)
		x8[n] = e[n] * (float)x5[n];
	while(1)
	{
		
	}
}
