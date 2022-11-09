#include "my_lib.h"

void PWM1_Init(long frequence){
    if(frequence > 490 && frequence < 125000)
    {
        OSCCON = 0b01110010;	/* Set internal clock to 8MHz */
        TRISC = 0b11111101;		/* Set CCP1 pin as output for PWM out */

        /* CCP PWM mode */
        CCP2CON = 0b00001100;

        /* Timer2 configuration */
        PR2 = (125000 - frequence) / frequence;           //  configure timer2 period

        TMR2 = 0;		/* Clear Timer2 initially */
        T2CON = 0b00000111;		/* Timer ON for start counting*/ //  Set prescalar 16   
    }
    else
    {
        OSCCON = 0b01110010;	/* Set internal clock to 8MHz */
        TRISC = 0b11111101;		/* Set CCP1 pin as output for PWM out */

        /* CCP PWM mode */
        CCP2CON = 0b00001100;

        /* Timer2 configuration */
        PR2 = (125000 - 500) / 500;           //  configure timer2 period

        TMR2 = 0;		/* Clear Timer2 initially */
        T2CON = 0b00000111;		/* Timer ON for start counting*/ //  Set prescalar 16   
    }
}


void PWM1_setDC(int dutycycle){
    /*
    CCPR1L = ((PR2 + 1) * (dutycycle/100)) >> 2;
    if ((((PR2 + 1) * (dutycycle/100)) >> 1) % 2 == 0)
    {
        CCP1CONbits.DC1B1 = 0;
    }
    else
    {
        CCP1CONbits.DC1B1 = 1;
    }
    if ((((PR2 + 1) * (dutycycle/100))) % 2 == 0)
    {
        CCP1CONbits.DC1B0 = 0;
    }
    else
    {
        CCP1CONbits.DC1B0 = 1;
    }
    */
    CCPR2L = 0b00001111;
    CCP2CONbits.DC2B1 = 1;
    CCP2CONbits.DC2B0 = 0;
}

