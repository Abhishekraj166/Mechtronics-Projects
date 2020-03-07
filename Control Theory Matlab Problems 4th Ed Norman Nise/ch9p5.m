g = zpk([-9.67],[0 -8 -25],669);
t= feedback(g,1);
step(t);
