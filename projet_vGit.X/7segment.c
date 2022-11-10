#include "my_lib.h"

#define QUANTUM 0.0204919
#define ZERO 63
#define ONE 6
#define TWO 91
#define THREE 79
#define FOUR 102
#define FIVE 109
#define SIX 125
#define SEVEN 7
#define EIGHT 127
#define NINE 111
#define DELAY 3


void display_7segment(void)
{
    PORTD = global_FOUR;
    PORTAbits.RA3 = 1;
    __delay_ms(DELAY);
    PORTAbits.RA3 = 0;
    
    PORTD = global_ONE;
    //PORTD = 255;
    PORTAbits.RA0 = 1;
    __delay_ms(DELAY);
    PORTAbits.RA0 = 0;
    
    PORTD = global_TWO;
    PORTAbits.RA1 = 1;
    __delay_ms(DELAY);
    PORTAbits.RA1 = 0;
    
    PORTD = global_THREE;
    PORTAbits.RA2 = 1;
    __delay_ms(DELAY);
    PORTAbits.RA2 = 0;
}

int correspondance_7segment(int val)
{
    if(val == 0)
        return ZERO;
    else if(val == 1)
        return ONE;
    else if(val == 2)
        return TWO;
    else if(val == 3)
        return THREE;
    else if(val == 4)
        return FOUR;
    else if(val == 5)
        return FIVE;
    else if(val == 6)
        return SIX;
    else if(val == 7)
        return SEVEN;
    else if(val == 8)
        return EIGHT;
    else if(val == 9)
        return NINE;
    else
        return 0b11111111;
}

void calcul_7segment(int adresh)
{
    int first_digit;
    int second_digit;
    int third_digit;
    int fourth_digit;
    
    float voltage_value = adresh * QUANTUM;
    
    //Recupération dans chachune des digits de la valeur
    fourth_digit = (int)voltage_value; //Cast pour obtenir la première value
    voltage_value -= fourth_digit;
    voltage_value *= 10;
    
    third_digit = (int)voltage_value;
    voltage_value -= third_digit;
    voltage_value *= 10;
    
    second_digit = (int)voltage_value;
    voltage_value -= second_digit;
    voltage_value *= 10;
    
    first_digit = (int)voltage_value;
    
    global_ONE = correspondance_7segment(first_digit);
    global_TWO = correspondance_7segment(second_digit);
    global_THREE = correspondance_7segment(third_digit);
    global_FOUR = correspondance_7segment(fourth_digit) + 0b10000000;
}

