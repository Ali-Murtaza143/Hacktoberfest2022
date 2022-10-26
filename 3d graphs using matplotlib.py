#to show a 3D scatter plot
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as pt

fig = pt.figure()

chart = fig.add_subplot(1,1,1,projection='3d')

X,Y,Z = [1,2,3,4,5,6,7,8],[2,4,2,7,4,6,8,7],[8,6,6,5,7,7,7,9]

chart.scatter(X,Y,Z,c='red',marker='o')
chart.set_xlabel('x axis')
chart.set_ylabel('y axis')
chart.set_zlabel('z axis')

pt.show()

#to show a 3d wireframe
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as pt
import numpy as np

fig = pt.figure()

chart = fig.add_subplot(1,1,1,projection='3d')

x,y,z=axes3d.get_test_data(0.05)
chart.plot_wireframe(x,y,z,rstride=10,cstride=10)

chart.set_xlabel('x label')
chart.set_ylabel('y label')
chart.set_zlabel('z label')

pt.show()
