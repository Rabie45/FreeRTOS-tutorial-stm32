# FreeRTOS Template

## Functions 
1. void USART_SendData(USART_TypeDef* USARTx, uint16_t Data).\
   - Used to send data over UART peripheral.
  
2. uint8_t USART_GetFlagStatus(USART_TypeDef* USARTx, uint32_t USART_FLAG);\
   - Used to check the flag to know the Status of some register
  
3. void USART2_init(void);  //UART peripheral Initialization\
   - Used to initalize the UART hardware 
  
4. void GPIO_Init();        // Hardware to work with UART\
   - GPIO(General purpose Input Output) 
  
5. void Error_handler();\
   - Infinte loop when error handle happens 
  
6. void prm(char *msg);\
   - Used to send strings over UART
  
## Include 
1. #include "stm32f3xx.h"\
   - Stm32f3 header file 
2. #include "stm32f3xx_nucleo.h"\
   - Header file for nucleo board
3. #include "FreeRTOS.h"\
   - FreeRTOS header file
4. #include "SEGGER_SYSVIEW.h"\
   - Will be explanid in the future but it used to watch the context switching between tasks


