#include "stm32_ub_vga_screen.h"
#include "top.h"
#ifndef __STM32F4_UB_MAIN_H
#define __STM32F4_UB_MAIN_H


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
//#include "stm32_ub_vga_screen.h"


//--------------------------------------------------------------
#endif // __STM32F4_UB_MAIN_H


int main()
{
	SystemInit(); // System speed to 168MHz
	//  uint32_t n;


	UB_VGA_Screen_Init(); // Init VGA-Screen

	  UB_VGA_FillScreen(VGA_COL_BLACK);
	  UB_VGA_SetPixel(10,10,10);




	  while(1)
	  {
		  UB_VGA_FillScreen(VGA_COL_WHITE);
		  // put the code here
	  }
    while(1)
    {
    DrawCircle(100,100,10,VGA_COL_BLUE,1);
	    DrawRectangle(150,150,50,50,VGA_COL_RED,1);
	    DrawLine(100,100,130,80,VGA_COL_RED);
	    DrawTriangle(200,200,10,VGA_COL_BLUE);
    }
    return 0;
}
