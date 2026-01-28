#include<stm32f4xx_hal.h>
//SW
#define SW_PORT GPIOB
#define SW_PIN GPIO_PIN_0
//LED
#define LED_PORT GPIOC
#define LED_PIN GPIO_PIN_10

//SW and LED config functions
void btn_init(void);
void led_init(void);

int main(void){
	HAL_Init();

}
void btn_init(void){
	GPIO_InitTypeDef GPIO_initStruct={0};
	//Set clock to the SW PORT B
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_initStruct.Pin=SW_PIN;
	GPIO_initStruct.Mode=GPIO_MODE_IT_FALLING;
	GPIO_initStruct.Pull=GPIO_NOPULL;
	GPIO_initStruct.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(SW_PORT,&GPIO_initStruct);
}
void led_init(void){
	GPIO_InitTypeDef GPIO_initStruct={0};
	//set the clock to the LED PORT C
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_initStruct.Pin=LED_PIN;
	GPIO_initStruct.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_initStruct.Pull=GPIO_NOPULL;
	GPIO_initStruct.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_PORT,&GPIO_initStruct);
}
