num = [1 0];
den = poly([-10 -100]);
g = tf(num,den)
bode(g)