void DrawChar(char character,
void DrawText(char* string, int x, int y)
{
    char c = string[0];
    int stringIndex = 0;
    while(c != '\0')
    {
        DrawChar(c, x+ stringIndex*GetCharSpace(),y)
        stringIndex ++;
        c = string[stringIndex];
    }
}
