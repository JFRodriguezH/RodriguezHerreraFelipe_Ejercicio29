from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("difusion_A.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot_wireframe(X, T, Z, color='green')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('\psi')

plt.savefig("difusion_A.png")

data = np.loadtxt("difusion_B.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot_wireframe(X, T, Z, color='green')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('\psi')

plt.savefig("difusion_B.png")


data = np.loadtxt("difusion_C.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot_wireframe(X, T, Z, color='green')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('\psi')

plt.savefig("difusion_C.png")

data = np.loadtxt("difusion_D.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
fig = plt.figure()
ax = plt.axes(projection="3d")
ax.plot_wireframe(X, T, Z, color='green')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('\psi')

plt.savefig("difusion_D.png")
