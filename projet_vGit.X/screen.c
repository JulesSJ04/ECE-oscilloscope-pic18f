#include "my_lib.h"

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
    unsigned char string1[16] = {'C','h','o','i','s','i','r',' ','u','n',' ', 'm', 'o', 'd', 'e', '\0'};
    unsigned char string2[15] = {'1','.','O','s','c','i','l','l','o','s','c','o','p','e','\0'};
    unsigned char string3[16] = {'2','.','R','e','c','t','a','n','g','u','l','a','i','r','e','\0'};
    unsigned char string4[2] = {'1','\0'};
    unsigned char string5[2] = {'2','\0'};
    
    glcd_SetCursor(2,0);				//place le curseur
	glcd_WriteString(string1,f8X8,1);	//ecrit 
	glcd_SetCursor(2,2);				//place le curseur
	glcd_WriteString(string2,f8X8,1);	//ecrit
	glcd_SetCursor(2,3);				//place le curseur
	glcd_WriteString(string3,f8X8,1);	//ecrit 
    glcd_SetCursor(2,3);				//place le curseur
	glcd_WriteString(string3,f8X8,1);
	//__delay_ms(2000);					//attend 2s
	//glcd_FillScreen(0);					//efface l'ecran	
	__delay_us(1);
}



