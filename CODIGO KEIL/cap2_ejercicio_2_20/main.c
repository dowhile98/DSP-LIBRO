#include "stm32f4xx.h"
#include "arm_math.h"
#include "FIR_lpf_coefficients.h"
#include "time.h"
//definicion de macros
#define N 512
#define coreClock 16000000
float32_t x[N];
float32_t y[N];

int16_t n;
uint32_t cycleCount;
float32_t time;

int main(void){
	//creacion de una señall de entrada
	for(n = 0;n<N;n++)
		x[n] = arm_sin_f32(PI*n/128)+arm_sin_f32(PI*n/4);
	//operacion de convolucion
	startTiming();
	arm_conv_f32(x, N, h, K, y);
	cycleCount = StopTiming();
	time = calculateTime(cycleCount,coreClock);//se calcula el tiempo en segundos  
	while(1){
		
	}
}
