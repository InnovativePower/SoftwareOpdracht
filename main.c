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

	SetLineThickness(5);
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
				SetLineColor(VGA_COL_RED);
				SetFillColor(VGA_COL_WHITE);
				DrawEllipse(150,100,100,30,1);
				DrawString("Asian Experience", 90,90);
				DrawString("50 dollahrs",125,110);
				DrawBMP(100,130,&wc,VGA_COL_WHITE);
				//DrawCircle(100,100,40,1);
				break;
			case key_2:
				SetFont(arial16p,cursive);
				SetTextColor(VGA_COL_GREEN);
				DrawString("Axel is een humongus faggit", 50,100);
				DrawBMP(100,130,&wc,VGA_COL_BROWN);
				break;
			case key_3:
				SetLineColor(VGA_COL_YELLOW);
				SetFillColor(VGA_COL_YELLOW);
				SetFont(arial16p,bold)
				SetTextColor(VGA_COL_CYAN);

				DrawRectangle(20,100,120,10,1);
				DrawRectangle(180,100,120,10,1);
				DrawRectangle(20,210,120,10,1);
                DrawRectangle(180,210,120,10,1);

                DrawString("Music",20,20);
                DrawString("WC",180,20);
                DrawString("Coins",20,140);
                DrawString("Exit",180,140);

                DrawLine(40,70,100,70); //Music arrow
                DrawLine(40,70,80,50);
                DrawLine(40,70,80,90);

                DrawLine(220,70,280,70); //WC arrow
                DrawLine(260,50,280,70);
                DrawLine(260,90,280,70);


                DrawLine(40,180,100,180); //coin arrow
                DrawLine(40,180,60,160);
                DrawLine(40,180,60,200);


                DrawLine(220,180,280,180); //Exit arrow
                DrawLine(260,200,280,180);
                DrawLine(260,160,280,180);
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

