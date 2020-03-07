g = zpk([],[-1 -1 -10],1);
gc = zpk(-0.1,0,1);
rlocus(gc*g);
sgrid(0.6,0);
axis([-14 0 -5 5])
syms t
t = 0:0.0001:60;
g = zpk([],[-1 -1 -10],13.6);
gc = zpk(-0.1,[0 -1 -1 -10],13.4);
step(feedback(g,1),t)
hold on;
step(feedback(gc,1),t)
