num=[ 1 1 ]; 
 den=[ 1 5 6 ];
 H= tf (num,den);
 step (H) 
 figure
 rlocus (H)
 H1= feedback (H,1,-1)
 figure
 impulse (H1)
 figure
 step (H1)