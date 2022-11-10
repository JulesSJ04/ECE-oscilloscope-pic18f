#include "my_lib.h"

void display_line(int x, int y, int final_x,int final_y, int color)
{
    if(x==final_x)
    {
        for(int j=x-1;j<=x+1;j++)
        {
            for(int i=y;i<final_y;i++)
            {
                glcd_PlotPixel(j,i,color);
            }
        }

    }
    if(y==final_y)
    {
        for(int j=y-1;j<=y+1;j++)
        {
            for(int i=x;i<final_x;i++)
            {
                glcd_PlotPixel(i,j,color);
            }
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
	__delay_ms(4000);					//attend 2s
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
    if(have_to_FillScreen == 1)
    {
        have_to_FillScreen = 0;
        glcd_FillScreen(0);					//efface l'ecran
    }
    
    
    currently_in_menu = 1;
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
    
    //Where to display our cursor
    if(currently_in_menu == 1 && menu_selector == 0)
    {
        display_line(42,52,50,52,1);
    }
    else if(currently_in_menu == 1 && menu_selector ==1)
    {
        display_line(82,52,90,52,1);
    } 
    else
        asm("NOP");
          
	//__delay_ms(2000);					//attend 2s
		
	//__delay_ms(1);
    
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
    int cpt;
    
    if(need_osc_refresh == 1) //Se refresh seulement si changement
    {
        cpt = 0;
        need_osc_refresh = 0;
        unsigned char string1[2] = {'1','\0'};
        unsigned char string2[2] = {'2','\0'};
        unsigned char string3[2] = {'E','\0'};
        //Dessin des barres du mode
        display_line(27,0,27,64,1); //Ligne verticale
        display_line(0,25,27,25,1); //Ligne verticale

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
    }
    
    //Affichage de la tension analogique
    unsigned char string_first_digit[3] = {'0','.' ,'\0'};
    unsigned char string_second_digit[2] = {'0','\0'};
    unsigned char string_third_digit[2] = {'0','\0'};
    unsigned char string_fourth_digit[2] = {'0','\0'};
    
    glcd_SetCursor(2,3);
    glcd_WriteString(string_first_digit,f8X8,1);
    glcd_SetCursor(2,4);
    glcd_WriteString(string_second_digit,f8X8,1);
    glcd_SetCursor(2,5);
    glcd_WriteString(string_third_digit,f8X8,1);
    glcd_SetCursor(2,6);
    glcd_WriteString(string_fourth_digit,f8X8,1);
    
    //Affichage de la value de l'ADC
    if(cpt < 99)
    {
        display_line(28+cpt,0,28+cpt,64,0);
        glcd_PlotPixel(cpt+27,ADC_value,1);
        ++cpt;
    }
    else if(cpt >= 99)
    {
        cpt = 0;
        display_line(28+cpt,0,28+cpt,64,0);
        glcd_PlotPixel(cpt+27,ADC_value,1);
        cpt++;
    }
    
}



