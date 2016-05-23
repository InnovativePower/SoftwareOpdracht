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
	UB_VGA_Screen_Init(); // Init VGA-Screen
	UB_VGA_FillScreen(VGA_COL_WHITE);
  	UB_VGA_SetPixel(10,10,10);
  	//UB_VGA_FillScreen(VGA_COL_BLACK);

	///Mid level initialization
	InitMiddle();
	SetLineColor(VGA_COL_BLUE);
	SetFillColor(VGA_COL_RED);





	UB_VGA_FillScreen(VGA_COL_BLACK);
	DrawCircle(50,100,30,1);

	SetFillColor(VGA_COL_GREEN);

	SetFillColor(VGA_COL_YELLOW);



	DrawEllipse(150,150,20,100,1);
	SetFillColor(VGA_COL_MAGENTA);
	DrawSimpleTriangle(100,100,40,1);
	SetLineColor(VGA_COL_GREEN);
	SetFillColor(VGA_COL_CYAN);
	DrawRectangle(200,50,100,100,1);
	DrawTriangle(80,50,100,120,180,200,1);

	SetFont(timesNewRoman8p,normal);
	SetTextColor(VGA_COL_GREEN);
	DrawString("Times new roman, 8 pt, normal!",100,20);

	SetFont(timesNewRoman8p,bold);
	SetTextColor(VGA_COL_ORANGE);
	DrawString("Times new roman, 8 pt, bold!",100,35);

	SetFont(timesNewRoman8p,cursive);
	SetTextColor(VGA_COL_YELLOW);
	DrawString("Times new roman, 8 pt, italic!",100,50);

	SetFont(arial16p,normal);
	SetTextColor(VGA_COL_BLUE);
    DrawString("Arial, 16 pt, normal!",100,100);

	SetFont(arial16p,bold);
	SetTextColor(VGA_COL_RED);
	DrawString("Arial, 16 pt, bold!",100,130);

	SetFont(arial16p,cursive);
	SetTextColor(VGA_COL_WHITE);
	DrawString("Arial, 16 pt, cursive!",100,160);
	while(1);
}

