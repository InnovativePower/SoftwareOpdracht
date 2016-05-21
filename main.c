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

	//  uint32_t n;
	fillColor = VGA_COL_RED;
	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_BLACK);
  	  UB_VGA_SetPixel(10,10,10);

  		UB_VGA_FillScreen(VGA_COL_BLACK);
	//	DrawCircle(100,100,50,VGA_COL_RED,1);
	//	DrawCircle(100,100,40,VGA_COL_WHITE,1);
	//	DrawCircle(100,100,30,VGA_COL_RED,1);
	//	DrawCircle(100,100,20,VGA_COL_WHITE,1);
	//	DrawCircle(100,100,10,VGA_COL_RED,1);


		DrawRectangle(180,97,100,6,VGA_COL_BROWN,1);
		DrawRectangle(180,150,100,6,VGA_COL_BLUE,0);
		DrawEllipse(200,200,30,40,VGA_COL_BLUE,0);
		DrawEllipse(250,200,40,30,VGA_COL_BLUE,1);
	while(1);
}

