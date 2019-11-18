from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("difusion.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, -1]
X, T = np.meshgrid(x, t)
Z = data[:, :-1]
fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot_wireframe(X, T, Z, color='green')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('\phi')

plt.savefig("difusion.png")
