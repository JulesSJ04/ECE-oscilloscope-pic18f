#include "my_lib.h"

void main(void)
{
    frequence = 10000;
    dutycycle = 75;
//Init port
    //TRISB = 0;				//PORTB output
    //PORTB = 0; 
    //Reset PORTB
    initMyPIC18F();
    glcd_Init(1);
    glcd_Image();
    __delay_ms(2000);
    display_titre();
    display_auteur();
    if(frequence < 490)
    {
        frequence = 490;
    }
    if(frequence > 62500)
    {
        frequence = 62500;
    }
    if(dutycycle < 0)
    {
        dutycycle = 0;
    }
    if(dutycycle > 100)
    {
        dutycycle = 100;
    }
    PWM1_Init(frequence); //min 490 Hz - max 62500Hz
    PWM1_setDC(dutycycle); //0-100 dutyclycle
    need_osc_refresh = 1;
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

