#include "my_lib.h"

int double_edge = 0; //Variable permettant de vérifier si le bouton n'est pris qu'une fois en compte
//CAR RB6 et RB7 emettent une interruption sur front montant et front descendant

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
    PORTB = 0x00;
    
    INTCONbits.GIE = 1;
    PIE1bits.ADIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1;
    //INTCON2bits. = 1;
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
            if(double_edge == 0) 
            {
                if(currently_in_menu==1 && menu_selector==0)
                {
                    menu_selector = 1; //On inverse l'état
                    glcd_SetCursor(0,0);
                    glcd_FillScreen(0); //On efface l'ecran 
                    __delay_us(1);
                    display_menu(); //Affiche le curseur au bon endroit
                }
                if(currently_in_menu==1 && menu_selector==1)
                {
                    menu_selector = 0; //On inverse l'état
                    glcd_SetCursor(0,0);
                    glcd_FillScreen(0); //On efface l'ecran 
                    __delay_us(1);
                    display_menu(); //Affiche le curseur au bon endroit
                }
                double_edge++;
            }
            else
                double_edge = 0;
            
        }
        if(PORTBbits.RB7 == 1)
        {
            //Action
        }
        else
            return;
    }  
    return;
}

