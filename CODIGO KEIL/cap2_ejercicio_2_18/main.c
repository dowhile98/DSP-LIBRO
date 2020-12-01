#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP
#include "time.h"
#include "FIR_hpf_coefficients.h"

//DEFINICION DE MACROS
#define CoreClock 16000000
#define N 				512
//definicion de variables globales
float32_t excutionTime;
float32_t x[N], y[N];
uint32_t cycleCount;
float32_t firStateF32[N + K - 1];
int16_t n,k; 
float32_t dummy; 
arm_fir_instance_f32 S;

//definiciond de prototipo de funciones


int main(void){
	//se crea una señal sinusoidal
	int n;
	for(n = 0;n<N;n++)
		x[n] = arm_sin_f32(PI*n/128)+arm_sin_f32(PI*n/4);
	//inicio del proceso
	for(k = 0;k<K/2;k++){
		dummy = h[k];
		h[k] = h[K-k-1];
		h[K-k-1] = dummy;
	}
	
	arm_fir_init_f32(&S,K,h,firStateF32,N);
	
	arm_fir_f32(&S,x,y,N);
	
	while(1){
		
	}
}
