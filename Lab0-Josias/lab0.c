// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24FJ64GA002.h"
#include "initLab0.h"
#include <stdio.h>


// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



        typedef enum stateTypeEnum{
    //TODO: Define states by name
    led4,
    led5,
    led6,
    led7
}stateType;

volatile stateType State;

int main(void)
{
    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
    State = led4;                           //First state defined
    while(1)
    {
        switch(State){
            case led4:
                LED_ON(4);
                break;
            case led5:
                LED_ON(5);
                break;
            case led6:
                LED_ON(6);
                break;
            case led7:
                LED_ON(7);
                break;
        }
    }
    return 0;
}

void _ISR _CNInterrupt(void){
                                             //Put the interrupt flag down first, always.
            IFS1bits.CNIF = 0;               //Put it down
        if(PORTBbits.RB5 == Pressed){        //Switch1 pressed
            T2CONbits.TON = 1;               //Turn ON timer
        while(PORTBbits.RB5 == Pressed);     //Wait until someone release the switch1
        if(IFS0bits.T3IF == 1){              //If it last more than 2 seconds:
            IFS0bits.T3IF = 0;               //Put down the timer 3 flag
            T2CONbits.TON = 0;               //Turn OFF timer
            TMR2 = 0x0000;                   //Reset the lower counter bits
            TMR3 = 0x0000;                   //Reset the upper counter bits
        if(State == led4) State = led7;      //Return to the last led
        else if(State == led5) State = led4; //Return to the last led
        else if(State == led6) State = led5; //Return to the last led
        else if(State == led7) State = led6; //Return to the last led
        }
        else{
            T2CONbits.TON = 0;               //Turn OFF timer
            TMR2 = 0x0000;                   //Reset the lower counter bits
            TMR3 = 0x0000;                   //Reset the upper counter bits
        if(State == led4) State = led5;      //Go to the next led
        else if(State == led5) State = led6; //Go to the next led
        else if(State == led6) State = led7; //Go to the next led
        else if(State == led7) State = led4; //Go to the next led
        }
    }
}
/*
typedef enum stateTypeEnum{
    //TODO: Define states by name
    led4,
    led5,
    led6,
    led7
}stateType;

volatile stateType State;

int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
    
    while(1)
    {
    if(IFS1bits.CNIF == 1){ //Flag of switch1 went up
        IFS1bits.CNIF = 0; //Put it down
    if(PORTBbits.RB5 == Pressed){ //Switch1 pressed
        T2CONbits.TON = 1; //Turn ON timer
        while(PORTBbits.RB5 == Pressed); //Wait until someone release the switch1
        if(IFS0bits.T3IF == 1){ //If it last more than 2 seconds
            IFS0bits.T3IF = 0; //Put down the timer 3 flag
            T2CONbits.TON = 0; //Turn OFF timer
            TMR2 = 0x0000; //Reset the lower counter bits
            TMR3 = 0x0000; //Reset the upper counter bits
        if(State == led4) State = led7; //Return to the last led
        else if(State == led5) State = led4; //Return to the last led
        else if(State == led6) State = led5; //Return to the last led
        else if(State == led7) State = led6; //Return to the last led
        }
        else{
            T2CONbits.TON = 0; //Turn OFF timer
            TMR2 = 0x0000; //Reset the lower counter bits
            TMR3 = 0x0000; //Reset the upper counter bits
            if(State == led4) State = led5; //Go to the next led
            else if(State == led5) State = led6; //Go to the next led
            else if(State == led6) State = led7; //Go to the next led
            else if(State == led7) State = led4; //Go to the next led
        }
        }
    }
            switch(State){
            case led4:
                LED_ON(4);
                break;
            case led5:
                LED_ON(5);
                break;
            case led6:
                LED_ON(6);
                break;
            case led7:
                LED_ON(7);
                break;
        }
        //Use a switch statement to define the behavior based on the state

    }
    return 0;
}

/*void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 3 flag first!
    }
    //TODO: Change states if necessary.
    //Make sure if you use any variables that they are declared volatile!
}/*
 *
 * */