#include "my_lib.h"

void display_line(int x, int y, int final_x,int final_y, int color)
{
    if(x==final_x)
    {  
            for(int i=y;i<final_y;i++)
            {
                glcd_PlotPixel(x,i,color);
            }
    }
    if(y==final_y)
    {        
        for(int i=x;i<final_x;i++)
           {
               glcd_PlotPixel(i,y,color);
           } 
    }
}

void draw_line(int x1,int y1,int x2,int y2, int color)
{
    // Iterators, counters required by algorithm
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
    // Calculate line deltas
    dx = x2 - x1;
    dy = y2 - y1;
    // Create a positive copy of deltas (makes iterating easier)
    dx1 = fabs(dx);
    dy1 = fabs(dy);
    // Calculate error intervals for both axis
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;
    // The line is X-axis dominant
    if (dy1 <= dx1) {
        // Line is drawn left to right
        if (dx >= 0) {
            x = x1; y = y1; xe = x2;
        } else { // Line is drawn right to left (swap ends)
            x = x2; y = y2; xe = x1;
        }
        glcd_PlotPixel(x,y,color); // Draw first pixel
        glcd_PlotPixel(x-1,y,color);
        glcd_PlotPixel(x+1,y,color);
        glcd_PlotPixel(x,y-1,color);
        glcd_PlotPixel(x,y+1,color);
        glcd_PlotPixel(x-1,y-1,color);
        glcd_PlotPixel(x-1,y+1,color);
        glcd_PlotPixel(x+1,y-1,color);
        glcd_PlotPixel(x+1,y+1,color);
        // Rasterize the line
        for (i = 0; x < xe; i++) {
            x = x + 1;
            // Deal with octants...
            if (px < 0) {
                px = px + 2 * dy1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            glcd_PlotPixel(x,y,color);
            glcd_PlotPixel(x-1,y,color);
            glcd_PlotPixel(x+1,y,color);
            glcd_PlotPixel(x,y-1,color);
            glcd_PlotPixel(x,y+1,color);
            glcd_PlotPixel(x-1,y-1,color);
            glcd_PlotPixel(x-1,y+1,color);
            glcd_PlotPixel(x+1,y-1,color);
            glcd_PlotPixel(x+1,y+1,color);
        }
    } else { // The line is Y-axis dominant
        // Line is drawn bottom to top
        if (dy >= 0) {
            x = x1; y = y1; ye = y2;
        } else { // Line is drawn top to bottom
            x = x2; y = y2; ye = y1;
        }
        glcd_PlotPixel(x,y,color); // Draw first pixel
        glcd_PlotPixel(x-1,y,color);
        glcd_PlotPixel(x+1,y,color);
        glcd_PlotPixel(x,y-1,color);
        glcd_PlotPixel(x,y+1,color);
        glcd_PlotPixel(x-1,y-1,color);
        glcd_PlotPixel(x-1,y+1,color);
        glcd_PlotPixel(x+1,y-1,color);
        glcd_PlotPixel(x+1,y+1,color);
        // Rasterize the line
        for (i = 0; y < ye; i++) {
            y = y + 1;
            // Deal with octants...
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            glcd_PlotPixel(x,y,color);
            glcd_PlotPixel(x-1,y,color);
            glcd_PlotPixel(x+1,y,color);
            glcd_PlotPixel(x,y-1,color);
            glcd_PlotPixel(x,y+1,color);
            glcd_PlotPixel(x-1,y-1,color);
            glcd_PlotPixel(x-1,y+1,color);
            glcd_PlotPixel(x+1,y-1,color);
            glcd_PlotPixel(x+1,y+1,color);
        }
    }
}

void display_titre(void)
{
    unsigned char string1[7] = { 'P', 'r', 'o', 'j', 'e', 't', '\0' };
    unsigned char string2[6] = { 'M', 'C', 'U', ' ', ':', '\0' };
	unsigned char string3[10] = {'E', 'a', 's', 'y', 'S', 'C', 'O', 'P', 'E', '\0'};
	
	//GLCD ecran d'acceuil pendant 2s
    //NE PAS UTILISER 40 en POSX
	glcd_FillScreen(0);					//efface l'ecran
	glcd_SetCursor(18,2);				//place le curseur
	glcd_WriteString(string1,f8X8,1);	//ecrit 
	glcd_SetCursor(78,2);				//place le curseur
	glcd_WriteString(string2,f8X8,1);	//ecrit
	glcd_SetCursor(26,5);				//place le curseur
	glcd_WriteString(string3,f8X8,1);	//ecrit 
	__delay_ms(2000);					//attend 2s
	glcd_FillScreen(0);					//efface l'ecran	
	__delay_us(1);
}

void display_auteur(void)
{
	unsigned char string1[3] = { 'b', 'y', '\0' };
	unsigned char string2[5] = {'E', 'r', 'i', 'c', '\0'};
    unsigned char string3[2] = { '&', '\0' };
	unsigned char string4[8] = { 'Q', 'u', 'e', 'n', 't', 'i', 'n', '\0'};
	unsigned char string5[6] = { 'J', 'u', 'l', 'e', 's', '\0'};

	
	//GLCD ecran d'acceuil pendant 2s
    //NE PAS UTILISER 40 en POSX
	//glcd_FillScreen(0);					//efface l'ecran
	glcd_SetCursor(52,0);				//place le curseur
	glcd_WriteString(string1,f8X8,1);	//ecrit 
	glcd_SetCursor(45,2);				//place le curseur
	glcd_WriteString(string2,f8X8,1);	//ecrit
	glcd_SetCursor(54,3);				//place le curseur
	glcd_WriteString(string3,f8X8,1);	//ecrit 
    glcd_SetCursor(35,4);				//place le curseur
	glcd_WriteString(string4,f8X8,1);	//ecrit
	glcd_SetCursor(54,5);				//place le curseur
	glcd_WriteString(string3,f8X8,1);	//ecrit 
	glcd_SetCursor(41,6);				//place le curseur
	glcd_WriteString(string5,f8X8,1);	//ecrit 
	__delay_ms(2000);					//attend 2s
	glcd_FillScreen(0);					//efface l'ecran	
	__delay_us(1);
}

void display_menu(void)
{
    /*if(have_to_FillScreen == 1)
    {
        have_to_FillScreen = 0;
        glcd_FillScreen(0);					//efface l'ecran
    }*/

    //currently_in_menu = 1;
    //currently_in_oscillo = 0;
    if(need_menu_refresh == 1)
    {
        unsigned char string1[16] = {'C','h','o','i','s','i','r',' ','u','n',' ', 'm', 'o', 'd', 'e', '\0'};
        unsigned char string2[15] = {'1','.','O','s','c','i','l','l','o','s','c','o','p','e','\0'};
        unsigned char string3[16] = {'2','.','R','e','c','t','a','n','g','u','l','a','i','r','e','\0'};
        unsigned char string4[2] = {'1','\0'};
        unsigned char string5[2] = {'2','\0'};

        //Ecriture du menu
        glcd_SetCursor(2,0);				//place le curseur
        glcd_WriteString(string1,f8X8,1);	//ecrit 
        glcd_SetCursor(2,2);				//place le curseur
        glcd_WriteString(string2,f8X8,1);	//ecrit
        glcd_SetCursor(2,3);				//place le curseur
        glcd_WriteString(string3,f8X8,1);	//ecrit 
        glcd_SetCursor(2,3);				//place le curseur
        //Numéros
        glcd_SetCursor(42,5);
        glcd_WriteString(string4,f8X8,1);
        glcd_SetCursor(82,5);				//place le curseur
        glcd_WriteString(string5,f8X8,1);
        need_menu_refresh = 0;
    }
    
    //Where to display our cursor
    if(menu_selector == 0)
    {
        display_line(82,52,90,52,0);
        display_line(42,52,50,52,1);
    }
    else if(menu_selector == 1)
    {
        display_line(82,52,90,52,1);
        display_line(42,52,50,52,0);
    } 
           
}

void display_oscillo(int ADC_value)
{
    /*if(have_to_FillScreen == 1)
    {
        have_to_FillScreen = 0;
        glcd_FillScreen(0);					//efface l'ecran
    }*/
    //Declaration des variables locales
    currently_in_menu = 0;
    currently_in_oscillo = 1;
    //int cpt;
    
    //if(need_osc_refresh == 1) //Se refresh seulement si changement
    //{
        //cpt = 0;
        //need_osc_refresh = 0;
        unsigned char string1[2] = {'1','\0'};
        unsigned char string2[2] = {'2','\0'};
        unsigned char string3[2] = {'E','\0'};
        unsigned char string4[2] = {'|','\0'};
        //Dessin des barres du mode
        //Ligne verticale
        for(int i = 0;i<8;i++)
        {
            glcd_SetCursor(15,i);
            glcd_WriteString(string4,f8X8,1);
        }
        display_line(0,17,17,17,1); //Ligne horizontale
        //current_oscillo_mode = 0;
        //Affichage du mode de l'oscilloscope
        if(current_oscillo_mode == 0)
        {
            glcd_SetCursor(2,1);
            glcd_WriteString(string1,f8X8,1);
        }
        else if(current_oscillo_mode == 1)
        {
            glcd_SetCursor(2,1);
            glcd_WriteString(string2,f8X8,1);
        }
        else
        {
            glcd_SetCursor(2,1);
            glcd_WriteString(string3,f8X8,1);
        }
    //}
    
    char digit4 = (char)(fourth_digit+48);
    char digit3 = (char)(third_digit+48);
    char digit2 = (char)(second_digit+48);
    char digit1 = (char)(first_digit+48);
 
    unsigned char string_fourth_digit[3] = {digit4,'.','\0'};
    unsigned char string_third_digit[2] = {digit3,'\0'};
    unsigned char string_second_digit[2] = {digit2,'\0'};
    unsigned char string_first_digit[2] = {digit1,'\0'};
    
    glcd_SetCursor(2,3);
    glcd_WriteString(string_fourth_digit,f8X8,1);
    glcd_SetCursor(2,4);
    glcd_WriteString(string_third_digit,f8X8,1);
    glcd_SetCursor(2,5);
    glcd_WriteString(string_second_digit,f8X8,1);
    glcd_SetCursor(2,6);
    glcd_WriteString(string_first_digit,f8X8,1);
    
    if(current_oscillo_mode == 0)
    {
        if(cpt < 99)
        {
            display_line(29+cpt,0,29+cpt,64,0);
            glcd_PlotPixel(cpt+28,ADC_value,1);
            draw_line(28+cpt_prec,adc_prec,28+cpt,ADC_value,1);
            cpt_prec = cpt;
            adc_prec = ADC_value;
            ++cpt;
        }
        else if(cpt >= 99)
        {
            cpt = 0;
            display_line(27,0,27,64,0);
            display_line(28,0,28,64,0);
            display_line(29+cpt,0,29+cpt,64,0);
            glcd_PlotPixel(cpt+28,ADC_value,1);
            cpt_prec = cpt;
            adc_prec = ADC_value;
            cpt++;
        }
    }
    else if(current_oscillo_mode == 1)
    {
        //float trigger = trigger_level / 64
        if(trigger_was_param == 0) //Si on a pas encore paramétré l'ADC, on affiche une ligne à l'endroit du trigger
        {
            unsigned char string_rb[7] = {'R','B','6','=','O','K','\0'};
            if(ADC_value > 30)
            {
                glcd_SetCursor(50,1);
                glcd_WriteString(string_rb,f8X8,1);
            }
            else if (ADC_value <= 30)
            {
                glcd_SetCursor(50,7);
                glcd_WriteString(string_rb,f8X8,1);
            }
            
            display_line(28,ADC_value,127,ADC_value,1);
            have_to_FillScreen = 1;
        }
        else if(trigger_was_param == 1) //Sinon on affiche courbe
        {
            //int mult = (int)(TRIGGER_VAL*12);
            //int val_y = (int)((mult-62)*(-1));
            display_line(28,TRIGGER_VAL,127,TRIGGER_VAL,1); //Ligne a franchir
            if(ADC_value <= TRIGGER_VAL)
            {
                if(cpt < 99)
                {
                    display_line(29+cpt,0,29+cpt,64,0);
                    glcd_PlotPixel(cpt+28,ADC_value,1);
                    draw_line(28+cpt_prec,adc_prec,28+cpt,ADC_value,1);
                    cpt_prec = cpt;
                    adc_prec = ADC_value;
                    ++cpt;
                }
                else if(cpt >= 99)
                {
                    cpt = 0;
                    display_line(27,0,27,64,0);
                    display_line(28,0,28,64,0);
                    display_line(29+cpt,0,29+cpt,64,0);
                    glcd_PlotPixel(cpt+28,ADC_value,1);
                    cpt_prec = cpt;
                    adc_prec = ADC_value;
                    cpt++;
                }
            }
        }
        
    }
    //Affichage de la value de l'ADC
    
    
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void display_rectangle(void)
{
    unsigned char string1[6] = { 'F', 'r', 'e', 'q', ':', '\0' };
    unsigned char string2[4] = { 'D', 'C', ':', '\0' };
    unsigned char mode1[7] = { 'M', 'o', 'd', 'e', ':', '1', '\0'};
    unsigned char mode2[7] = { 'M', 'o', 'd', 'e', ':', '2', '\0'};
    unsigned char hz[3] = { 'H', 'z', '\0'};
    unsigned char percent[2] = { '%', '\0'};

    glcd_SetCursor(7,6);				//place le curseur
    if(current_rectangle_mode == 0)
    {
        glcd_WriteString(mode1,f8X8,1);	//ecrit un ou deux 
    }
    else
    {
        glcd_WriteString(mode2,f8X8,1);	//ecrit un ou deux 
    }
	
    display_line(56,47,56,55,1);// ligne vertical
    display_line(57,47,57,55,1);// ligne vertical
    
    glcd_SetCursor(62,6);				//place le curseur
	glcd_WriteString(string2,f8X8,1);	//ecrit dc
    
    glcd_SetCursor(114,6);				//place le curseur
    glcd_WriteString(percent,f8X8,1);	//ecrit dc
    
    glcd_SetCursor(11,7);				//place le curseur
	glcd_WriteString(string1,f8X8,1);	//ecrit freq
    
    glcd_SetCursor(102,7);				//place le curseur
	glcd_WriteString(hz,f8X8,1);	//ecrit freq
    
    display_line(0,46,128,46,1);// ligne horizontal
    
    float freq = (float) frequence * 0.0001; 
    
    int freq_digit1 = (int) freq;
    freq -= (int) freq;
    freq *= 10;
    
    int freq_digit2 = (int) freq;
    freq -= (int) freq;
    freq *= 10;
    
    int freq_digit3 = (int) freq;
    freq -= (int) freq;
    freq *= 10;
    
    int freq_digit4 = (int) freq;
    freq -= (int) freq;
    freq *= 10;
    
    int freq_digit5 = (int) freq;
    
    float dc = (float) dutycycle * 0.01; 
    
    int dc_digit1 = (int) dc;
    dc -= (int) dc;
    dc *= 10;
    
    int dc_digit2 = (int) dc;
    dc -= (int) dc;
    dc *= 10;
    
    int dc_digit3 = (int) dc;
    
    char fchar_digit1 = (char)(freq_digit1+48);
    char fchar_digit2 = (char)(freq_digit2+48);
    char fchar_digit3 = (char)(freq_digit3+48);
    char fchar_digit4 = (char)(freq_digit4+48);
    char fchar_digit5 = (char)(freq_digit5+48);
    
    char dchar_digit1 = (char)(dc_digit1+48);
    char dchar_digit2 = (char)(dc_digit2+48);
    char dchar_digit3 = (char)(dc_digit3+48);
    
    unsigned char string_f_digit1[2] = {fchar_digit1,'\0'};
    unsigned char string_f_digit2[2] = {fchar_digit2,'\0'};
    unsigned char string_f_digit3[2] = {fchar_digit3,'\0'};
    unsigned char string_f_digit4[2] = {fchar_digit4,'\0'};
    unsigned char string_f_digit5[2] = {fchar_digit5,'\0'};
    
    unsigned char string_d_digit1[2] = {dchar_digit1,'\0'};
    unsigned char string_d_digit2[2] = {dchar_digit2,'\0'};
    unsigned char string_d_digit3[2] = {dchar_digit3,'\0'};
    
    glcd_SetCursor(86,6);
    glcd_WriteString(string_d_digit1,f8X8,1);
    glcd_SetCursor(95,6);
    glcd_WriteString(string_d_digit2,f8X8,1);
    glcd_SetCursor(104,6);
    glcd_WriteString(string_d_digit3,f8X8,1);
    
    glcd_SetCursor(51,7);
    glcd_WriteString(string_f_digit1,f8X8,1);
    glcd_SetCursor(60,7);
    glcd_WriteString(string_f_digit2,f8X8,1);
    glcd_SetCursor(74,7);
    glcd_WriteString(string_f_digit3,f8X8,1);
    glcd_SetCursor(83,7);
    glcd_WriteString(string_f_digit4,f8X8,1);
    glcd_SetCursor(92,7);
    glcd_WriteString(string_f_digit5,f8X8,1);
    
    int ratio = map(frequence, 490, 62500, 1, 50);
    int max = (int) (((float) 100) / ratio);
    int compteur = (int) (((float) dutycycle) /ratio); 
    
    display_line(cpt_screen_rectangle,0,cpt_screen_rectangle,45,0);
    if(cpt_rectangle < compteur)
    {
        glcd_PlotPixel(cpt_screen_rectangle,10,1);
        if(cpt_prec_rectangle != 126)
        {
            draw_line(cpt_prec_rectangle,value_prec_rectangle,cpt_screen_rectangle,10,1);
        }
        cpt_prec_rectangle = cpt_screen_rectangle;
        value_prec_rectangle = 10;
    }
    else
    {
        glcd_PlotPixel(cpt_screen_rectangle,35,1);
        if(cpt_prec_rectangle != 126)
        {
            draw_line(cpt_prec_rectangle,value_prec_rectangle,cpt_screen_rectangle,35,1);
        }
        cpt_prec_rectangle = cpt_screen_rectangle;
        value_prec_rectangle = 35;
    }
    if(cpt_rectangle < max)
    {
        cpt_rectangle++;
    }
    else
    {
        cpt_rectangle = 0;
    }
    if(cpt_screen_rectangle >= 126)
    {
        cpt_screen_rectangle = 0;
    }
    else
    {
        cpt_screen_rectangle++;
    }
}



