/* 
 * File:   TMR0.h
 * Author: Prasad Mahabare
 *
 * Created on 23 January, 2026, 10:20 PM
 */

#ifndef TMR0_H
#define	TMR0_H

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
    
#define PULSE_WIDTH 75
#define BLINK_PERIOD 5000
    
#define LED LATAbits.LA0

volatile uint16_t cycle=0;


void Timer0_init(){
    T0CON = 0x07;   // OFF, 16-bit, prescaler 1:256
    // preload for ~5 seconds
    TMR0H = 0x67;
    TMR0L = 0x69;

    TMR0IF = OFF;
    TMR0IE = ON;
    GIE = ON;

    TMR0ON = ON;
}

void __interrupt() ISR(){
    if(TMR0IF){
                TMR0IF = OFF;
                // reload
                TMR0H = 0x67;
                TMR0L = 0x69;
                cycle=1;
            }
}


#ifdef	__cplusplus
}
#endif

#endif	/* TMR0_H */

