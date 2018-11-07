import numpy as np 
import matplotlib.pyplot as plt 

#### DATOS

Datos = np.loadtxt('sample.dat')

gaussian_distribution = Datos

#### GRAFICA

sigma = 3.5
mu = 2.5

x = np.arange(-10, 15, 0.1)
plt.plot(x, 1/(sigma * np.sqrt(2 * np.pi)) *np.exp( - (x - mu)**2 / (2 * sigma**2) ), linewidth=2, color='r')

plt.hist(gaussian_distribution, bins=100, normed=True)
plt.xlabel("Radio")
plt.ylabel("Velocidad de Rotacion")
plt.savefig('sample.pdf')
plt.show()
plt.clf()
