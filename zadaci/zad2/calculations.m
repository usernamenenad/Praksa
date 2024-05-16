%% Parametri sistema
Pout = [7.5, 100];
Vout = 5;
Vin = 230 * sqrt(2);
n = 0.4;
Rp = 0.00001;
Rs = 0.000001;
fs = 2500;
PlossT = 0.4;
k = 0.03;

%% Računanje radnog ciklusa
D0 = zeros(1, 2);
for i = 1:2
    pout = Pout(i);
    d = roots([n * Vin + Vout, (n^2 * Rp - Rs)*pout/Vout - n*Vin - 2*Vout, pout/Vout * Rs + Vout]);
    D0(i) = d(2);
end
clear d;
%% Računanje magnetizacione induktivnosti Lm
LmCalc = zeros(1, 2);
for i = 1:2
    d0 = D0(i);
    Iout = Pout(i) / Vout;
    a = d0 * ((1 - d0) * Vin - n*Rp*Iout);
    b = 2 * fs * n * Iout;
    LmCalc(i) = a / b * 1e3;
end
Lm = 10e-3;
clear d0 Iout a b
%% Provjera
ILMCalc = zeros(1, 2);
deltaILMCalc = zeros(1, 2);
Losses = zeros(1, 2);
for i = 1:2
    ILMCalc(i) = n * Pout(i) / ((1 - D0(i)) * Vout);
    Losses(i) = (D0(i) * Rp + (1 - D0(i)) * Rs / n^2) * ILMCalc(i);
end

%% Odabir izlazne kapacitivnosti Cf
CfCalc = zeros(1, 2);
for i = 1:2
    CfCalc(i) = D0(i) * Pout(i) / (2 * k * fs * Vout^2) * 1e3;
end
Cf = 5e-3;

%% State space and transfer function
pout = Pout(2);
d0 = D0(2);
A = [-(n^2 * d0 * Rp + (1 - d0) * Rs) / (n^2 * Lm), -(1 - d0)/(n * Lm); (1 - d0)/(n * Cf), 0];
B = [0, d0/Lm, ((1 - d0)*Vin - n*Rp*pout/Vout)/(Lm * (1- d0)^2); -1/Cf, 0, -pout/(Vout * Cf * (1-d0))];
C = [0, 1];
D = [0, 0, 0];

sys = ss(A, B, C, D);
G = tf(sys);

GDV = G(3);

%% Projektovanje Lead-Lag regulatora
fc = fs / 20;
wc = 2 * pi * fc;
k = 1 / abs(evalfr(GDV, 1j*wc));
G1 = k * GDV;

%% Trenutna margina faze

phi1 = rad2deg(angle(evalfr(G1, 1j*wc))) - 180;
phim = 80;
phicor = 89;

p = sqrt((1 + sind(phicor)) / (1 - sind(phicor)));

s = tf("s");
Glead = (p*s + wc) / (s + p*wc);
Glag = (s + wc/10) / s;
margin(Glead * G1)

%%
X = feedback(Glag * Glead * G1, 1);
step(X, RespConfig("Amplitude", 5));
%%
bode(X)