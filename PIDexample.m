kp=300;
ki= 70;
kd= 10;
%open loop step response
num = 1;
den = [1 10 20];
step(num,den)
title('open loop step response')

%proprtional control
num1 = [kp];
den1= [ 1 10 20+kp];
t=0:0.01:2;
figure
step(num1 , den1,t);
title('proprtional control')

%proprtional control closed loop
sys1 = cloop(kp*num,den);
figure
step(sys1,t);
title('proprtional control closed loop')

%proportional derivative control
num2 = [kd kp];
den2 = [ 1 10+kd 20+kp];
figure
step(num2,den2,t);
title('proportional derivative control')

%proportional integral control
kpp=30;
num3= [kpp ki];
den3 = [1 10 20+kp ki];
figure
step(num3,den,t);
title('proportional integral control')

%PID control
kp2=350;
ki2 = 300;
kd2 = 50;
num4 = [kd2 kp2 ki2];
den4 = [1 10+kd2 20+kp2 ki2];
figure
step (num4,den4,t);
title('PID control')
