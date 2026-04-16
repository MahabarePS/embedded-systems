/*
 * ledblink.h
 *
 *  Created on: Mar 16, 2024
 *      Author: DELL
 */

#ifndef INC_LEDBLINK_H_
#define INC_LEDBLINK_H_

#define LED_PORT	GPIOC
#define LED_PIN		GPIO_PIN_10

void pc10_led_init(void);

#endif /* INC_LEDBLINK_H_ */
