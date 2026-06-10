#include<stdio.h>
#include<stdlib.h>
#define WIDTH 80
#define HEIGHT 24
#define EMPTY '_'
#define PIXEL '*'
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
void drawCircle(int cx,int cy,int radius)
{
  int x=0;
int y=radius;
int p=1 - radius;
while(x<=y)
{
setPixel(cx+x,cy+y);
setPixel(cx-x,cy+y);
setPixel(cx+x,cy-y);
setPixel(cx-x,cy-y);
setPixel(cx+y,cy+x);
setPixel(cx-y,cy+x);
setPixel(cx+y,cy-x);
setPixel(cx-y,cy-x);
x++;
if(p<0)
{
p+=2*x+1;
}
else{
  y--;
p+=2*(x-y)+1;
}
}
}
void drawTriangle(int x1,int y1,int x2, int y2,int x3, int y3)
{
  drawLine(x1,y1,x2,y2);
drawLine(x2,y2,x3,y3);
drawLine(x3,y3,x1,y1);
}
int main()
{
int choice;
clearPicture();
printf("2D Graphics Ediotor");
printf("Canvas size:%dx%d\n",WIDTH,HEIGHT);
printf("Use coordinates x y.\n");

while(1)
{
printf("\nMENU\n");
printf("1.Draw Line\n");
printf("2.Draw Rectangle\n");
printf("3.Draw Circle\n");
printf("4.Draw Triangle\n");
printf("5.Display Pictures\n");
printf("0.Exit\n");
scanf("%d",&choice);
if(choice==1)
{
int x1,y1,x2,y2;
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
drawLine(x1,y1,x2,y2);
}
else if(choice==2)
{
int x1,y1,x2,y2;
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
drawRectangle(x1,y1,x2,y2);
}
else if(choice==3)
{
int cx,cy,radius;
scanf("%d%d%d",&cx,&cy,&radius);
  drawCircle(cx,cy,radius);
}
else if(choice==4)
{
int x1,y1,x2,y2,x3,y3;
scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
drawTriangle(x1,y1,x2,y2,x3,y3);
}
else if(choice==5)
{
displayPicture();
}
else if(choice==0)
{
break;
}
}
return 0;
}

  
