#include "my_lib.h"

int double_edge; //Variable permettant de vérifier si le bouton n'est pris qu'une fois en compte
//CAR RB6 et RB7 emettent une interruption sur front montant et front descendant
int double_edgeRB7;

void initMyPIC18F(void)
{
    // PORTs initialization
    TRISD = 0b00000000; // set PORTD as OUTPUT
    PORTD = 0b00000000; //clear port D
    
    ADCON1 = 0b00001010; //RA0 en mode analog, resultat justifie a gauche et tension de ref VDD
    ADCON0 = 0b00010001; //choix du channel sur RA0   

    TRISA = 0b11110000;
    PORTA = 0b00000000;
    
    //Mode inputs
    TRISB = 0b11000000;
    PORTB = 0b00000000;
    
    TRISE = 0b00000100;
    PORTE = 0b00000000;
    
    INTCONbits.GIE = 1;
    RCONbits.IPEN = 1;
    PIE1bits.ADIE = 1;
    IPR1bits.ADIP = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1;
    INTCON2bits.RBIP = 1; //Haute priorité
    //RCONbits.IPEN = 0;
    //INTCON2bits. = 1;
}

void __interrupt(low_priority) irq_handle_low()
{
    if(PIR1bits.ADIF == 1)
    {
        PIR1bits.ADIF = 0;
        global_ADC_value = ADRESH;
        calcul_7segment(global_ADC_value);
    }
    return;
}

void __interrupt(high_priority) irq_handle_high()
{
    
    if(INTCONbits.RBIF == 1) 
    {
        //PIE1bits.ADIE = 0;
        __delay_ms(25);
        //INTCONbits.GIE = 0;
        //ADCON0bits.GO_DONE = 0;
        INTCONbits.RBIF = 0;
        if(PORTBbits.RB6 == 1)
        {
            if(double_edge == 0) 
            {
                if(currently_in_menu==1 && menu_selector==0)
                {
                    double_edge++;
                    menu_selector = 1; //On inverse l'état
                    return;
                }
                else if(currently_in_menu==1 && menu_selector==1)
                {           
                    double_edge++;
                    menu_selector = 0; //On inverse l'état
                    return;
                }
                else if(currently_in_oscillo == 1 && current_oscillo_mode == 0 && trigger_was_param == 0)
                {
                    double_edge++;
                    have_to_FillScreen = 1; //Besoin de refraichir l'ecran
                    current_oscillo_mode = 1; //On inverse l'état
                    trigger_was_param = 0; //besoin de paramétrer l'oscillo
                    return;
                }
                else if(currently_in_oscillo == 1 && current_oscillo_mode == 1 && trigger_was_param == 1)
                {
                    double_edge++;
                    have_to_FillScreen = 1;
                    current_oscillo_mode = 0; //On inverse l'état
                    return;
                }
                else if(currently_in_oscillo == 1 && current_oscillo_mode == 1 && trigger_was_param == 0) //Si besoin de parametrer le trigger
                {
                    double_edge++;
                    TRIGGER_VAL = global_screen_ADC_value; //On set le trigger au niveau actuel
                    have_to_FillScreen = 1;
                    trigger_was_param = 1; //On indique que le trigger à été param
                    return;
                }
            }
            else
            {
                double_edge = 0;
                //INTCONbits.GIE = 1;
                return;
            }                 
        }
        else if(PORTBbits.RB7 == 1)
        {
            if(double_edgeRB7 == 0)
            {
                if(currently_in_menu == 1)
                {
                    if(menu_selector == 0)
                    {
                        double_edgeRB7++;
                        currently_in_menu = 0; //On sort du menu
                        currently_in_oscillo = 1; //On passe à l'oscillos
                        need_osc_refresh = 1; //On refraichit l'oscillo
                        current_oscillo_mode = 0; //Premier mode de l'oscillo
                        have_to_FillScreen = 1; //Besoin de rafraichir l'écran
                        return;
                    }
                }
                else if(currently_in_oscillo == 1)
                {
                    double_edgeRB7++;
                    currently_in_menu = 1; //On passe au menu
                    currently_in_oscillo = 0; //On sort de l'oscillos
                    need_menu_refresh = 1; //Besoin de refraichir le menu
                    have_to_FillScreen = 1; //Besoin de rafraichir l'écran
                    return;
                }
            }
            else
            {
                double_edgeRB7 = 0;
                return;
            }   
        }
        else
        {
            return;         
        }      
    } 
    //INTCONbits.RBIE = 1;
    return;
}

