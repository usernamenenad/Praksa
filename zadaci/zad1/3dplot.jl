using Plots
using Polynomials

Ploss = 0.01
Vin = 230 * sqrt(2)
n = 0.037

Vout = 5:0.01:12
Pout = 7.5:0.01:100

f(vout, pout) = roots(Polynomial([-vout, n*Vin + vout - Ploss * vout / pout, Ploss * vout / pout]))[2]

surface(Vout, Pout, f, camera=(10, 30), xlabel="V_out", ylabel="P_out", zlabel="D_0", legend=false)
png("D_0")  
