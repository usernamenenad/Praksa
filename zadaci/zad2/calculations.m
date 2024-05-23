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
RlList = zeros(1, 2);
for i = 1:2
    RlList(i) = Vout^2 / PoutList(i);
end

%% Duty ratio
D0List = zeros(1, 2);
for i = 1:2
    Rl = RlList(i);
    a = Rl * (n * Vin + Vout);
    b = (n^2 * Rp - Rs) * Vout - (n * Vin + 2 * Vout) * Rl;
    c = (Rl + Rs) * Vout;
    d = roots([a, b, c]);
    D0List(i) = d(2);
end
clear a b c d Rl

%% Induktivnost Lm
LmList = zeros(1, 2);
for i = 1:2
    D0 = D0List(i);
    Rl = RlList(i);
    a = (1 - D0) * ((1 - D0) * Rl + Rs);
    b = 2 * n^2 * fs;
    LmList(i) = a / b * 1e3;
end
Lm = 20e-3;

clear D0 Rl a b

%% Kapacitivnost Cf
CfList = zeros(1, 2);
for i = 1:2
    D0 = D0List(i);
    Rl = RlList(i); 
    a = (1 - D0) * n * D0^2 * 1.2 * Vin;
    b = 2 * k * fs * Vout * ((1 - D0)^2 * Rl + (1 - D0) * Rs + n^2 * D0 * Rp);
    CfList(i) = a / b * 1e3;
end
Cf = 5e-3;

clear D0 Rl a b

%% Funkcija prenosa
D0 = D0List(2);
Rl = RlList(2);

A11 = - (n^2 * D0 * Rp + (1 - D0) * Rs) / (n^2 * Lm);
A12 = -(1 - D0) / (n * Lm);
A21 = (1 - D0) / (n * Cf);
A22 = -1/(Rl * Cf);

A = [A11, A12; A21, A22];

clear A11 A12 A21 A22

B11 = D0 / Lm;
B12 = Vin * ((1 - D0) * Rl + Rs) / (Lm * ((1 - D0)^2 * Rl + (1 - D0) * Rs + n^2 * D0 * Rp));
B21 = 0;
B22 = -(n * D0 * Vin) / (Cf * ((1 - D0)^2 * Rl + (1 - D0) * Rs + n^2 * D0 * Rp));

B = [B11, B12; B21, B22];

clear B11 B12 B21 B22

C = [0, 1];
D = [0, 0];

sys = ss(A, B, C, D);
G = tf(sys);
GVV = G(1);
GDV = G(2);
s = tf("s");

%%
wc = 2 * pi * fs/10;
k = 1 / abs(evalfr(GDV, 1j * wc));
margin(k * GDV)
%%
theta = 89;
p = sqrt((1 + sind(theta)) / (1 - sind(theta)));
Glag1 = p * (1 + s/(p*wc)) / (1 + p * s / wc);
Glag2 = 1 + wc/10 / s;
Reg = k * 1 / Glag1 * Glag2;
%%
X = feedback(Reg * GDV, 1);
step(X, 10, RespConfig("Amplitude", 5))