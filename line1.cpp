#include<graphics.h>
#include <stdio.h>

int main(){
    int gd=DETECT, gm,i;
initgraph(&gd,&gm,"C:\\TC\\BGI");

//for(i=0; i<640;i++){
  //   putpixel(i,240,15);
//}
   //for(i=0; i<480;i++){
 //    putpixel(320,i,15);
//}
int x1,y1,x2,y2;
printf("\nEnter the value of x start :");
scanf("%f",&x1);
printf("\nEnter the value of y start :");
scanf("%f",&y1);
printf("\nEnter the value of x end :");
scanf("%f",&x2);
printf("\nEnter the value of y end :");
scanf("%f",&y2);
float dy = y2-y1;
float dx = x2-x1;
float m = dy/dx;
float b= y1 - m*x1;
int x;

for (x=x;x<x;x++){
    yi=m*x+b;
putpixel(xi,yi,15);
}
    getch();
    return 0;
}

