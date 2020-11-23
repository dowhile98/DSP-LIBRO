#ifndef hal_config
#define hal_config

/**************************************************************/

void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	__PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

/**************************************************************/

void SysTick_Handler(void){
	HAL_IncTick();
}

/**************************************************************/

#ifdef GPIO_Output
GPIO_InitTypeDef GPIO_InitStruct_Output;

void GPIO_Output_Config(void){
GPIO_OUTPUT_CLK_ENABLE();
GPIO_InitStruct_Output.Pin   = GPIO_OUTPUTx;
GPIO_InitStruct_Output.Mode  = GPIO_MODE_OUTPUT_PP;
HAL_GPIO_Init(GPIO_OUTPUT_PORT , &GPIO_InitStruct_Output);
}
#endif /* GPIO_Output */

/**************************************************************/

#ifdef GPIO_Input
GPIO_InitTypeDef GPIO_InitStruct_Input;

void GPIO_Input_Config(void){
GPIO_INPUT_CLK_ENABLE();
GPIO_InitStruct_Input.Pin = GPIO_INPUTx;
GPIO_InitStruct_Input.Mode = GPIO_MODE_INPUT;
HAL_GPIO_Init(GPIO_INPUT_PORT, &GPIO_InitStruct_Input);
}
#endif /* GPIO_Input */

/**************************************************************/

#ifdef GPIO_Interrupt
GPIO_InitTypeDef GPIO_InitStruct_Interrupt;

void GPIO_Interrupt_Config(void){
GPIO_INTERRUPT_CLK_ENABLE();
GPIO_InitStruct_Interrupt.Pin = GPIO_INTERRUPTx;
GPIO_InitStruct_Interrupt.Pull = GPIO_NOPULL;	
GPIO_InitStruct_Interrupt.Mode = GPIO_INTERRUPT_MODE;
HAL_GPIO_Init(GPIO_INTERRUPT_PORT, &GPIO_InitStruct_Interrupt);

HAL_NVIC_SetPriority(EXTIx_IRQn, 1, 1);
HAL_NVIC_EnableIRQ(EXTIx_IRQn);	
HAL_NVIC_SetPriority(SysTick_IRQn,0,0);
}

void EXTIx_IRQHandler(void){
HAL_GPIO_EXTI_IRQHandler(GPIO_INTERRUPTx);
}

#endif /* GPIO_Interrupt */

/**************************************************************/

#ifdef Timer
TIM_HandleTypeDef TimHandle;

void Timer_Config(void){
TimHandle.Instance = TIMx;
TimHandle.Init.Period = TIMxPeriod - 1;
TimHandle.Init.Prescaler = (uint32_t) ((SystemCoreClock /2) / TIMxFrequency) - 1;
TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
HAL_TIM_Base_Init(&TimHandle);
}

void HAL_TIM_Base_MspInit ( TIM_HandleTypeDef * htim){
TIMx_CLK_ENABLE();	
HAL_NVIC_SetPriority(TIMx_IRQn, 4, 0);
HAL_NVIC_EnableIRQ(TIMx_IRQn);	
}

void TIMx_IRQHandler(void){
HAL_TIM_IRQHandler(&TimHandle);
}
#endif /* Timer */

/**************************************************************/

#ifdef ADC_InternalCh
ADC_HandleTypeDef AdcHandle;
ADC_ChannelConfTypeDef ADC_ChannelStruct;	
DMA_HandleTypeDef   DMA_HandleStruct;

void ADC_InternalCh_Config(void){
AdcHandle.Instance = ADCx;  
AdcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
AdcHandle.Init.Resolution = ADC_RESOLUTION12b;
AdcHandle.Init.ScanConvMode = DISABLE;
AdcHandle.Init.ContinuousConvMode = DISABLE;
AdcHandle.Init.DiscontinuousConvMode = DISABLE;
AdcHandle.Init.NbrOfDiscConversion = 1;
AdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
AdcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
AdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
AdcHandle.Init.NbrOfConversion = 1;
AdcHandle.Init.DMAContinuousRequests = ADCx_DMA;
AdcHandle.Init.EOCSelection = EOC_SINGLE_CONV;
HAL_ADC_Init(&AdcHandle);
ADC_ChannelStruct.Channel = ADCx_CHANNEL;
ADC_ChannelStruct.Rank = 1;
ADC_ChannelStruct.SamplingTime = ADCx_SamplingTime;
ADC_ChannelStruct.Offset = 0;
HAL_ADC_ConfigChannel(&AdcHandle, &ADC_ChannelStruct);
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc){	
ADCx_CLK_ENABLE();
if (ADCx_DMA == ENABLE) __HAL_LINKDMA(hadc, DMA_Handle, DMA_HandleStruct);	
}

#endif /* ADC_InternalCh */

/**************************************************************/

#ifdef ADC_Software
ADC_HandleTypeDef ADC_HandleStruct;
ADC_ChannelConfTypeDef ADC_ChannelStruct;	
GPIO_InitTypeDef GPIO_InitStruct_Adc;
DMA_HandleTypeDef   DMA_HandleStruct;

void ADC_Software_Config(void){
ADC_HandleStruct.Instance = ADCx;  
ADC_HandleStruct.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
ADC_HandleStruct.Init.Resolution = ADC_RESOLUTION12b;
ADC_HandleStruct.Init.ScanConvMode = DISABLE;
ADC_HandleStruct.Init.ContinuousConvMode = ADCx_CONTCONVMODE;
ADC_HandleStruct.Init.DiscontinuousConvMode = DISABLE;
ADC_HandleStruct.Init.NbrOfDiscConversion = 1;
ADC_HandleStruct.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
ADC_HandleStruct.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
ADC_HandleStruct.Init.DataAlign = ADC_DATAALIGN_RIGHT;
ADC_HandleStruct.Init.NbrOfConversion = 1;
ADC_HandleStruct.Init.DMAContinuousRequests = ADCx_DMA;
ADC_HandleStruct.Init.EOCSelection = EOC_SINGLE_CONV;
HAL_ADC_Init(&ADC_HandleStruct);
ADC_ChannelStruct.Channel = ADCx_CHANNEL;
ADC_ChannelStruct.Rank = 1;
ADC_ChannelStruct.SamplingTime = ADCx_SamplingTime;
ADC_ChannelStruct.Offset = 0;
HAL_ADC_ConfigChannel(&ADC_HandleStruct, &ADC_ChannelStruct);
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc){	
ADCx_CLK_ENABLE();	
ADCx_CHANNEL_GPIO_CLK_ENABLE();
GPIO_InitStruct_Adc.Pin = ADCx_CHANNEL_PIN;
GPIO_InitStruct_Adc.Mode = GPIO_MODE_ANALOG;
GPIO_InitStruct_Adc.Pull = GPIO_NOPULL;
HAL_GPIO_Init(ADCx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_Adc);
if (ADCx_DMA == ENABLE) __HAL_LINKDMA(hadc, DMA_Handle, DMA_HandleStruct);	
}
#endif /* ADC_Software */

/**************************************************************/

#ifdef ADC_Timer
ADC_HandleTypeDef ADC_HandleStruct;
ADC_ChannelConfTypeDef ADC_ChannelStruct;
GPIO_InitTypeDef GPIO_InitStruct_Adc;
TIM_HandleTypeDef TIM_HandleStruct;
TIM_MasterConfigTypeDef MasterConfigStruct;	
DMA_HandleTypeDef   DMA_HandleStruct;

void ADC_Timer_Config(void){
__TIM3_CLK_ENABLE();
TIM_HandleStruct.Instance = TIM3;
TIM_HandleStruct.Init.Period = ADCx_Trigger_Period - 1;
TIM_HandleStruct.Init.Prescaler = (uint32_t) ((SystemCoreClock /2) / ADCx_Trigger_Frequency) - 1;
TIM_HandleStruct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
TIM_HandleStruct.Init.CounterMode = TIM_COUNTERMODE_UP;
HAL_TIM_Base_Init(&TIM_HandleStruct);	
HAL_TIM_Base_Start(&TIM_HandleStruct);
HAL_TIM_GenerateEvent (&TIM_HandleStruct, TIM_EventSource_Trigger);	
MasterConfigStruct.MasterOutputTrigger = TIM_TRGO_UPDATE;
MasterConfigStruct.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
HAL_TIMEx_MasterConfigSynchronization(&TIM_HandleStruct, &MasterConfigStruct);	
ADC_HandleStruct.Instance = ADCx;  
ADC_HandleStruct.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
ADC_HandleStruct.Init.Resolution = ADC_RESOLUTION12b;
ADC_HandleStruct.Init.ScanConvMode = DISABLE;
ADC_HandleStruct.Init.ContinuousConvMode = DISABLE;
ADC_HandleStruct.Init.DiscontinuousConvMode = DISABLE;
ADC_HandleStruct.Init.NbrOfDiscConversion = 0;
ADC_HandleStruct.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
ADC_HandleStruct.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_TRGO;
ADC_HandleStruct.Init.DataAlign = ADC_DATAALIGN_RIGHT;
ADC_HandleStruct.Init.NbrOfConversion = 1;
ADC_HandleStruct.Init.DMAContinuousRequests = ADCx_DMA;
ADC_HandleStruct.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
HAL_ADC_Init(&ADC_HandleStruct);
ADC_ChannelStruct.Channel = ADCx_CHANNEL;
ADC_ChannelStruct.Rank = 1;
ADC_ChannelStruct.SamplingTime = ADCx_SamplingTime;
ADC_ChannelStruct.Offset = 0;

HAL_ADC_ConfigChannel(&ADC_HandleStruct, &ADC_ChannelStruct);
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc){	
ADCx_CLK_ENABLE();	
ADCx_CHANNEL_GPIO_CLK_ENABLE();
GPIO_InitStruct_Adc.Pin = ADCx_CHANNEL_PIN;
GPIO_InitStruct_Adc.Mode = GPIO_MODE_ANALOG;
GPIO_InitStruct_Adc.Pull = GPIO_NOPULL;
HAL_GPIO_Init(ADCx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_Adc);
if (ADCx_DMA == ENABLE) __HAL_LINKDMA(hadc, DMA_Handle, DMA_HandleStruct);	
HAL_NVIC_SetPriority(ADCx_IRQn, 1, 1);
HAL_NVIC_EnableIRQ(ADCx_IRQn);	
}

void ADCx_IRQHandler(void){
HAL_ADC_IRQHandler(&ADC_HandleStruct);
}
#endif /* ADC_Timer */

/**************************************************************/

#ifdef DAC_Notrigger
DAC_HandleTypeDef DAC_HandleStruct;
DAC_ChannelConfTypeDef DAC_ChannelStruct;
GPIO_InitTypeDef GPIO_InitStruct_Dac;

void DAC_Notrigger_Config(void){
DAC_HandleStruct.Instance = DACx;
HAL_DAC_Init(&DAC_HandleStruct);
DAC_ChannelStruct.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
DAC_ChannelStruct.DAC_Trigger = DAC_TRIGGER_NONE;
HAL_DAC_ConfigChannel(&DAC_HandleStruct,&DAC_ChannelStruct,DACx_CHANNEL);
HAL_DAC_SetValue(&DAC_HandleStruct,DACx_CHANNEL,DAC_ALIGN_12B_R,0);
}

void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac){	
DACx_CLK_ENABLE();	
DACx_CHANNEL_GPIO_CLK_ENABLE();
GPIO_InitStruct_Dac.Pin = DACx_CHANNEL_PIN;
GPIO_InitStruct_Dac.Mode = GPIO_MODE_ANALOG;
GPIO_InitStruct_Dac.Pull = GPIO_NOPULL;
HAL_GPIO_Init(DACx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_Dac);
}
#endif /* DAC_Notrigger */

/**************************************************************/

#ifdef DAC_Software
DAC_HandleTypeDef DAC_HandleStruct;
DAC_ChannelConfTypeDef DAC_ChannelStruct;
GPIO_InitTypeDef GPIO_InitStruct_Dac;

void DAC_Software_Config(void){
DAC_HandleStruct.Instance = DACx;
HAL_DAC_Init(&DAC_HandleStruct);
DAC_ChannelStruct.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
DAC_ChannelStruct.DAC_Trigger = DAC_TRIGGER_SOFTWARE;
HAL_DAC_ConfigChannel(&DAC_HandleStruct,&DAC_ChannelStruct,DACx_CHANNEL);
HAL_DAC_SetValue(&DAC_HandleStruct,DACx_CHANNEL,DAC_ALIGN_12B_R,0);
}

void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac){	
DACx_CLK_ENABLE();	
DACx_CHANNEL_GPIO_CLK_ENABLE();
GPIO_InitStruct_Dac.Pin = DACx_CHANNEL_PIN;
GPIO_InitStruct_Dac.Mode = GPIO_MODE_ANALOG;
GPIO_InitStruct_Dac.Pull = GPIO_NOPULL;
HAL_GPIO_Init(DACx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_Dac);
}
#endif /* DAC_Software */

/**************************************************************/

#ifdef DAC_Timer
DAC_HandleTypeDef DAC_HandleStruct;
DAC_ChannelConfTypeDef DAC_ChannelStruct;
TIM_HandleTypeDef TIM6_HandleStruct;
TIM_MasterConfigTypeDef TIM6_MasterConfigStruct;
GPIO_InitTypeDef GPIO_InitStruct_Dac;

void DAC_Timer_Config(void){
TIM6_HandleStruct.Instance = TIM6;
TIM6_HandleStruct.Init.Period = DAC_Trigger_Period - 1;
TIM6_HandleStruct.Init.Prescaler = (uint32_t) ((SystemCoreClock /2) / DAC_Trigger_Frequency) - 1;
TIM6_HandleStruct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
TIM6_HandleStruct.Init.CounterMode = TIM_COUNTERMODE_UP;
HAL_TIM_Base_Init(&TIM6_HandleStruct);
TIM6_MasterConfigStruct.MasterOutputTrigger = TIM_TRGO_UPDATE;
TIM6_MasterConfigStruct.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
HAL_TIMEx_MasterConfigSynchronization(&TIM6_HandleStruct, &TIM6_MasterConfigStruct);	
HAL_TIM_Base_Start_IT(&TIM6_HandleStruct);
DAC_HandleStruct.Instance = DACx;
HAL_DAC_Init(&DAC_HandleStruct);
DAC_ChannelStruct.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
DAC_ChannelStruct.DAC_Trigger = DAC_TRIGGER_T6_TRGO;
HAL_DAC_ConfigChannel(&DAC_HandleStruct,&DAC_ChannelStruct,DACx_CHANNEL);
HAL_DAC_SetValue(&DAC_HandleStruct,DACx_CHANNEL,DAC_ALIGN_12B_R,0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim){
__TIM6_CLK_ENABLE();
HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 4, 0);
HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

void TIM6_DAC_IRQHandler(void){
HAL_TIM_IRQHandler(&TIM6_HandleStruct);
}

void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac){	
DACx_CLK_ENABLE();	
DACx_CHANNEL_GPIO_CLK_ENABLE();
GPIO_InitStruct_Dac.Pin = DACx_CHANNEL_PIN;
GPIO_InitStruct_Dac.Mode = GPIO_MODE_ANALOG;
GPIO_InitStruct_Dac.Pull = GPIO_NOPULL;
HAL_GPIO_Init(DACx_CHANNEL_GPIO_PORT, &GPIO_InitStruct_Dac);
}
#endif /* DAC_Timer */

/**************************************************************/

#ifdef DMA_M2M

DMA_HandleTypeDef   DMA_HandleStruct;

void DMA_M2M_Config(void){
DMAx_CLK_ENABLE();

DMA_HandleStruct.Init.Channel = DMAx_CHANNEL;                
DMA_HandleStruct.Init.Direction = DMA_MEMORY_TO_MEMORY;
DMA_HandleStruct.Init.PeriphInc = DMAx_PINC;              
DMA_HandleStruct.Init.MemInc = DMAx_MINC;                  
DMA_HandleStruct.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;  
DMA_HandleStruct.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;     
DMA_HandleStruct.Init.Mode = DMA_NORMAL;
DMA_HandleStruct.Init.Priority = DMA_PRIORITY_HIGH;
DMA_HandleStruct.Init.FIFOMode = DMAx_FIFOMODE; 
DMA_HandleStruct.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;  
DMA_HandleStruct.Init.MemBurst = DMAx_MEMBURST;
DMA_HandleStruct.Init.PeriphBurst = DMA_PBURST_SINGLE;
DMA_HandleStruct.Instance = DMAx_STREAM;
HAL_DMA_Init(&DMA_HandleStruct);
HAL_NVIC_SetPriority(DMAx_STREAM_IRQ, 0, 0);
HAL_NVIC_EnableIRQ(DMAx_STREAM_IRQ);
}

void DMAx_STREAM_IRQHANDLER(void){
HAL_DMA_IRQHandler(&DMA_HandleStruct);  
}
#endif /* DMA_M2M */

/**************************************************************/

#ifdef DMA_P2M

DMA_HandleTypeDef   DMA_HandleStruct;

void DMA_P2M_Config(){
DMAx_CLK_ENABLE();

DMA_HandleStruct.Init.Channel = DMAx_CHANNEL;                
DMA_HandleStruct.Init.Direction = DMA_PERIPH_TO_MEMORY;
DMA_HandleStruct.Init.PeriphInc = DMAx_PINC;              
DMA_HandleStruct.Init.MemInc = DMAx_MINC;                  
DMA_HandleStruct.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;  
DMA_HandleStruct.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;     
DMA_HandleStruct.Init.Mode = DMA_CIRCULAR;
DMA_HandleStruct.Init.Priority = DMA_PRIORITY_HIGH;
DMA_HandleStruct.Init.FIFOMode = DMAx_FIFOMODE; 
DMA_HandleStruct.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;  
DMA_HandleStruct.Init.MemBurst = DMAx_MEMBURST;
DMA_HandleStruct.Init.PeriphBurst = DMAx_PBURST;
DMA_HandleStruct.Instance = DMAx_STREAM;
HAL_DMA_Init(&DMA_HandleStruct);
HAL_NVIC_SetPriority(DMAx_STREAM_IRQ, 0, 0);
HAL_NVIC_EnableIRQ(DMAx_STREAM_IRQ);

}

void DMAx_STREAM_IRQHANDLER(void){
HAL_DMA_IRQHandler(&DMA_HandleStruct);  
}
#endif /* DMA_P2M */

#ifdef AUP_Audio_Board

#include "stdint.h"

typedef enum {
    AUDIO_CH_LEFT  = 1,
    AUDIO_CH_RIGHT = 2,
    AUDIO_CH_BOTH  = (AUDIO_CH_LEFT | AUDIO_CH_RIGHT)
} DspAudioChannelSelect;
#define IS_LEFT_CH_SELECT(MASK)  (((MASK) & AUDIO_CH_LEFT) != 0)
#define IS_RIGHT_CH_SELECT(MASK) (((MASK) & AUDIO_CH_RIGHT) != 0)

typedef struct{
    int32_t mask;
    int32_t input_l;
    int32_t input_r;
    int32_t output_l;
    int32_t output_r;
} I2S_Data_TypeDef;

void ProcessData(I2S_Data_TypeDef* I2S_Data);

/*! This enum describes the different sampling frequency setup of the CODEC */
typedef enum {
    FS_8000_HZ  = 8000,
    FS_16000_HZ = 16000,
    FS_22050_HZ = 22050,
    FS_32000_HZ = 32000,
    FS_44100_HZ = 44100,
    FS_48000_HZ = 48000,
    FS_96000_HZ = 96000
} sampling_rate;

/*! This enum describes the different input setup of the CODEC */		
typedef enum {
    AUDIO_INPUT_LINE,  // Select ADC input Line In
    AUDIO_INPUT_MIC,       // Select ADC input Microphone In
} audio_input;

/*! This enum describes the different input setup of the CODEC */		
typedef enum {
    IO_METHOD_INTR,     // User I2S interruptions to controll the flow of the program (generate interruption when  irq_depth=<FIFO level)
    IO_METHOD_DMA,      // Use DMA requests to controll the flow of the program (generat a request whem dma_depth=<FIFO level)
    IO_METHOD_POLL,
} mode;

/*! This enum describes two channels of DMA data */		
typedef enum {
    LEFT = 0,
    RIGHT = 1,
} audio_data_channel;

/*! This enum describes the test pin */
typedef enum {
    PD15,
} test_pin_num;

#define TEST_PIN PD15

#define PING 1
#define PONG 0

#define HIGH 1
#define LOW 0

#define DMA_BUFFER_SIZE 256

short prbs(void);
void AudioInit(sampling_rate, audio_input, mode);

void TestPinInit(test_pin_num);
void TestPinOut(test_pin_num, int value);
void TestPinToggle(test_pin_num);

#endif /* AUP_Audio_Board */

/**************************************************************/

#endif /* hal_config */
