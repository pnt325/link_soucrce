# Implementation of matplotlib function 
import matplotlib.pyplot as plt 
import matplotlib.animation as animation
import numpy as np 
from matplotlib.colors import LogNorm

fig = plt.figure()

ax = fig.add_subplot(1, 1, 1)
x= 0
y = 1

def ani(i, x, y):
    ax.clear()
    z = np.random.rand(8,8)
    ax.pcolormesh(z)
    plt.title('matplotlib.pyplot.pcolormesh() function Example', fontweight ="bold") 
    # plt.pcolormesh(z)     

     
# Z = np.random.rand(8, 8) 
     
# plt.pcolormesh(Z) 
  
# plt.title('matplotlib.pyplot.pcolormesh() function Example', fontweight ="bold") 

ani = animation.FuncAnimation(fig, ani,fargs=(x, y), interval=50)
plt.show() 