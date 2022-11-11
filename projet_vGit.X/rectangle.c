#include "my_lib.h"

void PWM1_Init(long freq){
    OSCCON = 0b01110010;	/* Set internal clock to 8MHz */
    TRISC = 0b11111101;		/* Set CCP1 pin as output for PWM out */
        /* CCP PWM mode */
    CCP2CON = 0b00001100;
    TMR2 = 0;		/* Clear Timer2 initially */
    T2CON = 0b00000111;		/* Timer ON for start counting*/ //  Set prescalar 16   
    PR2 = (int) ((125000 - freq) / freq);           //  configure timer2 period
}


void PWM1_setDC(float dc){
    float calcul = ((PR2 + 1) * (dc / 100));
    CCPR2L = (int) calcul;
    //CCPR2L = 62;
    CCP2CONbits.DC2B1 = 0;
    CCP2CONbits.DC2B0 = 0;
}

