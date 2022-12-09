# FreeRTOS Template

## Functions 
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data).
  -used to send data over UART peripheral.
uint8_t USART_GetFlagStatus(USART_TypeDef* USARTx, uint32_t USART_FLAG);
  -used to check the flag to know the Status of some register
void USART2_init(void);  //UART peripheral Initialization
  -used to initalize the UART hardware 
void GPIO_Init();        // Hardware to work with UART
  -GPIO(General purpose Input Output) 
void Error_handler();
  -infinte loop when error handle happens 
void prm(char *msg);
  -used to send strings over UART 
  
## Include 
#include "stm32f3xx.h"
  -stm32f3 header file 
#include "stm32f3xx_nucleo.h"
  -header file for nucleo board
#include "FreeRTOS.h"
  -FreeRTOS header file
#include "SEGGER_SYSVIEW.h"
  -will be explanid in the future but it used to watch the context switching between tasks



