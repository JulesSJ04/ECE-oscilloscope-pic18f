#define _XTAL_FREQ 8000000 

#include <xc.h>
#include "KS0108.h"
#include "screen.h"
#include "rectangle.h"
#include "Interrupt.h"
#include "7segment.h"


#pragma config FOSC = HS // Oscillator Selection bits (XT oscillator)
#pragma config WDT = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit 
#pragma config MCLRE = ON
#pragma config CPUDIV = OSC1_PLL2
#pragma config PBADEN = OFF
    
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

