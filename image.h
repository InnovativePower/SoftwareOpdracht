#include "middle.h"
#define MAX_SIZE 20000
typedef struct
{
	int width;
	int height;
	const char iBMP[MAX_SIZE];
}BMP;

extern const BMP snoopy;
extern const BMP wc;
void DrawBMP(int x, int y, const BMP* image, char transparantColor);
void DrawBackGround(const BMP* image);
