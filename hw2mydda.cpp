#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int gd=DETECT, gm,i,flag,n;
float x,y,x1,x2,y1,y2,len,dx,dy,s1,s2,t,p;
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("\nEnter the value of x start :");
scanf("%f",&x1);
printf("\nEnter the value of y start :");
scanf("%f",&y1);
printf("\nEnter the value of x end :");
scanf("%f",&x2);
printf("\nEnter the value of y end :");
scanf("%f",&y2);
x=x1;
y=y1;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(x2>x1)
s1=1;
else
s1=-1;
if(y2>y1)
s2=1;
else
s2=-1;
if(dy>dx)
{
t=dx;
dx=dy;
dy=t;
flag=1;
}
else
flag=0;
n=1;
p=2*dy-dx;
putpixel(x,y,YELLOW);
while(n<=dx)
{
if (p>=0)
{
y=y+s2;
x=x+s1;
p=p+2*(dy-dx);}
else
{
if (flag==1)
y=y+s2;
else
x=x+s1;
p=p+2*dy;
}
putpixel(x,y,RED);
n=n+1;
}
getch();
closegraph();
}
