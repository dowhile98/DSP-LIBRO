#include "stm32f4xx_hal.h"
#include "STM32F4-Discovery\stm32f4_discovery_accelerometer.h"
#include "hal_config.h"

#define N 2000

static int16_t acc_data[3] = {0}; // x-axis, y-axis, z-axis
static int16_t acc_buffer[N] = {0};
static int i=0;

int main(void){
	HAL_Init();
	SystemClock_Config();
	BSP_ACCELERO_Init();
	for(i=0;i<N;i++){
		BSP_ACCELERO_GetXYZ(acc_data);
		acc_buffer[i]=acc_data[0];
		HAL_Delay(10);
	}	
	while(1);
}
