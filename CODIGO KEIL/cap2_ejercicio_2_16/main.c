#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP
#include "time.h"
#include "FIR_hpf_coefficients.h"
#include "FIR_lpf_coefficients.h"

//DEFINICION DE MACROS
#define CoreClock 16000000
#define N 				512
//definicion de variables globales
float excutionTime;
float x[N], y[N];
uint32_t cycleCount;
//definiciond de prototipo de funciones
void convolution_sum(float x[],float h[],float y[],int size1,int size2){
	int n, k;
	float sum;
	for (n=0;n<size1;n++){
		sum = 0.0;
		for(k=0;k<size2;k++){
			if(k<(n+1))
				sum += h[k]*x[n-k];
		}
		y[n] = sum;
	}
}


int main(void){
	//se crea una señal sinusoidal
	int n;
	for(n = 0;n<N;n++)
		x[n] = arm_sin_f32(PI*n/4);
	//inicio del proceso
	startTiming();
	convolution_sum(x,hl,y,N,Kl);
	cycleCount = StopTiming();
	excutionTime = calculateTime(cycleCount,CoreClock);
	while(1){
		
	}
}
