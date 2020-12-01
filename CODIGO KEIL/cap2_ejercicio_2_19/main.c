#include "stm32f4xx.h"
#include "arm_math.h"
#include "FIR_lpf_coefficients.h"

//definicion de macros
#define N 512

float32_t x[N];
float32_t y[N];

int16_t n;

int main(void){
	//creacion de una señall de entrada
	for(n = 0;n<N;n++)
		x[n] = arm_sin_f32(PI*n/128)+arm_sin_f32(PI*n/4);
	//operacion de convolucion
	arm_conv_f32(x, N, h, K, y);
	
	while(1){
		
	}
}
