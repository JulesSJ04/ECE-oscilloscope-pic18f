#include "my_lib.h"

void main(void)
{
    initMyPIC18F();
    global_variables_init();
    glcd_Init(1);
    glcd_Image();
    __delay_ms(2000);
    display_titre();
    display_auteur();
    PWM1_Init(); //min 490 Hz - max 62500Hz
    PWM1_setFreqDC(dutycycle, frequence); //0-100 dutyclycle
    //Initialisations variables globales
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
            currently_in_rectangle = 0;
            
            display_menu();
        }
        else if(currently_in_oscillo == 1)
        {
            currently_in_menu = 0;
            currently_in_rectangle = 0;
            //need_osc_refresh = 1;
            global_screen_ADC_value = (int)((global_ADC_value/4) - 62)*(-1); //Récupère le niveau actuel du screen
            display_oscillo(global_screen_ADC_value);
        }
         else if(currently_in_rectangle == 1)
        {
            currently_in_menu = 0;
            currently_in_oscillo = 0;
            display_rectangle();
        }
        display_7segment();
    }
}

