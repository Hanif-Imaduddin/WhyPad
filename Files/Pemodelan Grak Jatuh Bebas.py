import matplotlib.pyplot as plt
 
a = -9.8
dt = 0.1
def y_analitik(t,y0):
    return (a*t**2/2)+y0 
 
def solusi_analitik(y0):
    t = 0
    T = [0]
    Y = [y0]
    t += dt
    y = y_analitik(t,y0)
    # while(True):
    #     t += dt
    #     y = y_analitik(t,y0)
    #     Y.append(y)
    #     T.append(t)
    #     if y <= 0:
    #         break
    while y > 0:
        Y.append(y)
        T.append(t)
        t += dt
        y = y_analitik(t,y0)
    return Y,T,T[-1]
 
def solusi_numeric(y0):
    v = 0
    t = 0
    y = y0
    Y = [y0]
    T = [t]
    while(True):
        t = t+dt
        v = v+(a*dt)
        y = y+(v*dt)
        Y.append(y)
        T.append(t)
        if y <= 0:
            break
    return Y,T,t
 
 
y0 = float(input("Masukan Tinggi Awal: "))
Y_analisis,T_analisis,t_analitik = solusi_analitik(y0)
Y_numeric,T_numeric,t_numeric = solusi_numeric(y0)
 
plt.figure(figsize=(12,8))
plt.plot(T_analisis,Y_analisis,c='b')
plt.plot(T_numeric,Y_numeric,c='r')
plt.xlabel("Waktu (detik)")
plt.ylabel("Tinggi (meter)")
plt.title(f"Solusi Analitik vs Solusi Numeric dalam Pemodelan Gerak Jatuh Bebas (y0 = {y0} meter)")
plt.legend([f"Solusi analitik, waktu: {t_analitik}",f"Solusi numeric, waktu {t_numeric}"])
plt.show()
print(T_analisis[-1])
