
void DrawRectangle(int x, int y, int width, int height, int isFilled);

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int isFilled);
void DrawSimpleTriangle(int x, int y, float sideLength, int isFilled);
void DrawEllipse(int x, int y, int width, int height,int isFilled);
void DrawLine(int x1, int y1, int x2, int y2);

void DrawLineCol(int x1, int y1, int x2, int y2, char color);
void InitMiddle();
void SetLineColor(char newColor);
void SetFillColor(char newFillColor);
void DrawPixel(int x, int y, char color);

void DrawCircle(int x, int y, int radius, int isFilled);
void SetLineThickness(int newThickness);
char fillColor;
char lineColor;
int lineThickness;
