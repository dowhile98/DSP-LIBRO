#include "stm32f4xx.h"                  // Device header
#include "arm_math.h"                   // ARM::CMSIS:DSP

#define N 200

int n;

float w1 = PI/10;
float w2 = 3.0/10.0;

float sin1[N], sin2[N];


int main(void)
{
	for(n = 0; n<N; n++){
		sin1[n] = (float)cos(w1*(float)n);
		sin2[n] = (float)cos(w2*(float)n);
	}
	while(1);
}
