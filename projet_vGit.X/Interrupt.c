#include "my_lib.h"

void initMyPIC18F(void)
{
    // PORTs initialization
    TRISD = 0b00000000; // set PORTD as OUTPUT
    PORTD = 0b00000000; //clear port D
    
    ADCON1 = 0b00001010; //RA0 en mode analog, resultat justifie a gauche et tension de ref VDD
    ADCON0 = 0b00010001; //choix du channel sur RA0   

    TRISA = 0b11110000;
    PORTA = 0b00000000;
    
    INTCONbits.GIE = 1;
    PIE1bits.ADIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1;
}


void __interrupt() irq_handle()
{
    if(PIR1bits.ADIF == 1)
    {
        PIR1bits.ADIF = 0;
        calcul_7segment(ADRESH);
    }
    if(INTCONbits.RBIF == 1) 
    {
        INTCONbits.RBIF = 0;
        if(PORTBbits.RB6 == 1)
        {
            //Move cursor
        }
        if(PORTBbits.RB7 == 1)
        {
            //Action
        }
    }
        
    return;
}
