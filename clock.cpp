#include<graphics.h>
#include<math.h>
#include<conio.h>


void slopeline(double x1,double y1,double x2,double y2){
double dy,dx,m,b,yr,xr;
dx=x2-x1;
dy=y2-y1;
if(dx!=0)
m=dy/dx;
else
    m=1000*dy;

if(fabs(m)<=1){
    if(dx>0){
            double y=y1;
        for(double x=x1;x<=x2;x++){
           yr=round(y);
            putpixel(x,yr,5);
    y=y+m;
        }}

else{
          double y=y2;
          for(double x=x2;x<=x1;x++){
            yr=round(y);
            putpixel(x,yr,7);
            y=y+m;
          }}}

        else{

                if(dy>0){
                      double x=x1;
             for(double y=y1;y<=y2;y++){
            xr=round(x);
            putpixel(xr,y,GREEN);
        x=x+(1/m);}}
    else {
            double x=x2;
        for(double y=y2;y<=y1;y++){

            xr=round(x);
            putpixel(xr,y,YELLOW);
            x=x+(1/m);
        }
    }}}



int main (){
    int gd= DETECT ,gm ;
    initgraph(&gd,&gm,"");
int xc=220;
int yc=220;
double xe;
double ye;
double q;
 double r=320;
for(q=0;q<=360;q+=6){


    xe=xc+ r*cos(q*M_PI/180);
    ye=yc-r*sin(q*M_PI/180);
    setcolor(15);
    slopeline(xc,yc,xe,ye);
    delay(100);
       setcolor(0);
    slopeline(xc,yc,xe,ye);
}
getch();
closegraph();
    return 0;
}


