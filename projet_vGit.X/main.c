#include "my_lib.h"

void main(void)
{
//Init port
    TRISB = 0;				//PORTB output
    PORTB = 0; 				//Reset PORTB
    glcd_Init(1);
    display_titre();
    display_auteur();
    PWM1_Init(1000); //min 490 Hz - max 125000Hz
    PWM1_setDC(50); //0-100 dutyclycle
    initMyPIC18F();
    
    while(1)
    {
        display_menu();
        ADCON0bits.GO_DONE = 1;
        display_7segment();
        
    }
}
