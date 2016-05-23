#include "text.h"
FONT fArial16p={{&arial_16ptFontInfo,&arialBold_16ptFontInfo,&arialCursive_16ptFontInfo}};
FONT fTimesNewRoman8p = {{&timesNewRoman_8ptFontInfo,&timesNewRomanBold_8ptFontInfo,&timesNewRomanCursive_8ptFontInfo}};
///Set the text color, this color stays the same until it is changed by calling this function with a different value
 void SetTextColor(char color)
 {
	 textColor = color;
 }
 
 ///Set the text font and style, this font stays and style the same until it is changed by calling this function with a different font name and style
 void SetFont(FONT_NAME font, FONT_STYLE style)
 {
	 switch(font)
	 {
	 case arial16p:
		 currentFontInfo = fArial16p.styles[style];
		 break;
	 case timesNewRoman8p:
		 currentFontInfo = fTimesNewRoman8p.styles[style];
		 break;
	 }
 }

 ///Draw a character on coordinate "x, y", these characters are loaded bitmaps
int DrawChar(char character,int x, int y)
{
	const char* fontBitmap = currentFontInfo->p_character_bitmaps;
	const FONT_CHAR_INFO* fontDescriptor = currentFontInfo->p_character_descriptor;

	int descriptorOffset = character - currentFontInfo->start_char;

	int templateOffset = fontDescriptor[descriptorOffset].offset;
	int charWidthPixels = fontDescriptor[descriptorOffset].width;
	int charWidth = charWidthPixels/8;
	if(charWidthPixels % 8 > 0)
	{
		charWidth ++;
	}
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
	return charWidthPixels;
}

///Draw multiple characters with pre defined spacing on coordinate "x, y"
void DrawString(char* string, int x, int y)
{
    char c = string[0];
    int stringIndex = 0;
    int spacing = 0;
    while(c != '\0')
    {
    	if(c != ' ')
    		spacing += DrawChar(c, x+ spacing,y) +1;
    	else
    	{
    		spacing += currentFontInfo->space_width*2;
    	}
    	stringIndex ++;
        c = string[stringIndex];
    }
}
