#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP
#include "FIR_lpf_coefficients.h"


void convolution_sum(float x[],float h[],float y[], int size1, int size2){
	int n,k;
	float sum;
	for (n = 0;n<size1; n++){
		sum = 0.0;
		for (k = 0;k<size2;k++){
			if(k<(n+1))
				sum += h[k]*x[n-k];							//se realiza la convolucion
		}
		y[n] = sum;
	}
}

#define N 512														//cantidad de muestras
int n;
float x[N], y[N];												//buffer de entrada y salida

	
int main(void)
{
	//se genera la señal de entrada
	for(n = 0;n<N; n++){
		x[n] = arm_sin_f32(PI*n/128) + arm_sin_f32(PI*n/4);
	}
	
	convolution_sum(x,h,y,N,K);
	while(1);
}
