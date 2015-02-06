/* 
* File:   initLab0.h
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#ifndef INITLAB0_H
#define	INITLAB0_H


//Use defines for pin settings to make your code
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12
#define OFF 1
#define ON 0
#define output 0
#define input 1
#define Pressed 0
#define fcy 14745600 //Clock frequency
#define delay 2 //2 seconds delay to count
#define presc 64 //Prescalar number


void initLEDs();
void initSW1();
void initTimer1();
void LED_ON(int led);

#endif	/* INITLAB0_H */

