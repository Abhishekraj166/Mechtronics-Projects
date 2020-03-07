syms s;
G = (s^2+3*s+10)*(s+5)/[(s+3)*(s+4)*(s^2+2*s+100)];
k = ilaplace(G);
pretty(k)