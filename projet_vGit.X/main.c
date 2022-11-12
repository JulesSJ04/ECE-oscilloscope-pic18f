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
    need_menu_refresh = 1;
    PORTAbits.RA5 = 1;
    currently_in_oscillo = 0;
    currently_in_menu = 1;
    menu_selector = 0;
    trigger_was_param =0;
    while(1)
    {
        ADCON0bits.GO_DONE = 1;
        //display_menu();
        if(have_to_FillScreen == 1)
        {
            have_to_FillScreen = 0;
            glcd_FillScreen(0);					//efface l'ecran
        }
        if(currently_in_menu == 1)
        {
            currently_in_oscillo = 0;
            display_menu();
        }
        else if(currently_in_oscillo == 1)
        {
            currently_in_menu = 0;
            global_screen_ADC_value = (int)((global_ADC_value/4) - 62)*(-1); //Récupère le niveau actuel du screen
            display_oscillo(global_screen_ADC_value);
        }
        display_7segment();
    }
}

