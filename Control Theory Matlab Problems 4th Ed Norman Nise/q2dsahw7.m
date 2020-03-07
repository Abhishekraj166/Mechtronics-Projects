
num=5;
den=[1 5];
Ga=tf(num,den)
subplot(1,2,1)
step(Ga)
title('(a)')
'(b)'
num=20;
den=[1 20];
Gb=tf(num,den)
subplot(1,2,2)
step(Gb)
title('(b)')