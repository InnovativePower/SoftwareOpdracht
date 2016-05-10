#include "bottom.h"
int width = 320;
int height = 240;
char** vRam;
void InitBottom()
{
    vRam = (char**)malloc(width*sizeof(char*));
    int i,j;
    for(i = 0; i < width; i++)
    {
        vRam[i] = (char*)malloc(height*sizeof(char));
        for(j = 0; j < height; j++)
        {
            vRam[i][j] = '0';
        }
    }

}
void DrawScreen()
{
    int i,j;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            printf("%c",vRam[j][i]);
        }
        printf("\n");
    }

}
void DrawPixel(int x, int y, char state)
{
    vRam[x][y] = state;
}
