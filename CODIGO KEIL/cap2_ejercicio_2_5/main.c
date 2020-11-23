#include "math.h"
#include "arm_math.h"


#define N 10

int n;
int d[N], u[N], r[N];
float e[N], s[N];
float a=0.8;
float w0=PI/5;

int x2[N],x3[N];
float x1[N], x4[N], x5[N];

int main(void){

//unit pulse signal
for(n=0;n<N;n++)
if (n==0) d[n]=1;
else d[n]=0;

//unit step signal
for(n=0;n<N;n++)
u[n]=1;

//exponential signal
for(n=0;n<N;n++)
e[n]=pow(a,(float)n);
	
//unit ramp signal
for(n=0;n<N;n++)
r[n]=n;	

//sinusoidal signal
for(n=0;n<N;n++)
s[n]=sin(w0*(float)n);

for(n=0;n<N;n++)
if(n<(N-4))x1[n]=0.6*r[n+4];
else x1[n]=0;	


for(n=0;n<N;n++)
if (n<3) x2[n]=0;
else x2[n]=u[n-3]-u[n-8];

for(n=0;n<N;n++)
if (n<3) x3[n]=u[n];
else x3[n]=u[n]-u[n-3]+u[n-8];


for(n=0;n<N;n++)
x4[n]=x2[n]*s[n]+d[n];


for(n=0;n<N;n++)
x5[n]=-2.4*e[n]*s[n];

return(0);
}
