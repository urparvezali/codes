import matplotlib.pyplot as plt
import numpy as np

ts = np.linspace(-1,1,1000)

ym = np.sin(2.0 * np.pi * ts)
yc=np.sin(4.0*np.pi*ts)
yf=yc+ym

plt.subplot(3,1,1)
plt.plot(ts,ym)
plt.axhline(c='green')
plt.axvline(c='green')
plt.grid()

plt.subplot(3,1,2)
plt.plot(ts,yc)
plt.axhline(c='green')
plt.axvline(c='green')
plt.grid()

plt.subplot(3,1,3)
plt.plot(ts,yf)
plt.axhline(c='green')
plt.axvline(c='green')
plt.grid()

plt.show()