#define _XTAL_FREQ 8000000 

#include <xc.h>
#include <math.h>
#include "KS0108.h"
#include "screen.h"
#include "rectangle.h"
#include "Interrupt.h"
#include "7segment.h"
#include "utility.h"


#pragma config FOSC = HS // Oscillator Selection bits (XT oscillator)
#pragma config WDT = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit 
#pragma config MCLRE = ON
#pragma config CPUDIV = OSC1_PLL2
#pragma config PBADEN = OFF
//#pragma CONFIG DEBUG=OFF

int TRIGGER_VAL;

//Menu booleans
int currently_in_menu;
int menu_selector; //1, 2
int need_menu_refresh;

//Oscilloscope booleans
int current_oscillo_mode;
int currently_in_oscillo;
int currently_in_rectangle;
int need_osc_refresh;
int cpt;
int trigger_was_param;

int have_to_FillScreen;

int global_ADC_value;
int global_screen_ADC_value;
   
//7 seg values
int first_digit;
int second_digit;
int third_digit;
int fourth_digit;

//rectangular signal params
long frequence;
int dutycycle;
int cpt_rectangle;
int cpt_screen_rectangle;
int cpt_prec_rectangle;
int value_prec_rectangle;
int current_rectangle_mode;


int cpt_prec;
int adc_prec;

int trigger_level;

int dans_le_mode_trigger;

/*
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config DEBUG = OFF
#pragma config MCLRE = ON
#pragma config CPUDIV = OSC1_PLL2
#pragma config PBADEN = OFF

 
#pragma config FOSC = HS 		//oscillator HS
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF 		//Disable watchDog
#pragma config LVP = OFF 		//Disable low voltage programmig
#pragma config MCLRE = ON
#pragma config CPUDIV = OSC1_PLL2
#pragma config PBADEN = OFF
*/

//#pragma config DEBUG = ON		//Debug ON

