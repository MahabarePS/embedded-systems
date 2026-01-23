/* 
 * File:   LCD.h
 * Author: Prasad Mahabare
 *
 * Created on 23 January, 2026, 9:52 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>
#include<stdio.h>

#pragma config OSC = HS 
#pragma config WDT = OFF          

#define _XTAL_FREQ 8000000

#define OUTPUT_PIN 0
#define INPUT_PIN 1
    
#define ON 1
#define OFF 0
    
#define LED LATAbits.LA0

volatile uint8_t swEvent=0,cycle = 0;; 

uint8_t pressCount=0, 
 


void Timer0_init(){
    T0CON = 0x07;   // OFF, 16-bit, prescaler 1:256
    TMR0H = 0x67;
    TMR0L = 0x69;

    TMR0IF = 0;
    TMR0IE = 1;
    INT0IF = 0;
    INT0IE = 1;
    GIE = 1;

    TMR0ON = 1;
}

void __interrupt() ISR(){
    if(TMR0IF){
                TMR0IF = 0;
                cycle++;
            }
}



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

