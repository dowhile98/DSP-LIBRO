#define N 100

int n;

float Asaw=0.75; // Amplitude of the sawtooth signal
int Psaw=20; // Period of the sawtooth signal

float saw[N];

int main(void){

	// One period of the sawtooth signal
	for(n=0;n<N;n++)
		saw[n]=(2*Asaw/(Psaw-1))*n - Asaw;
		
	// Generating the sawtooth signal
	for(n=Psaw;n<N;n++)
		saw[n]=saw[n%Psaw]; 	

	while(1);
}
