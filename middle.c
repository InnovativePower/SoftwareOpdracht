#include "middle.h"
#include "math.h"
#include "stm32_ub_vga_screen.h"
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
                if(ceil(sqrt(pow(radius-j,2) + pow(radius-i,2))) == radius-1)
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
                if(ceil(sqrt(pow(radius-j,2) + pow(radius-i,2))) <= radius-1)
                    DrawPixel(x+ i,y+ j, color);
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
//Betere naam bedenken voor length
void DrawTriangle(int x, int y, char color, int length)
{
    float offset = 0.5f * (float)length;
    int x1 = x;
    int y1 = y - offset;
    int x2 = x - offset;
    int y2 = y + offset;
    int x3 = x + offset;
    int y3 = y + offset;
    DrawLine(x1,y1,x2,y2,color);
    DrawLine(x2,y2,x3,y3,color);
    DrawLine(x3,y3,x1,y1,color);
}

void DrawEllipse(int x, int y, int height, int width, char color)
{
	int radius;
	
	//Stapgrootte in radialen, deze moet wsl nog gefinetuned worden
	int step = 2*Pi/200;

	//Center coordinaten
	int h = x + 0.5*width;
	int k = y + 0.5*height;
	
	//Bepalen in welke richting de ellipse moet worden ingedrukt
	if(height > width)
	{
		xFactor = 1;
		yFactor = width / height;
		radius = 0.5*width;
	} 
	else
	{
		xFactor = height / width;
		yFactor = 1;
		radius = 0.5*height;
	}
	
	//Pixel coordinaten berekenen
	for(i = 0; i < 2*Pi; i+=step)
	{
		int xPixel = h + xFactor*radius*sin(i);
		int yPixel = k + yFactor*radius*sin(i);
		DrawPixel(xPixel, yPixel, color);
	}
}
