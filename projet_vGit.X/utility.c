#include "my_lib.h"


long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void global_variables_init(void)
{
    frequence = 490;
    dutycycle = 50;
    need_osc_refresh = 1;
    current_oscillo_mode = 0;
    need_menu_refresh = 1;
    PORTAbits.RA5 = 1;
    currently_in_oscillo = 0;
    currently_in_rectangle = 0;
    currently_in_menu = 1;
    current_rectangle_mode = 0;
    menu_selector = 0;
    trigger_was_param =0;
    cpt_screen_rectangle = 3;
    cpt_prec_rectangle = 2;
    value_prec_rectangle = 10;
    dans_le_mode_trigger = 0;
}



