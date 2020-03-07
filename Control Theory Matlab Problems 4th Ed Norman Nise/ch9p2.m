g = zpk(-0.01,[0 0 -3 -6],161);
T = feedback(g,1);
pole(T)
k = 1;
t = 0:0.1:300;
u = 1*t;
g = zpk(-0.01,[0 0 -3 -6],k);
T = feedback(g,1);
lsim(T,u,t);
ylabel u(t)/t