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

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include "middle.h"


int main(void)
{
	///Low level initialization
	SystemInit(); // System speed to 168MHz
	UB_VGA_Screen_Init(); // Init VGA-Screen
	UB_VGA_FillScreen(VGA_COL_BLACK);
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
	while(1);
}

