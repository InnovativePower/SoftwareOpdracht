#include "middle.h"
#include <math.h>
#include "stm32_ub_vga_screen.h"
#define PI 3.14159

#define DEGREES_TO_RAD PI/180
void InitMiddle()
{
	lineColor = 0;
	fillColor = 0;
}

///Set the line color for shapes, this color stays the same until it is changed by calling this function with a different value
///This color applies to all shapes
void SetLineColor(char newColor)
{
	lineColor = newColor;
}

///Set the fill color for shapes, this color stays the same until it is changed by calling this function with a different value
///This color applies to all shapes
void SetFillColor(char newColor)
{
	fillColor = newColor;
}

///
void DrawPixel(int x, int y, char color)
{
	UB_VGA_SetPixel(x,y,color);
}

///Draw a circle according to the Bresenham's algoritm
void DrawCircle(int x, int y, int radius, int isFilled)
{

	int dx = 0, dy = radius;
	int dp = 1 - radius;
	do
	{
		if (dp < 0)
			dp = dp + 2 * (++dx) + 3;
		else
			dp = dp + 2 * (++dx) - 2 * (--dy) + 5;
		if(isFilled)
		{
			DrawLineCol(x + dx,y + dy,x - dx,y + dy,fillColor);
			DrawLineCol(x + dx,y - dy,x - dx,y - dy,fillColor);
			DrawLineCol(x + dy,y + dx,x - dy,y + dx,fillColor);
			DrawLineCol(x + dy,y - dx,x - dy,y - dx,fillColor);
		}
		DrawPixel(x + dx, y + dy, lineColor);     //For the 8 octants
		DrawPixel(x - dx, y + dy, lineColor);
		DrawPixel(x + dx, y - dy, lineColor);
		DrawPixel(x - dx, y - dy, lineColor);
		DrawPixel(x + dy, y + dx, lineColor);
		DrawPixel(x - dy, y + dx, lineColor);
		DrawPixel(x + dy, y - dx, lineColor);
		DrawPixel(x - dy, y - dx, lineColor);

	} while (dx < dy);
	if(isFilled)
		DrawLineCol(x-radius,y,x + radius,y,fillColor);
	DrawPixel(x-radius,y, lineColor);
	DrawPixel(x+radius,y, lineColor);
}


/// Variabels x and y define the top left corner of the rectangle
void DrawRectangle(int x, int y, int width, int height,int isFilled)
{
    int i, j;
    if(isFilled)
    {
		for(i = 0; i < width; i++)
		{
			for(j = 0; j < height; j++)
			{
				DrawPixel(x + i, y+ j, fillColor);
			}
		}
	}

	for(i = 0; i < width+1; i++)
	{
		DrawPixel(x + i, y, lineColor);
		DrawPixel(x + i, y+ height, lineColor);
	}
	for(j = 0; j < height+1; j++)
	{
		DrawPixel(x, y + j, lineColor);
		DrawPixel(x + width, y+ j, lineColor);
	}


}

///Draw line from "x1, y1" to "x2, y2" with specified color
void DrawLineCol(int x1, int y1, int x2, int y2, char color)
{

    float dx = x2 - x1;
    float dy = y2 - y1;
    float length = sqrt(dx*dx + dy*dy);
    int i;
    for(i = 0; i < length; i++)
    {

        DrawPixel(x1 + i*dx/length,y1 + i*dy/length,color);
    }
}

///Draw line from "x1, y1" to "x2, y2" with color defined by function SetColor
void DrawLine(int x1, int y1, int x2, int y2)
{
	DrawLineCol(x1,y1,x2,y2,lineColor);
}

/*!	Draw a triangle with sides of equal length.
 * 
 *	The triangle will be drawn with x and y as its center
 *
 * The distance between two point of a triangle with equal sides is equal to the distance from the center to one of the points
 *
 *
 */
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int isFilled)
{
	if(isFilled)
	{
		float dx1 = x2 - x1;
		float dy1 = y2 - y1;
		float dx2 = x3 - x2;
		float dy2 = y3 - y2;
		float dx3 = x1 - x3;
		float dy3 = y1 - y3;

		float length1 = sqrt(dx1*dx1 + dy1*dy1);
		float length2 = sqrt(dx2*dx2 + dy2*dy2);
		float length3 = sqrt(dx3*dx3 + dy3*dy3);

		char lineColorBuffer = lineColor;
		SetLineColor(fillColor);
		for(int i = 0; i < length1;i++)
		{
			float lineX = i*dx1/length1;
			float lineY = i*dy1/length1;
			DrawLine(x1 +lineX, y1 + lineY,x3 , y3);
		}
		for(int i = 0; i < length2;i++)
		{
			float lineX = i*dx2/length2;
			float lineY = i*dy2/length2;
			DrawLine(x2 +lineX, y2 + lineY,x1 , y1);
		}
		for(int i = 0; i < length3;i++)
		{
			float lineX = i*dx3/length3;
			float lineY = i*dy3/length3;
			DrawLine(x3 +lineX, y3 + lineY,x2 , y2);
		}
		SetLineColor(lineColorBuffer);
	}
	DrawLine(x1,y1,x2,y2);
	DrawLine(x2,y2,x3,y3);
	DrawLine(x3,y3,x1,y1);
}

///Draw triangle with specified side and bottom left corner on "x, y", user can specify wether or not the triangle should be filled.
void DrawSimpleTriangle(int x, int y, float sideLength, int isFilled)
{

	int x1 = x;
	int y1 = y - 0.5*sideLength;
	int x2 = x + 0.5*sideLength;
	int y2 = y + 0.5*sideLength;
	int x3 = x - 0.5*sideLength;
	int y3 = y + 0.5*sideLength;
	if(isFilled)
		{
			char lineColorBuffer = lineColor;
			SetLineColor(fillColor);
			for(int i = 0; i < sideLength; i++)
			{

				DrawLine(x3+i,y3,x1,y1);
			}
			SetLineColor(lineColorBuffer);
		}
	DrawLine(x1,y1,x2,y2);
	DrawLine(x2,y2,x3,y3);
	DrawLine(x3,y3,x1,y1);

}

///Draw ellipse with specified width and height. "x, y" specify the bottom left corner of an imaginary rectangle drawn around the ellipse. User can specify wether 
/// or not the shape should be filled
void DrawEllipse(int x, int y, int width, int height, int isFilled)
{
	float xRadius, yRadius, radius;
	if(width > height)
	{
		radius = width/2;
		xRadius = 1;
		yRadius = (float)height/(float)width;
	}
	else
	{
		radius = height/2;
		xRadius = (float)width/(float)height;
		yRadius = 1;
	}



	float dx = 0, dy = radius;
	int dp = 1 - radius;
	do
	{
		if (dp < 0)
			dp = dp + 2 * (++dx) + 3;
		else
			dp = dp + 2 * (++dx) - 2 * (--dy) + 5;
		float xScaledDx = xRadius*dx;
		float xScaledDy = xRadius*dy;
		float yScaledDx = yRadius*dx;
		float yScaledDy = yRadius*dy;
		if(isFilled)
		{
			DrawLineCol(x + xScaledDx,y + yScaledDy,x - xScaledDx,y + yScaledDy,fillColor);
			DrawLineCol(x + xScaledDx,y - yScaledDy,x - xScaledDx,y - yScaledDy,fillColor);
			DrawLineCol(x + xScaledDy,y + yScaledDx,x - xScaledDy,y + yScaledDx,fillColor);
			DrawLineCol(x + xScaledDy,y - yScaledDx,x - xScaledDy,y - yScaledDx,fillColor);
		}
		DrawPixel(x + xScaledDx, y + yScaledDy, lineColor);     //For the 8 octants
		DrawPixel(x - xScaledDx, y + yScaledDy, lineColor);
		DrawPixel(x + xScaledDx, y - yScaledDy, lineColor);
		DrawPixel(x - xScaledDx, y - yScaledDy, lineColor);
		DrawPixel(x + xScaledDy, y + yScaledDx, lineColor);
		DrawPixel(x - xScaledDy, y + yScaledDx, lineColor);
		DrawPixel(x + xScaledDy, y - yScaledDx, lineColor);
		DrawPixel(x - xScaledDy, y - yScaledDx, lineColor);

	} while (dx < dy);
	if(isFilled)
		DrawLineCol(x-width/2,y,x + width/2,y,fillColor);
	DrawPixel(x-width/2,y, lineColor);
	DrawPixel(x+width/2,y, lineColor);
}
