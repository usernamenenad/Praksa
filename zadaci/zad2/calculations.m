Pout = 100;
Vout = 5;
Vin = 230 * sqrt(2);
n = 0.1;
Rp = 0.001;
Rs = 0.0001;

D0 = roots([(n^2 * Rp - Rs) * Pout / Vout + n * Vin + Vout, Rs * Pout/Vout - n*Vin - 2*Vout, Vout]);
D0 = D0(2);

Lm = 100e-3;
Cf = 250e-3;
Req = Rp * D0 + (1 - D0) / n^2 * Rs;

A = [-D0 * Req / Lm, -(1 - D0)/(n * Lm); (1 - D0)/(n * Cf), 0];
B = [0, D0/Lm, ((1 - D0)*Vin - n*Req*Pout/Vout)/(Lm * (1- D0)^2); -1/Cf, 0, -Pout/(Vout * Cf * (1-D0))];
C = [0, 1];
D = [0, 0, 0];

sys = ss(A, B, C, D);
G = tf(sys);

GDV = G(3);

s = tf("s");
fs = 2500;
fc = fs / 10;
wc = 2 * pi * fc;
k = 10^(22/20);

phi = 85;
p = sqrt((1 + sind(phi)) / (1 - sind(phi)));
wz = wc / p;
wp = p * wc;

Glead = 1/p * (1 + s/wz) / (1 + s/wp);

wl = wc / 10;
Glag = (s + wl) / s;

step(feedback(k * Glead * Glag * GDV, 1), RespConfig("Amplitude", 5))

fs = 2500;
ILM = n * (Pout / Vout) / (1 - D0);
deltaILM = D0 * ((1 - D0) * Vin - n * Req * Pout/Vout) / (2 * Lm * fs * (1 - D0));

Gsys = zpk(feedback(k * Glead * Glag * GDV, 1));