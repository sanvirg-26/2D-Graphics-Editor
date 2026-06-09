#include<stdio.h>
#include<stdlib.h>
#define WIDTH 80
#define HEIGHT 24
#define EMPTY'_'
#define PIXEL'*'
char picture[HEIGHT][WIDTH];
void clearPicture()
{
  for(int i=0;i<HEIGHT;i++)
{
for(int j=0;j<WIDTH;j++)
{
picture[i][j]=EMPTY;
}
}
}
void displayPicture()
{
  for(int i=0;i<HEIGHT;i++)
{
for(int j=0;j<WIDTH;j++)
{
printf("%c",picture[i][j]);
}
printf("\n");
}
}
void setPixel(int x,int y)
{
  if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT)
{
picture[y][x]=PIXEL;
}
}
void drawLine(int x1,int y1,int x2,int y2)
{
  int dx=x2-x1;
int dy=y2-y1;
int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
float xlnc=dx/(float)steps;
float ylnc=dy/(float)steps;
float x=x1;
float y=y1;
for(int i=0;i<=steps;i++)
{
setPixel((int)(x+0.5),(int)(y+0.5));
x+=xlnc;
y+=ylnc;
}
}
void drawRectangle(int x1,int y1,int x2,int y2)
{
  drawLine(x1,y1,x2,y1);
drawLine(x1,y2,x2,y2);
drawLine(x1,y1,x1,y2);
drawLine(x2,y1,x2,y2);
}
void drawCircle(int cx,int xy,int radius)
{
  int x=0;
int y=radius;
int p-1-radius;
while(x<=y)
{
setPixel(cx+x,cy+y);
setPixel(cx-x,cy+y);
setPixel(cx+x,cy-y);
setPixel(cx-x,cy-y);
setPixel(cx+y,cy+x);
setPixel(cx-y,cy+x);
setPixel(cx+y,cy-x);
setpixel(cx-y,cy-x);
x++;
if(p<0)
{
p+=2*x+1;
}
else(
  y--;
p+=2*(x-y)+1;
}
}
}

