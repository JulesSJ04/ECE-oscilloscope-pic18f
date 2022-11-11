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
    need_osc_refresh = 1;
    current_oscillo_mode = 0;
    need_menu_refresh = 1;
    PORTAbits.RA5 = 1;
    currently_in_oscillo = 0;
    currently_in_menu = 1;
    menu_selector = 1;
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
            display_oscillo((int)((global_ADC_value/4) - 64)*(-1));
        }
        display_7segment();
    }
}

