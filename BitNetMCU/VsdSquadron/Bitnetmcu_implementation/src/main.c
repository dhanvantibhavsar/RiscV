/* Using BitNeuMCU for inference of 16x16 MNIST images on a CH32V003 */
#include "ch32v00x.h"
#include "debug.h"

// Declare processfclayer an SRAM based function for speedup
// void processfclayer(int8_t *,  const uint32_t *, int32_t, uint32_t, uint32_t, int32_t *)__attribute__((section(".srodata"))) __attribute__((used));

#include "../data/BitNetMCU_inference.c"
// #include "BitNetMCU_model_1k.h"
#include "../data/BitNetMCU_model28.h"
// #include "BitNetMCU_model_12k_FP130.h"
#include <stdio.h>

#define Demo 0 
// #define Demo 1

// Demo = 0 for real time implementatioin with camera 1  
// Demo = 1 for Demo with test images 

#define SEG7_PORTC GPIOC
#define SEG7_PIN_A GPIO_Pin_0 // pc0
#define SEG7_PIN_B GPIO_Pin_1 //pc1
#define SEG7_PIN_C GPIO_Pin_2 // pc2
#define SEG7_PIN_D GPIO_Pin_3 //pc3
#define SEG7_PIN_E GPIO_Pin_4 // pc4
#define SEG7_PIN_F GPIO_Pin_5 // pc5
#define SEG7_PIN_G GPIO_Pin_6 // pc6

void USART1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/***********************
 * @fn      USART1_IRQHandler
 *
 * @brief   This function handles USART3 global interrupt request.
 *
 * @return  none
 */
 int8_t RxBuffer1[784];
 int RxCnt1 = 0;
 int RxFinish = 0;
int capturing= 0;
int prev_capture = 1;
void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void Delay_Init(void);
void Delay_Ms(uint32_t n);

// digit patter for 7 segment display
const uint8_t digitPatterns[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};



// Test images
// const int8_t input_data_0[256] = {-22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, 11.0, 64.0, 30.0, 6.0, -14.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, 28.0, 124.0, 127.0, 115.0, 66.0, -3.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -12.0, 18.0, 58.0, 97.0, 124.0, 70.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -16.0, 47.0, 100.0, -11.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -21.0, 44.0, 104.0, -11.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -16.0, 68.0, 106.0, -12.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -13.0, 77.0, 99.0, -18.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -13.0, 77.0, 96.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -13.0, 77.0, 96.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -13.0, 77.0, 96.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -17.0, 62.0, 97.0, -20.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, 18.0, 71.0, -14.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -22.0, -20.0, -16.0, -21.0, -22.0, -22.0, -22.0, -22.0, -22.0};
// const uint8_t label_0 = 7;
// const int8_t input_data_1[256] = {-20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -4.0, 69.0, 6.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 5.0, 106.0, 42.0, -18.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 28.0, 119.0, 50.0, -17.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -14.0, 64.0, 125.0, 19.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 3.0, 99.0, 121.0, 13.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -19.0, 33.0, 120.0, 100.0, -7.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -16.0, 71.0, 126.0, 65.0, -17.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 6.0, 106.0, 112.0, 13.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 47.0, 125.0, 100.0, -3.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 54.0, 127.0, 68.0, -19.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 53.0, 119.0, 43.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 16.0, 59.0, -3.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0};
// const uint8_t label_1 = 1;
// const int8_t input_data_2[256] = {-21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -16.0, 11.0, 49.0, 48.0, 0.0, -20.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -20.0, -5.0, 41.0, 80.0, 62.0, 56.0, 70.0, 0.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -18.0, 10.0, 76.0, 58.0, 3.0, -18.0, -14.0, 70.0, 24.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -19.0, 28.0, 94.0, 29.0, -15.0, -21.0, -21.0, 1.0, 99.0, 47.0, -20.0, -21.0, -21.0, -21.0, -21.0, -21.0, 7.0, 87.0, 29.0, -19.0, -21.0, -20.0, -9.0, 65.0, 90.0, 7.0, -21.0, -21.0, -21.0, -21.0, -21.0, -19.0, 55.0, 67.0, -14.0, -21.0, -20.0, -4.0, 77.0, 118.0, 30.0, -19.0, -21.0, -21.0, -21.0, -21.0, -21.0, -17.0, 68.0, 33.0, -12.0, -0.0, 29.0, 69.0, 127.0, 72.0, -12.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -18.0, 55.0, 91.0, 84.0, 75.0, 38.0, 51.0, 111.0, 8.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -11.0, 16.0, 14.0, -8.0, -13.0, 62.0, 65.0, -18.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -3.0, 84.0, 18.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, 14.0, 68.0, -13.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, 8.0, 39.0, -17.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -20.0, -18.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0, -21.0};
// const uint8_t label_2 = 9;
// const int8_t input_data_3[256] = {-20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -13.0, -15.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -6.0, 41.0, 78.0, 38.0, -18.0, -20.0, -20.0, -20.0, -20.0, -17.0, -17.0, -20.0, -20.0, -20.0, -20.0, -11.0, 67.0, 109.0, 63.0, 6.0, -20.0, -20.0, -20.0, -20.0, -8.0, 48.0, 50.0, -8.0, -20.0, -20.0, -20.0, 2.0, 108.0, 65.0, -14.0, -20.0, -20.0, -20.0, -20.0, -12.0, 59.0, 114.0, 89.0, 4.0, -20.0, -20.0, -20.0, 10.0, 114.0, 27.0, -20.0, -20.0, -20.0, -20.0, -20.0, 36.0, 122.0, 65.0, -14.0, -20.0, -20.0, -20.0, -20.0, -2.0, 96.0, 55.0, -13.0, -20.0, -20.0, -20.0, -12.0, 89.0, 114.0, 16.0, -20.0, -20.0, -20.0, -20.0, -20.0, -17.0, 43.0, 100.0, 46.0, -5.0, -15.0, -18.0, 6.0, 115.0, 84.0, -9.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -14.0, 45.0, 115.0, 100.0, 78.0, 50.0, 66.0, 127.0, 53.0, -17.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -13.0, 28.0, 76.0, 91.0, 104.0, 127.0, 122.0, 28.0, -18.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -19.0, -16.0, -14.0, -1.0, 71.0, 114.0, 8.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, 19.0, 112.0, 39.0, -13.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -11.0, 70.0, 89.0, 19.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -18.0, -6.0, -18.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0};
// const uint8_t label_3 = 4;


// USART Initialize at PC0 and PC1
void USART_Initialize(uint32_t baudrate) {
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    // Enable GPIOD  and USART1 clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC | RCC_APB2Periph_USART1, ENABLE);

    // Configure USART1 Tx (PA.09) as alternate function push-pull
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // Configure USART1 Rx (PA.10) as input floating
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // USART1 configuration
    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    // Apply USART1 configuration
    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    // Enable USART1
    USART_Cmd(USART1, ENABLE);
}
void NVIC_Config(void) {
    NVIC_InitTypeDef NVIC_InitStructure;

    // Configure the NVIC for USART1 interrupt
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void USART1_IRQHandler(void)
{
    
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {   
        int8_t capture_data = (int8_t)USART_ReceiveData(USART1);
        if (RxFinish==1){
            USART_ClearITPendingBit(USART1, USART_IT_RXNE);
            return;
        }
        if (capturing){
            RxBuffer1[RxCnt1++] = capture_data;
            if(RxCnt1 >= 784){
            printf("image received \n");
                
                RxCnt1 = 0;
                RxFinish=1;
                capturing=0;
            }
        }
        else if (capture_data ==(int8_t)0){
            prev_capture=0;
        }
        else if(capture_data == (int8_t)4 && prev_capture == 0){
            capturing = 1;
            prev_capture = 1;
        }
        else{
            prev_capture = 1;
            // USART1->DATAR = capture_data;
            
        }
    }
    
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}
void BitMnistInference(const int8_t *input, const uint8_t label, const uint8_t sample) {
    int32_t layer_out[MAX_N_ACTIVATIONS];
    int8_t layer_in[MAX_N_ACTIVATIONS];
	int32_t prediction;
	uint32_t startticks, endticks;


	startticks = SysTick->CNT;
    processfclayer((int8_t*)input, L1_weights, L1_bitperweight, L1_incoming_weights, L1_outgoing_weights, layer_out);
    ReLUNorm(layer_out, layer_in, L1_outgoing_weights);

    processfclayer(layer_in, L2_weights, L2_bitperweight, L2_incoming_weights,  L2_outgoing_weights, layer_out);
    ReLUNorm(layer_out, layer_in, L2_outgoing_weights);

    processfclayer(layer_in, L3_weights, L3_bitperweight, L3_incoming_weights,  L3_outgoing_weights, layer_out);
    prediction=ReLUNorm(layer_out, layer_in, L3_outgoing_weights);

#if NUM_LAYERS == 4
    processfclayer(layer_in, L4_weights, L4_bitperweight, L4_incoming_weights,  L4_outgoing_weights, layer_out);
    prediction=ReLUNorm(layer_out, layer_in, L4_outgoing_weights);
#endif

	endticks = SysTick->CNT;
    if (label<10){
	    printf( "Inference of Sample %d\tPrediction: %ld\tLabel: %d\tTiming: %lu clock cycles\n", sample, prediction, label, endticks-startticks);	
	}
    else{
	    printf( "Inference of Sample %d\tPrediction: %ld\tTiming: %lu clock cycles\n", sample, prediction,  endticks-startticks);	
	}
    displayDigit(prediction);
}

void displayDigit(uint8_t digit) {
    if (digit > 9) return;
    // digit=5;
    // printf(digit);
    uint8_t segments = digitPatterns[digit];
	uint8_t ledState = 0;

    // while (1)
	// {
	// 	GPIO_WriteBit(GPIOC, GPIO_Pin_0, ledState);
	// 	ledState ^= 1; // invert for the next run
	// 	// Delay_Ms(1000);
	// }
    // uint8_t GPIO_PIN_SET = 0;
	// uint8_t GPIO_PIN_RESET = GPIO_PIN_SET^1;
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_A, (segments & 0b00000001) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_B, (segments & 0b00000010) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_C, (segments & 0b00000100) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_D, (segments & 0b00001000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_E, (segments & 0b00010000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_F, (segments & 0b00100000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    // GPIO_WriteBit(SEG7_PORTC, SEG7_PIN_G, (segments & 0b01000000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    GPIOC->OUTDR=~segments;
}

void main()
{
	SystemInit();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);
    USART_Initialize(115200);
    NVIC_Config();
    printf("start\n");
    GPIO_InitTypeDef GPIO_InitStructure = {0};
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	// GPIO_InitTypeDef GPIO_InitStructure = {0};

	// // Configure GPIO pins for segments
    // GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    // GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

    // GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    // GPIO_Init(GPIOC, &GPIO_InitStructure);

    int i;

    // for(i=0; i<=9;i++){
    //    displayDigit(i);
    //    Delay_Ms(500);
    // }



//	SysTick->CTLR = 5;  // Use HCLK as time base -> configured in funconfig.h
    int frameCounter=0;

	while(1)
	{
        // printf("%d",frameCounter);
        
        if(RxFinish==1){
            // int sum= 0;
            // for(int i=0;i<256; i++){
            //     sum+=(uint8_t)(RxBuffer1[i]+128);
            // }
            // sum/=256;
            // printf("%d%d",0x00,4);
            while ((USART1->STATR & (uint16_t)0x0080) == (uint16_t)0);
            USART1->DATAR = 0x00;
            while ((USART1->STATR & (uint16_t)0x0080) == (uint16_t)0);

            USART1->DATAR = 0x04;
// 
            for(int i=0;i<784; i++){
                if(RxBuffer1[i]>=0 && RxBuffer1[i]<64){
                    RxBuffer1[i]=1;
                } else{
                    RxBuffer1[i]=0;
                }
                while ((USART1->STATR & (uint16_t)0x0080) == (uint16_t)0);
                USART1->DATAR = RxBuffer1[i];
                
                //printf("%x",RxBuffer1[i]);
                // if(i%28==27){
                //     printf("\n");
                // }
                // sum+=RxBuffer1[i];
            }
            RxFinish = 0;
            capturing = 0;
            BitMnistInference(RxBuffer1, 10, ++frameCounter);
        }
        Delay_Ms(2000);


    }
    // while(Demo){
	// 	printf("Starting MNIST inference...\n");
	// 	BitMnistInference(input_data_0, label_0,1);	
	// 	Delay_Ms(2000);
	// 	BitMnistInference(input_data_1, label_1,2);	
	// 	Delay_Ms(2000);
	// 	BitMnistInference(input_data_2, label_2,3);	
	// 	Delay_Ms(2000);
	// 	BitMnistInference(input_data_3, label_3,4);	
	// 	Delay_Ms(2000);
	// }
}
void NMI_Handler(void) {}
void HardFault_Handler(void)
{
	while (1)
	{
	}
}

