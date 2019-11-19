from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("difusion_A.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
plt.figure()
plt.subplot(1,3,1)
plt.imshow(Z, aspect=0.1)
plt.subplot(1,3,2)
plt.plot(x, Z[-1, :], label=t[-1])
plt.plot(x, Z[100, :], label=t[100])
plt.plot(x, Z[200, :], label=t[200])
plt.plot(x, Z[0, :], label=t[0])
plt.legend()
plt.subplot(1,3,3)
plt.plot(t, Z[:, 15])
plt.tight_layout()

plt.savefig("difusion_A.png")

data = np.loadtxt("difusion_B.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
plt.figure()
plt.subplot(1,3,1)
plt.imshow(Z, aspect=0.1)
plt.subplot(1,3,2)
plt.plot(x, Z[-1, :], label=t[-1])
plt.plot(x, Z[100, :], label=t[100])
plt.plot(x, Z[200, :], label=t[200])
plt.plot(x, Z[0, :], label=t[0])
plt.legend()
plt.subplot(1,3,3)
plt.plot(t, Z[:, 15])
plt.tight_layout()

plt.savefig("difusion_B.png")


data = np.loadtxt("difusion_C.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
plt.figure()
plt.subplot(1,3,1)
plt.imshow(Z, aspect=0.1)
plt.subplot(1,3,2)
plt.plot(x, Z[-1, :], label=t[-1])
plt.plot(x, Z[100, :], label=t[100])
plt.plot(x, Z[200, :], label=t[200])
plt.plot(x, Z[0, :], label=t[0])
plt.legend()
plt.subplot(1,3,3)
plt.plot(t, Z[:, 15])
plt.tight_layout()

plt.savefig("difusion_C.png")

data = np.loadtxt("difusion_D.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
plt.figure()
plt.subplot(1,3,1)
plt.imshow(Z, aspect=0.1)
plt.subplot(1,3,2)
plt.plot(x, Z[-1, :], label=t[-1])
plt.plot(x, Z[100, :], label=t[100])
plt.plot(x, Z[200, :], label=t[200])
plt.plot(x, Z[0, :], label=t[0])
plt.legend()
plt.subplot(1,3,3)
plt.plot(t, Z[:, 15])
plt.tight_layout()

plt.savefig("difusion_D.png")
