PoutList = [7.5, 100];
Vout = 5;
Vin = 230 * sqrt(2);
n = 0.2;
k = 0.01;
fs = 2500;
PlossT = 0.5;

D0 = 0.071398529052943;
Iout = 100 / 5;

Rp = 0.375554361604807;
Rs = 0;
Lm = 0.024371678197417;
Cf = 0.011912132547347;
%%

A11 = -(n^2 * D0 * Rp + (1 - D0) * Rs) / (n^2 * Lm);
A12 = -(1 - D0) / (n * Lm);
A21 = (1 - D0) / (n * Cf);
A22 = 0;

A = [A11, A12; A21, A22];

B11 = 0;
B12 = D0 / Lm;
B13 = (-D0 * Vin - Iout * Rp * n + Vin) / (Lm * (1 - D0)^2);
B21 = -1/Cf;
B22 = 0;
B23 = Iout / (Cf * (D0 - 1));

B = [B11, B12, B13; B21, B22, B23];

C = [0, 1];

D = [0, 0, 0];

Ts = 1e-6;

sysC = ss(A, B, C, D);
sysD = c2d(sysC, Ts, 'zoh');

GC = tf(sysC);
GD = tf(sysD);

GIVD = GD(1);
GVVD = GD(2);
GDVD = GD(3);