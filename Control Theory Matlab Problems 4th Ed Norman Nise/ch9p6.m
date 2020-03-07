g = zpk([],[-1 -3],1);
gc = zpk(-7.93,[],1.6);
gp = g*gc;
tc = feedback(gp,1);
step(tc)
