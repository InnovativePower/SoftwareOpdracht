#include "middle.h"
#define MAX_SIZE 20000
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
extern const BMP bluntBoy;
void DrawBMP(int x, int y, const BMP* image, char transparantColor);
void DrawBackGround(const BMP* image, BGSTYLE style);
