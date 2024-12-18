import numpy as np
import matplotlib.pyplot as plt

a = -9.8
dt = 0.01
def solusi_analitik(v0,theta):
    vx = v0*np.cos(np.radians(theta))
    vy = v0*np.sin(np.radians(theta))
    X = [0]
    Y = [0]
    t = 0
    y = (a*t**2)/2+vy*t
    x = vx*t
    while(True):
        t += dt
        y = (a*t**2)/2+vy*t
        x = vx*t
        X.append(x)
        Y.append(y)
        if y < 0:
            break

    return X,Y,t
        
def solusi_numeric(v0,theta):
    vx = v0*np.cos(np.radians(theta))
    vy = v0*np.sin(np.radians(theta))
    x = 0
    y = 0
    X = [x]
    Y = [y]
    t = 0
    while(True):
        t = t + dt
        vy = vy + a*dt
        x = x + vx*dt
        y = y + vy*dt 
        Y.append(y)
        X.append(x)
        if y < 0:
            break
    return X,Y,t


v0 = float(input("Masukan kecepatan awal: "))
theta = float(input("Masukan sudut theta dalam derajat: "))

X_analitik,Y_analitik,t_analitik = solusi_analitik(v0,theta)
X_numeric,Y_numeric,t_numeric = solusi_numeric(v0,theta)

plt.figure(figsize=(12,8))
plt.plot(X_analitik,Y_analitik,c='b')
plt.plot(X_numeric,Y_numeric,c='r')
plt.title(f"Solusi Analitik Vs Solusi Numeric dalam Pemodelan Gerak Peluru (kecepatan awal: {v0}, sudut theta {theta})")
plt.xlabel("x")
plt.ylabel("y")
plt.legend([f"Solusi analitik, waktu: {t_analitik}",f"Solusi numeric, waktu: {t_numeric}"])
plt.show()
