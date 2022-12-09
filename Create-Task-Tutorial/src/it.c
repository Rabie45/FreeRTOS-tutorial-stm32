#include "stm32f3xx.h"
#include "stm32f3xx_nucleo.h"

extern USART_HandleTypeDef uart;
void SysTick_Handler(void)
{
//	HAL_IncTick();
	//HAL_SYSTICK_IRQHandler();
}
void USART2_IRQHandler(void)
{

	HAL_UART_IRQHandler(&uart);

}
