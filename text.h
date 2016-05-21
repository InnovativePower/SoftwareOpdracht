#include "middle.h"
#include "arialNormal.h"
enum STYLE{
	normal =0,
	bold,
	cursive,
	underlined
}typedef Style;
struct FONT{
	const char* styles[4];
}typedef Font;


Font* currentFont;
Style currentStyle;

const Font Arial = {{arial_16ptBitmaps,0,0,0}};
