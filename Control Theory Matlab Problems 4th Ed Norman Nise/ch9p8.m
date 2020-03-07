g = zpk([],[0 -4 -6 -10],1);
gc = zpk([-0.1 -2.95],[0],296.7);
tc = feedback(gc*g,1);
step(tc)
t = 0:0.1:15;
u=t;
y = lsim(tc,u,t);
plot(t,u,t,y,'r--')
legend('ramp input','ramp response')