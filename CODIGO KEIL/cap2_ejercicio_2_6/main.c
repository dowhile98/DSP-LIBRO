#include "arm_math.h"
#include "math.h"

#define N 512
int n;
float s1[N],s2[N],s[N];
float w1=PI/128;
float w2=PI/4;

int main(void)
{
	//sinusoidal signals
	for(n=0;n<N;n++){
		s1[n]=sin(w1*(float)n);
		s2[n]=sin(w2*(float)n);
		s[n]=s1[n]+s2[n];				//es la suma de las dos señales sinusoidales
	}
	while(1);
}
