#include "middle.h"
#include "math.h"
void DrawCircle(int x, int y, int radius, int isFilled)
{
    int i,j;
    for(i = 0; i < radius*2; i++)
    {
        for(j = 0; j < radius*2; j++)
        {
            if(ceil(sqrt(pow(radius-j,2) + pow(radius-i,2))) == radius-1)
                DrawPixel(x+ i,y+ j, 'w');
        }

    }


}

// Vars x and y define the top left corner of the rectangle
void DrawRectangle(int x, int y, int width, int height, int isFilled)
{
    int i, j;

    for(i = x; i <= x+width; i++)
        {
            DrawPixel(i, y,'w');
            DrawPixel(i, y+height,'w');
        }

    for(j = y; j <= y+height; j++)
        {
            DrawPixel(x, j,'w');
            DrawPixel(x+width, j,'w');
        }
        if(isFilled = 1)
        {
                if(width >= 1 && height >= 1)
                {
                    DrawRectangle(x+1,y+1,width-1,height-1,1);
                }

        }
}

//Betere naam bedenken voor length
void DrawTriangle(int x, int y, int length)
{






}
