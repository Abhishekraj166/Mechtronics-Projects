clc
p = [1 12 21 10 0]
r = roots(p)
num = [1 0.01];
g = tf(num,p)
rlocus(g)
z = 0.6
sgrid(z,0)
