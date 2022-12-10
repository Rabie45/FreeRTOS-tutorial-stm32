/**
 ******************************************************************************
 * @file    main.c
 * @author  Abdallah rabie
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f3xx.h"
#include "stm32f3xx_nucleo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "string.h"
#include "SEGGER_SYSVIEW.h"
//extern void initialise_monitor_handles();

//some macros


/*******************Variables**************************/


uint16_t buttomValue=GPIO_PIN_RESET;
TaskHandle_t xTaskHandler1 = NULL;
TaskHandle_t xTaskHandler2 = NULL;
TaskFunction_t pxTaskCode;
UART_HandleTypeDef uart;
char user_data[250];


/*******************Functions**************************/
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint8_t USART_GetFlagStatus(USART_TypeDef* USARTx, uint32_t USART_FLAG);
void USART2_init(void);
void GPIO_Init();
void Error_handler();
void prm(char *msg);
void rtos_delay(uint32_t delay_in_ms);
void ButtonTask(void *params);
void LEDTask(void *params);



int main(void) {

	DWT->CTRL |=(1<<0);
	//initialise_monitor_handles();
	HAL_Init();
	GPIO_Init();
	USART2_init();

	//sprintf(user_data,"the app is running \r\n");
	//prm(user_data);

	/*Start SEEGER Captures*/
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();

	/*Create two Taskes*/
	xTaskCreate(LEDTask, "LED Task", 500, NULL, 2,
			&xTaskHandler1);
		xTaskCreate(ButtonTask, "Button Task", 500, NULL, 2,
				&xTaskHandler2);


	vTaskStartScheduler();
	for (;;);
}

void LEDTask(void *params) {
	while (1) {
		uint32_t current_count=0;
		if(xTaskNotifyWait(0,0,&current_count,portMAX_DELAY) == pdTRUE){
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
			sprintf(user_data,"Notification is received : Button press count : %ld \r\n",current_count);
			prm(user_data);
				}


	}
}
void ButtonTask(void *params) {
	while (1) {


		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == GPIO_PIN_RESET)
		{
			rtos_delay(100);

			xTaskNotify(xTaskHandler1,0x0,eIncrement);
		}
	}
}
void USART2_init(void) {

	uart.Instance = USART2;
	uart.Init.BaudRate = 115200;
	uart.Init.Mode = USART_MODE_TX_RX;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = USART_STOPBITS_1;
	uart.Init.Parity = USART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	while (HAL_UART_Init(&uart) != HAL_OK) {
		Error_handler();
	}

}
void GPIO_Init(){

	GPIO_InitTypeDef led_gpio,button_gpio;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	led_gpio.Mode=GPIO_MODE_OUTPUT_PP;
	led_gpio.Pin=GPIO_PIN_5;
	led_gpio.Speed=GPIO_SPEED_FREQ_MEDIUM;
	led_gpio.Pull=GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&led_gpio);

	button_gpio.Mode=GPIO_MODE_INPUT;
	button_gpio.Pin=GPIO_PIN_13;
	button_gpio.Speed=GPIO_SPEED_FREQ_MEDIUM;
	button_gpio.Pull=GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC,&button_gpio);

}
void Error_handler() {

	while (1)
		;
}
void prm(char *msg) {
	uint16_t len = strlen(msg);

for(uint32_t i=0;i<len;i++){
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)!= SET);
	USART_SendData(USART2,msg[i]);
}
}
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data)
{
  /* Transmit Data */
  USARTx->TDR = (Data & (uint16_t)0x01FF);
}
uint8_t USART_GetFlagStatus(USART_TypeDef* USARTx, uint32_t USART_FLAG)
{
  uint8_t bitstatus = RESET;

  if ((USARTx->ISR & USART_FLAG) != (uint16_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

void rtos_delay(uint32_t delay_in_ms){

	uint32_t current_ticks= xTaskGetTickCount();
	uint32_t delay_in_ticks=(delay_in_ms * configTICK_RATE_HZ) /1000;
	while(xTaskGetTickCount() <(current_ticks+delay_in_ticks));
}
