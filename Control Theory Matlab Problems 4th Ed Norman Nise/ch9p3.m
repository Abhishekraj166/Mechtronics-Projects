g = zpk(-0.04098,[-0.01 -2 -3 -7],1);
rlocus(g);
sgrid(0.59,0);
axis([-10 0 -4 4])
t = 0:0.1:5;
g1 = zpk([],[-2 -3 -7],41);
t1 = feedback(g1,1);
step(t1,t)
hold on
g2 = zpk(-0.04098,[-0.01 -2 -3 -7],41);
t2 = feedback(g2,1);
step(t2,t)
