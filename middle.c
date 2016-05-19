#include "middle.h"
#include <math.h>
#include "stm32_ub_vga_screen.h"
#define PI 3.14159
void DrawPixel(int x, int y, char color)
{
	UB_VGA_SetPixel(x,y,color);
}
void DrawCircle(int x, int y, int radius, char color, int isFilled)
{
    int i,j;
    if(isFilled == 0)
    {
        for(i = 0; i < radius*2; i++)
        {
            for(j = 0; j < radius*2; j++)
            {
            	float hDistance = radius-i;
            	float vDistance = radius-j;
                if(vDistance*vDistance + hDistance*hDistance == (radius-1)*(radius-1))
                    DrawPixel(x+ i,y+ j, color);
            }

        }
    }
    else
    {
        for(i = 0; i < radius*2; i++)
        {
            for(j = 0; j < radius*2; j++)
            {
            	float hDistance = radius-i;
            	float vDistance = radius-j;
            	if(ceil(vDistance*vDistance + hDistance*hDistance )<= (radius-1)*(radius-1))
                    DrawPixel(x+ i-radius,y+ j-radius, color);
            }

        }
    }

}

/*void DrawCircle2(int x, int y, int radius, char color)
{

    char** quarter = (char**)malloc(sizeof(char*)*radius+1);
    int i, j;
    for(i = 0; i < radius+1; i++)
    {
        quarter[i] = (char*)malloc(sizeof(char)*radius+1);
        for(j = 0; j < radius+1; j++)
        {
            quarter[i][j] = color;
        }
    }

    for(i = 0; i < (int)(0.5*3.1415926*radius + 0.5f); i ++)
    {

        int dx,dy;
        dx = (int)radius*cos((float)i/(float)radius);
        dy = (int)radius*sin((float)i/(float)radius);
      //  printf("%d %d\n",dx,dy);
        quarter[dx][dy] =color;
    }

    for(i = 0; i < radius; i++)
    {
        for(j = 0; j < radius; j++)
        {
            DrawPixel(x+i,y+j,quarter[i][j] );
            DrawPixel(x-i,y+j,quarter[i][j] );
            DrawPixel(x+i,y-j,quarter[i][j] );
            DrawPixel(x-i,y-j,quarter[i][j] );
        }
    }
}*/
// Vars x and y define the top left corner of the rectangle
void DrawRectangle(int x, int y, int width, int height, char color, int isFilled)
{
    int i, j;

    for(i = x; i <= x+width-1; i++)
	{
		DrawPixel(i, y,color);
		DrawPixel(i, y+height-1,color);
	}

    for(j = y; j <= y+height-1; j++)
	{
		DrawPixel(x, j,color);
		DrawPixel(x+width-1, j,color);
	}
	if(isFilled == 1)
	{
			if(width >= 1 && height >= 1)
			{
				DrawRectangle(x+1,y+1,width-1,height-1,color,1);
			}
	}
}
void DrawLine(int x1, int y1, int x2, int y2, char color)
{
    /*
    if( x2 > x1)
    {
        int xBuf = x1;
        x1 = x2;
        x2 = xBuf;
    }*/
 /*   if(y2 > y1)
    {
        int yBuf = y1;
        y1 = y2;
        y2 = yBuf;
    }*/
    float dx = x2 - x1;
    float dy = y2 - y1;
    float length = sqrt(dx*dx + dy*dy);
    int i;
    for(i = 0; i < length; i++)
    {

        DrawPixel(x1 + i*dx/length,y1 + i*dy/length,color);
    }
}
/*	Draw a triangle with sides of equal length
 *	The triangle will be drawn with x and y as its center
 *
 *
 */
void DrawTriangle(int x, int y, int sideLength,float angle, char color, int isFilled)
{
	/* The ratio of the length of a side and the radius of the circle the triangle resides in is the square root of 0.8
	 *
	 *
	 */
	float ratio = sqrt(0.8);
	int x1 = x + ratio*sideLength*cos(PI*(angle + 120)/180);
    int y1 = y + ratio*sideLength*sin(PI*(angle + 120)/180);
    int x2 = x + ratio*sideLength*cos(PI*(angle + 240)/180);
    int y2 = y + ratio*sideLength*sin(PI*(angle + 240)/180);
    int x3 = x + ratio*sideLength*cos(PI*(angle)/180);
    int y3 = y + ratio*sideLength*sin(PI*(angle)/180);
    DrawLine(x1,y1,x2,y2,color);
    DrawLine(x2,y2,x3,y3,color);
    DrawLine(x3,y3,x1,y1,color);
    if(isFilled && sideLength > 0)
    {
    	DrawTriangle(x,y,sideLength-1,angle,color,isFilled);
    }


}
