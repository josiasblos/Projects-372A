/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24FJ64GA002.h"
#include "initLab0.h"

void initLEDs(){
    //TODO: Initialize the pin connected to the LEDs as outputs
TRISBbits.TRISB15 = output; // pin 26, led 4, output
TRISBbits.TRISB14 = output; // pin 25, led 5, output
TRISBbits.TRISB13 = output; // pin 24, led 6, output
TRISBbits.TRISB12 = output; // pin 23, led 7, output
    //TODO: Turn each LED OFF
LED4 = OFF; // pin 26, led 4 OFF
LED5 = OFF; // pin 25, led 5 OFF
LED6 = OFF; // pin 24, led 6 OFF
LED7 = OFF; // pin 23, led 7 OFF
    /*TRISB &= 0x0FFF;
    LATB |= 0xF000;*/
}

void initSW1(){
    //TODO: Initialize the pin connected to the switch as an input.
TRISBbits.TRISB5 = input; // pin 14, switch 1, input
IEC1bits.CNIE = 1; //Enable the overall CN Interrupt
IFS1bits.CNIF = 0; //Put flag down
CNEN2bits.CN27IE = 1; //Enable CN for pin 14, switch 1, CN27
}


void initTimer1(){
    //TODO: Initialize the timer
long int PR; //initialize a 32-bit period register for a 32-bit timer
PR = (fcy*delay)/presc - 1; //PR formula
PR3 = (PR >> 16); //16 upper bits of PR
PR2 = (PR << 16) >> 16; //16 lower bits of PR
T2CONbits.T32 = 1; //32-bit mode enabled
T2CONbits.TCKPS = 0b10; //Prescalar of 64, page 126
IEC0bits.T3IE = 1; //Enable interruption
IFS0bits.T3IF = 0; //Put timer3 flag down
}

void LED_ON(int led){
    switch(led){
            case 4:
                LED4 = ON;  // pin 26, led 4 ON
                LED5 = OFF; // pin 25, led 5 OFF
                LED6 = OFF; // pin 24, led 6 OFF
                LED7 = OFF; // pin 23, led 7 OFF
                break;
            case 5:
                LED4 = OFF;  // pin 26, led 4 OFF
                LED5 = ON; // pin 25, led 5 ON
                LED6 = OFF; // pin 24, led 6 OFF
                LED7 = OFF; // pin 23, led 7 OFF
                break;
            case 6:
                LED4 = OFF;  // pin 26, led 4 OFF
                LED5 = OFF; // pin 25, led 5 OFF
                LED6 = ON; // pin 24, led 6 ON
                LED7 = OFF; // pin 23, led 7 OFF
                break;
            case 7:
                LED4 = OFF;  // pin 26, led 4 OFF
                LED5 = OFF; // pin 25, led 5 OFF
                LED6 = OFF; // pin 24, led 6 OFF
                LED7 = ON; // pin 23, led 7 ON
                break;
    }
   /* LATB |= 0xF000;
    LATB ^= (0x1 << (19 - led));*/
}