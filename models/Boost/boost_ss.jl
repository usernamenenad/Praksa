using ControlSystems

Vin = 10
RL = 1
RC = 1
L = 1
C = 1
Rload = 1
D0 = 0.5

A = [-1/L * (RL + (1 - D0) * (Rload * RC) / (RC + Rload)) -Rload * (1 - D0) / (L * (RC + Rload)); Rload * (1 - D0) / (C * (RC + Rload)) -1/(C * (RC + Rload))]
B = [1/L; 0]
C = [1 0]
D = 0
sys = ss(A, B, C, D)
