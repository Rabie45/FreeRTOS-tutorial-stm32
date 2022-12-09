#include "stm32f3xx_hal.h"

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	gpio_init.Mode = GPIO_MODE_AF_PP;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOA , &gpio_init);

	HAL_NVIC_EnableIRQ(USART2_IRQn);

	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}
void HAL_MspInit(void)
{
	NVIC_SetPriorityGrouping( 0 );
}
