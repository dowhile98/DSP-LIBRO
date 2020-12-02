#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP

//DEFINICION DEL FILTRO IIR
 void IIR_filter (float b[], float a[], float x[], float y[], int size []){ 
  int n,k,l; 
  float sum; 
  for(n=0;n<size [0];n++) { 
                 
		sum=0.0; 
    for(k=0;k<size [1];k++) 
      if(k<(n+1)) sum+=b[k]*x[n-k]; 
    for(l=1;l<size [2];l++) 
      if(l<(n+1)) sum -=a[l]*y[n-l]; 
    y[n]=sum; 
   } 
} 
// definicion de algunos macros
#define N 512
#define K 3
#define L 3


//definicion de variables globales
int n;
int size[3];
float x[N], y[N];

// los coeficientes del filtro iir
float b[K] = {0.705514, -1.414028, 0.705514}; 
float a[L] = {1, -1.359795, 0.462261};


int main(void){
	//geberacion de la señal de entrada
	for(n = 0;n<N; n++)
		x[n] = arm_sin_f32(PI*(float)n/128)+arm_sin_f32(PI*(float)n/4);
	
	size[0] = N;
	size[1] = K;
	size[L] = L;
	
	//reslizacion del filtro
	IIR_filter (b,a,x,y,size); 
	
	while(1){
		
	}
}

