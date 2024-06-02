%% Parametri sistema
PoutList = [7.5, 100];
Vout = 5;
Vin = 230 * sqrt(2);
n = 0.2;
k = 0.03;
fs = 2500;
PlossT = 0.5;

%% ReqCalc

ReqList = zeros(1, 2);
for i = 1:2
    Pout = PoutList(i);
    a = Vin * Vout;
    b = n * Vin * Pout + Vout * (Pout + PlossT);
    ReqList(i) = (a/b)^2 * PlossT;
end

%% PlossCalc
Req = min(ReqList);
PlossTList = zeros(1, 2);
for i = 1:2
    Pout = PoutList(i);
    a = Req * Vout^2;
    b = 2 * Pout * Req * Vin * Vout * n + 2 * Pout * Req * Vout^2 - Vin^2 * Vout^2;
    c = Pout^2 * Req * Vin^2 * n^2 + 2 * Pout^2 * Req * Vin * Vout * n + Pout^2 * Req * Vout^2;
    d = roots([a, b, c]);
    PlossTList(i) = d(2);
end
%% Load
RlList = zeros(1, 2);
for i = 1:2
    RlList(i) = Vout^2 / PoutList(i);
end

%% Duty ratio
D0List = zeros(1, 2);
for i = 1:2
    PlossTC = PlossTList(i);
    Pout = PoutList(i);
    a = Vout * (1 + PlossTC / Pout);
    b = n * Vin + a;
    D0List(i) = a / b;
end
clear a b c d Rl

%% ILm
ILmList = zeros(1, 2);
for i = 1:2
    a = n * PoutList(i);
    b = (1 - D0List(i)) * Vout;
    ILmList(i) = a / b;
end

%% Lm
LmList = zeros(1, 2);
for i = 1:2
    Pout = PoutList(i);
    D0 = D0List(i);
    ILm = ILmList(i);
    Rl = RlList(i);
    a = (1 - D0)^2 * D0 * Rl * Vin;
    b = 2 * fs * ILm * ((1 - D0)^2 * Rl + n^2 * Req);
    LmList(i) = a / b;
end

Lm = max(LmList) + 1e-2;

%% Cf
CfList = zeros(1, 2);
for i = 1:2
    D0 = D0List(i);
    Rl = RlList(i);
    a = n * D0^2 * (1 - D0) * Vin;
    b = 2 * k * fs * Vout * ((1 - D0)^2 * Rl + n^2 * Req);
    CfList(i) = a / b;
end

Cf = max(CfList) + 1e-2;
%%
Rp = Req / D0List(2);
Rs = 0;

%%
D0 = D0List(2);
Rl = RlList(2);

A11 = -(n^2 * D0 * Rp + (1 - D0) * Rs) / (n^2 * Lm);
A12 = -(1 - D0) / (n * Lm);
A21 = (1 - D0) / (n * Cf);
A22 = -1/(Rl * Cf);

A = [A11, A12; A21, A22];

B11 = D0 / Lm;
B12 = Vin * ((1 - D0) * Rl + Rs) / (Lm * ((1 - D0)^2 * Rl + (1 - D0) * Rs + n^2 * D0 * Rp));
B21 = 0;
B22 = - n * D0 * Vin / (Cf * ((1 - D0)^2 * Rl + (1 - D0) * Rs + n^2 * D0 * Rp));

B = [B11, B12; B21, B22];

C = [0, 1];

D = [0, 0];

Ts = 1e-6;

sysC = ss(A, B, C, D);
sysD = c2d(sysC, Ts, 'zoh');

GC = tf(sysC);
GD = tf(sysD);

GVVD = GD(1);
GDVD = GD(2);

GVV = GC(1);
GDV = GC(2);
%%
s = tf("s");
P = 3.86e-5;
I = 0.1005;

Reg = P + I / s;
margin(Reg * GDV)
