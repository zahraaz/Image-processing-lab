#include<graphics.h>
#include<math.h>
#include<conio.h>

void myline(double x1,double y1,double x2,double y2){
double dy,dx,m,b,yr,xr;
dx=x2-x1;
dy=y2-y1;
if(dx!=0)
m=dy/dx;
else
    m=1000*dy;
b=y1-m*x1;
if(fabs(m)<=1){
    if(dx>0){
        for(double x=x1;x<=x2;x++){
            double y=m*x+b;
            yr=round(y);
            putpixel(x,yr,15);
        }}

else{
          for(double x=x2;x<=x1;x++){
            double y=m*x+b;
            yr=round(y);
            putpixel(x,yr,YELLOW);
          }}}

        else{
                if(dy>0){
             for(double y=y1;y<=y2;y++){
            double x=(y-b)/m;
            xr=round(x);
            putpixel(xr,y,GREEN);}}
    else {
        for(double y=y2;y<=y1;y++){
              double x=(y-b)/m;
            xr=round(x);
            putpixel(xr,y,YELLOW);
        }
    }}}









    int main (){
    int gd= DETECT ,gm;
    initgraph(&gd,&gm,"");
int xc=220;
int yc=220;
double xe;
double ye;
double q;
 double r=320;
for(q=0;q<=360;q+=6){


    xe=xc+ r*sin(q*M_PI/180);
    ye=yc-r*cos(q*M_PI/180);
    setcolor(15);
    myline(xc,yc,xe,ye);
    delay(100);
       setcolor(0);
    myline(xc,yc,xe,ye);
}
getch();
closegraph();
    return 0;
}
