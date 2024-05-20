%% Parametri sistema
PoutList = [7.5, 100];
Vout = 5;
Vin = 230 * sqrt(2);
n = 0.2;
k = 0.03;
Rp = 0.001;
Rs = 0.0001;
fs = 2500;

%% Load
IoutList = zeros(1, 2);
for i = 1:2
    IoutList(i) = PoutList(i) / Vout;
end

%% Duty ratio
D0List = zeros(1, 2);
for i = 1:2
    Iout = IoutList(i);
    a = n * Vin + Vout;
    b = (n^2 * Rp - Rs) * Iout - n * Vin - 2 * Vout;
    c = Vout + Rs * Iout;
    d = roots([a, b, c]);
    D0List(i) = d(2);
end
clear a b c d Rl

%% Induktivnost Lm
LmList = zeros(1, 2);
for i = 1:2
    D0 = D0List(i);
    Iout = IoutList(i);
    a = D0 * ((1 - D0)*Vin - n * Rp * Iout);
    b = 2 * n * fs * Iout;
    LmList(i) = a / b * 1e3;
end
Lm = 20e-3;

clear D0 Rl a b

%% Kapacitivnost Cf
CfList = zeros(1, 2);
for i = 1:2
    D0 = D0List(i);
    Iout = IoutList(i); 
    a = D0 * Iout;
    b = 2 * k * fs * Vout;
    CfList(i) = a / b * 1e3;
end
Cf = 100e-3;

clear D0 Rl a b

%% Funkcija prenosa
D0 = D0List(1);
Iout = IoutList(1);

A11 = - (n^2 * D0 * Rp + (1 - D0) * Rs) / (n^2 * Lm);
A12 = -(1 - D0) / (n * Lm);
A21 = (1 - D0) / (n * Cf);
A22 = 0;

A = [A11, A12; A21, A22];

clear A11 A12 A21 A22

B11 = 0;
B12 = D0 / Lm;
B13 = ((1 - D0) * Vin - n * Rp * Iout) / (Lm * (1 - D0)^2);
B21 = -1/Cf;
B22 = 0;
B23 = -Iout / (Cf * (1 - D0));

B = [B11, B12, B13; B21, B22, B23];

clear B11 B12 B21 B22

C = [0, 1];
D = [0, 0, 0];

sys = ss(A, B, C, D);
G = tf(sys);
GDV = G(3);
s = tf("s");

%% 

fc = fs / 50;
wc = 2 * pi * fc;
wl = wc / 10;

k = 1 / abs(evalfr(GDV, 1j*wc));
phicor = 86;
p = sqrt((1 + sind(phicor)) / (1 - sind(phicor)));
Glead = (p*s + wc) / (s + p*wc);
Glag = (s + wl) / s;

REG = k * Glead * Glag;
N = p * wc;
I = k * wl / p;
P = k/p + k * (1 - 1/p^2) * wl/wc;
D = k/N * (p - 1/p + (1/p^2 -1) * wl/wc);
PID = P + I/s + D * N * s / (s + N);

margin(k * Glead * GDV)
X = feedback(PID * GDV, 1);
%%
ILMList = zeros(1, 2);
ReqList = zeros(1, 2);
Losses = zeros(1, 2);
for i = 1:2
    D0 = D0List(i);
    Rl = RlList(i);
    ILMList(i) = n^2 * D0 * Vin / ((1 - D0)^2 * Rl + (1 - D0)*Rs + n^2 * D0 * Rp);
    ReqList(i) = D0 * Rp + (1 - D0) / n^2 * Rs;
    Losses(i) = ILMList(i)^2 * ReqList(i);
end