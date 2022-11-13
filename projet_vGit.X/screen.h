#include <xc.h>
#include "KS0108.h"

void display_titre(void);
void display_auteur(void);
void display_menu(void);
void display_line(int x, int y, int final_x,int final_y, int color);
void display_oscillo(int ADC_value);
void draw_line(int x1,int y1,int x2,int y2, int color);
long map(long x, long in_min, long in_max, long out_min, long out_max);
void display_rectangle(void);
