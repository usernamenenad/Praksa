import numpy as np
import scipy as sp

# FIRSTLY, RUN THE SCRIPT AND SEE WHAT PARAMETERS SHOULD YOU CHOOSE
Vin = 230 * np.sqrt(2)
Vout = 5
PoutList = [7.5, 100]
n = 0.2
Rp = 0.001
Rs = 0.0001
fs = 2500
k = 0.03


def getRlList():
    RlList = []
    for Pout in PoutList:
        RlList.append(Vout**2 / Pout)
    return RlList


def getD0List(RlList):
    D0List = []
    for Rl in RlList:
        a = Rl * (n * Vin + Vout)
        b = (n**2 * Rp - Rs) * Vout - (n * Vin + 2 * Vout) * Rl
        c = (Rl + Rs) * Vout
        D0List.append(min(np.roots([a, b, c])))
    return D0List


def getLmList(RlList, D0List):
    LmList = []
    for i in range(len(RlList)):
        D0 = D0List[i]
        Rl = RlList[i]
        a = (1 - D0) * ((1 - D0) * Rl + Rs)
        b = 2 * n**2 * fs
        LmList.append(a / b)
    return LmList


def getCfList(RlList, D0List):
    CfList = []
    for i in range(len(RlList)):
        D0 = D0List[i]
        Rl = RlList[i]
        a = (1 - D0) * n * D0**2 * 1.2 * Vin
        b = 2 * k * fs * Vout * ((1 - D0) ** 2 * Rl + (1 - D0) * Rs + n**2 * D0 * Rp)
        CfList.append(a / b)
    return CfList


RlList = getRlList()
D0List = getD0List(RlList)
LmList = getLmList(RlList, D0List)
CfList = getCfList(RlList, D0List)

# info(f"Resistive loads that represent {PoutList} are: {RlList}")
# info("-----------------------------\r\n")
# info(f"Needed magnetizing inductances: {LmList}")
# info("-----------------------------\r\n")
# info(f"Needed output filtering capacitances: {CfList}")
# info("-----------------------------\r\n")

# PICK PARAMETERS LARGER THAN ONES CALCULATED
Lm = 20e-3
Cf = 5e-3

# SYSTEM CALCULATION
D0 = D0List[1]  # no matter what you choose, load will only differ and
Rl = RlList[1]  # the task of regulation is to compensate that difference

A11 = -(n**2 * D0 * Rp + (1 - D0) * Rs) / (n**2 * Lm)
A12 = -(1 - D0) / (n * Lm)
A21 = (1 - D0) / (n * Cf)
A22 = -1 / (Rl * Cf)
A = [[A11, A12], [A21, A22]]

B11 = D0 / Lm
B12 = (
    Vin
    * ((1 - D0) * Rl + Rs)
    / (Lm * ((1 - D0) ** 2 * Rl + (1 - D0) * Rs + n**2 * D0 * Rp))
)
B21 = 0
B22 = -(n * D0 * Vin) / (Cf * ((1 - D0) ** 2 * Rl + (1 - D0) * Rs + n**2 * D0 * Rp))
B = [[B11, B12], [B21, B22]]

B1 = [[B11], [B21]]
B2 = [[B12], [B22]]
D1 = [[0]]
D2 = [[0]]

C = [0, 1]
D = [0, 0]

GVV = sp.signal.ss2tf(A, B1, C, D1)
GDV = sp.signal.ss2tf(A, B2, C, D2)

# COMPENSATOR (2 LAG COMPENSATOR NEEDED IN THIS CASE, MIGHT DIFFER WITH YOUR)
wc = 2 * np.pi * fs / 10
k = 0.127841775727543
p = 0.008726867790758
print(GDV)
