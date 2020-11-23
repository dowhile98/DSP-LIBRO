#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP

#define N 200

int n;

float Asq = 2.4; 		// Amplitude of the square signal 
float Atr = 1.5; 		// Amplitude of the triangle signal 
int Psq = 50; 			// Period of the square signal 
int Ptr = 40; 			// Period of the triangle signal 

float square[N], triangle[N]; 
int main(void)
{
	//One period of the square signal 
	for(n=0;n<Psq/2;n++){
		 
		 if(n<(Psq/2)) 
			 square[n]=Asq; 
		 else 
			 square[n]=-Asq; 
	 }
		// One period of the triangle signal 
	for(n=0;n<Ptr;n++){
		if(n<(Ptr/2))
			triangle[n]=(2*Atr/(Ptr/2))*n - Atr; 
		else 
			triangle[n] = -(2*Atr/(Ptr/2))*(n-Ptr/2) + Atr; 
	}
	 // Generating the square signal 
	for(n=Psq;n<N;n++) 
		square[n]=square[n%Psq]; 

		// Generating the triangle signal 
	for(n=Ptr;n<N;n++) 
		triangle[n]=triangle[n%Ptr]; 
	while(1);
}
