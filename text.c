#include "text.h"
FONT fArial16p={{&arial_16ptFontInfo,&arialBold_16ptFontInfo,&arialCursive_16ptFontInfo}};

 void SetTextColor(char color)
 {
	 textColor = color;
 }
 void SetFont(FONT_NAME font, FONT_STYLE style)
 {
	 switch(font)
	 {
	 case arial16p:
		 currentFontInfo = fArial16p.styles[style];
		 break;

	 }
 }

int DrawChar(char character,int x, int y)
{
	const char* fontBitmap = currentFontInfo->p_character_bitmaps;
	const FONT_CHAR_INFO* fontDescriptor = currentFontInfo->p_character_descriptor;

	int descriptorOffset = character - currentFontInfo->start_char;

	int templateOffset = fontDescriptor[descriptorOffset].offset;
	int charWidth = fontDescriptor[descriptorOffset].width;

	int charHeight = currentFontInfo->height;

	for(int i = 0; i < charHeight; i++)
	{
		for(int j = 0; j < charWidth; j++)
		{
				char currentByte = fontBitmap[templateOffset+i*charWidth + j ];
				for(int k = 0; k < 8; k++)
				{
					if((currentByte & 1<< k) != 0)
						DrawPixel(x+8-k +j*8,y+i,textColor);
				}
		}

	}
	return charWidth*8;
}
void DrawString(char* string, int x, int y)
{
    char c = string[0];
    int stringIndex = 0;
    int spacing = 0;
    while(c != '\0')
    {
    	if(c != ' ')
    		spacing += DrawChar(c, x+ spacing,y);
    	else
    	{
    		spacing += 10;
    	}
    	stringIndex ++;
        c = string[stringIndex];
    }
}
