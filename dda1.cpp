#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
int gd=DETECT, gm,i;
float x,y,x1,x2,y1,y2,len,dx,dy;
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("\nEnter the value of x start :");
scanf("%f",&x1);
printf("\nEnter the value of y start :");
scanf("%f",&y1);
printf("\nEnter the value of x end :");
scanf("%f",&x2);
printf("\nEnter the value of y end :");
scanf("%f",&y2);
if (abs(x2-x1)>=abs(y2-y1))
len=abs(x2-x1);
else
len=abs(y2-y1);
dx=(x2-x1)/len;
printf("%f",dx);
dy=(y2-y1)/len;
printf("%f",dy);
x=x1;
y=y1;
i=1;
while(i<=len)
{
putpixel(floor(x),floor(y),GREEN);
x=(x+dx);
y=(y+dy);
i=i+1;
}
getch();
closegraph();
}
