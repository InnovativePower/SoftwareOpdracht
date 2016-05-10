#include "middle.h"
#include "math.h"
void DrawCircle(int x, int y, int radius, int isFilled)
{
    int i,j;
    for(i = 0; i < radius*2; i++)
    {
        for(j = 0; j < radius*2; j++)
        {
            if(sqrt(pow(radius-j,2) + pow(radius-i,2) < radius))
                DrawPixel(x+ i,y+ j, 1);
        }

    }
    if(isFilled == 0)
        DrawCircle(x,y,radius-1,1);


}
void DrawRectangle(int x, int y, int width, int height)
{



}
