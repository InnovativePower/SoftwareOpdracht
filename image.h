#include "middle.h"
#define MAX_SIZE 10000
typedef struct
{
	int width;
	int height;
	const char iBMP[MAX_SIZE];
}BMP;

typedef enum
{
	fill,
	tiled
}BGSTYLE;
extern const BMP snoopy;
extern const BMP wc;
extern const BMP note;
extern const BMP beer;
extern const BMP exitSign;
extern const BMP bluntBoy;
extern const BMP stekelBaars1;
extern const BMP stekelBaars2;
extern const BMP stekelBaars3;
extern const BMP niceLice;

void DrawBMP(int x, int y, const BMP* image, char transparantColor);
void DrawBackGround(const BMP* image, BGSTYLE style);
