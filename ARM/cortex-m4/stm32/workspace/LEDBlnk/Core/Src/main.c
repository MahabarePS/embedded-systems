#include<stm32f4xx_hal.h>

#define LED_PORT GPIOC
#define LED_PIN GPIO_PIN_10

//Configure the LED Port Pin
void LED_init(void);

int main(void){
	HAL_Init();
	LED_init();
	while(1){
		HAL_GPIO_WritePin(LED_PORT,LED_PIN,GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(LED_PORT,LED_PIN,GPIO_PIN_RESET);
		HAL_Delay(1000);
	}
}
void LED_init(void){
GPIO_InitTypeDef GPIOstruct={0};
//assign the clock to the LED PORT
__HAL_RCC_GPIOC_CLK_ENABLE();
GPIOstruct.Pin=LED_PIN;
GPIOstruct.Mode=GPIO_MODE_OUTPUT_PP;
GPIOstruct.Pull=GPIO_NOPULL;
GPIOstruct.Speed=GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(LED_PORT,&GPIOstruct);
}
