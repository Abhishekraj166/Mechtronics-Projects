num = [1];
den = [1 0 1];
g = tf(num,den)
bode(g)
hold on;
num1 = [1];
den1 = [1 0.2 1];
g1 = tf(num1,den1)
bode(g1)
hold on;
num2 = [1];
den2 = [1 1.414 1];
g2 = tf(num2,den2)
bode(g2)