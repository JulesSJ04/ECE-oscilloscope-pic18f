#include "my_lib.h"

void main(void)
{
//Init port
    //TRISB = 0;				//PORTB output
    //PORTB = 0; 
    //Reset PORTB
    initMyPIC18F();
    glcd_Init(1);
    //glcd_Image();
    display_titre();
    display_auteur();
    PWM1_Init(2000); //min 490 Hz - max 125000Hz
    PWM1_setDC(50); //0-100 dutyclycle
    need_osc_refresh = 0;
    current_oscillo_mode = 0;
    menu_selector = 0;
    PORTAbits.RA5 = 1;
    while(1)
    {
        //display_menu();
        ADCON0bits.GO_DONE = 1;
        display_oscillo((int)(global_ADC_value/4));
        display_7segment();
    }
}

