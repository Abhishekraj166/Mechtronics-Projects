num = [10 1000];
den = poly([-0.1 -10]);
g = tf(num,den)
bode(g)