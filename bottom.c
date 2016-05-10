#include "bottom.h"
char** vRam;
void InitBottom()
{
    vRam = (char**)malloc(160*sizeof(char*));
    int i,j;
    for(i = 0; i < 160; i++)
    {
        vRam[i] = (char*)malloc(120*sizeof(char));
        for(j = 0; j < 120; j++)
        {
            vRam[i][j] = '0';
        }
    }

}
void DrawScreen()
{
    int i,j;
    for(i = 0; i < 160; i++)
    {
        for(j = 0; j < 120; j++)
        {
            printf("%c",vRam[i][j]);
        }
        printf("\n");
    }

}
void DrawPixel(int x, int y, char state)
{
    vRam[x][y] = state;
}
