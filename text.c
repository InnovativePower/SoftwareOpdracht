#include "text.h"

void InitText()
{


}
void DrawChar(char character,int x, int y, Font* DrawFont, Style drawStyle)
{
	const char* styleTemplate = DrawFont->styles[currentStyle];
	int i,j;
	for(i = 0; i < styleTemplate[character]; i++)
	{
		for(j = 0; j <  styleTemplate[character; j++)
		{
			DrawPixel(x+i,y+j,styleTemplate[i][j]);
		}
	}
}
void DrawText(char* string, int x, int y)
{
    char c = string[0];
    int stringIndex = 0;
    while(c != '\0')
    {
        DrawChar(c, x+ stringIndex*fontSize,y, currentFont, currentStyle);
        stringIndex ++;
        c = string[stringIndex];
    }
}
