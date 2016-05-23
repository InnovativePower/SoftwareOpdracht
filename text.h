#include "middle.h"
#include "arialNormal.h"
#include "arialBold.h"
#include "arialCursive.h"

typedef enum
{
	normal =0,
	bold,
	cursive
}FONT_STYLE;

typedef enum
{
	arial16p
}FONT_NAME;

 typedef struct
 {
	 const FONT_INFO* styles[4];

 }FONT;

extern FONT fArial16p;

const FONT_INFO* currentFontInfo;
char textColor;
 void DrawString(char* string, int x, int y);
 void SetFont(FONT_NAME font, FONT_STYLE style);
 void SetTextColor(char color);
