//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

/*! \mainpage Innovative Power Doxygen documentatie
 *
 * Deze documentatie is automatisch gegenereerd met behulp van Doxygen.
 * 
 * Kies een bestand uit de lijst hier links naast om o.a. de dependency graph, macro's, functies en variabelen van het betreffende bestand te zien.
 *
 */

#include "main.h"


int main(void)
{
	///Low level initialization
	SystemInit(); // System speed to 168MHz
	KEYS_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen
	UB_VGA_FillScreen(VGA_COL_BLACK);


	int key = key_1, prevKey = key_0;
	while(1)
	{

		while(!(key = KEYS_read()));
		if(key != prevKey)
		{
			UB_VGA_FillScreen(VGA_COL_BLACK);
			switch(key)
			{
			case key_1:
				SetFont(arial16p,bold);
				DrawBackGround(&niceLice,tiled);
				SetTextColor(VGA_COL_BLUE);
				DrawString("Asian Experience", 90,90);
				DrawString("50 dollahrs",125,110);
				DrawBMP(100,130,&wc,VGA_COL_BROWN);
				break;
			case key_2:
				SetFont(arial16p,cursive);
				SetTextColor(VGA_COL_GREEN);
				DrawString("Axel is een humongus faggit", 50,100);
				DrawBMP(100,130,&wc,VGA_COL_BROWN);
				break;
			case key_3:
				SetLineColor(VGA_COL_RED);
				SetFillColor(VGA_COL_YELLOW);
				DrawTriangle(0,0,320,0,160,240,1);

				break;
			case key_4:
				DrawBackGround(&bluntBoy,tiled);
				DrawBMP(0,0,&beer,0);
				DrawBMP(100,0,&exitSign,0);
				DrawBMP(0,100,&note,VGA_COL_WHITE);
				DrawBMP(100,100,&wc,0);
				break;
			default:
				DrawBackGround(&bluntBoy,tiled);
				int i;
				for(i = 0; i < 2000; i++)
					DrawBMP(rand() % 320, rand() %240,&bluntBoy,0);

			}
		}
		prevKey = key;

	}
}

