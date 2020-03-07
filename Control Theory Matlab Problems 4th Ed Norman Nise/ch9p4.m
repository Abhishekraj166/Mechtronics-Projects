g = zpk(-0.239,[-0.01 -3 -5 -7],1);
rlocus(g);
sgrid(0.5912,0);
axis([-10 0 -4 4])
t = 0:0.1:25;
g1 = zpk([],[-3 -5 -7],87.7);
t1 = feedback(g1,1);
step(t1,t)
hold on
g2 = zpk(-0.239,[-0.01 -3 -5 -7],88.7);
t2 = feedback(g2,1);
step(t2,t)
gcomp = zpk(-0.239,-0.01,1);
step(gcomp)