#include "stm32f3xx.h"
#include "stm32f3xx_nucleo.h"

extern USART_HandleTypeDef uart;

void USART2_IRQHandler(void)
{

	HAL_UART_IRQHandler(&uart);

}
