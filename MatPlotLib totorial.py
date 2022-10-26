#first graph - line graph
import matplotlib.pyplot as pt

pt.plot([1,2,3,4],[2,4,6,8])
# [1,2,3,4] - x coordinates , [2,4,6,8] - y coordinates

pt.show()
# for display

#second graph - line graph
import matplotlib.pyplot as pt

fig = pt.figure()

rect = fig.patch
rect.set_facecolor('green')
#this changes the bg color of the graph

x = [3,6,9,12]
y = [2,4,6,8]

graph1 = fig.add_subplot(2,1,1)
#first 2 stands for height, second 1 stands for width
#gives dimensions for multiple plots

graph1.plot(x,y,'red',linewidth=4.0)
pt.title("Graph with subplots")
pt.xlabel("X axis label")
pt.ylabel("Y axis label")

pt.show()

#third graph - line graph
import matplotlib.pyplot as pt

fig = pt.figure()

rect = fig.patch
rect.set_facecolor('green')
#this changes the bg color of the graph

x = [3,6,9,12]
y = [2,4,6,8]

x2 = [1,2,3,4]
y2 = [4,8,12,16]

x3 = [1,3,5,7]
y3 = [2,4,6,8]

graph1 = fig.add_subplot(2,1,1)
#first 2 stands for height, second 1 stands for width
#gives dimensions for multiple plots

graph1.plot(x,y,'red',linewidth=4.0)
graph1.plot(x2,y2,'blue',linewidth=3.5)
graph1.plot(x3,y3,'cyan',linewidth=2.5)

pt.title("Graph with multiple plots",color='white')
pt.xlabel("X axis label",color='white')
pt.ylabel("Y axis label",color='white')

graph1.tick_params(axis='x',color='white')
graph1.tick_params(axis='y',color='white')
#changes the ticks that mark numbers on the x and y axis

#changes the color of
graph1.spines["top"].set_color('w')
graph1.spines["left"].set_color('w')
graph1.spines["bottom"].set_color('w')
graph1.spines["bottom"].set_color('w')
#changes the color of the box that contains the graph

pt.show()

#fourth graph - line graph
import matplotlib.pyplot as pt

fig = pt.figure()

rect = fig.patch
rect.set_facecolor('green')
#this changes the bg color of the graph

x = [3,6,9,12]
y = [2,4,6,8]

x2 = [1,2,3,4]
y2 = [4,8,12,16]

x3 = [1,3,5,7]
y3 = [2,4,6,8]

graph1 = fig.add_subplot(2,2,1)
#first 2 stands for height, second 1 stands for width
#gives dimensions for multiple plots

graph1.plot(x,y,'red',linewidth=4.0)

graph1.tick_params(axis='x',color='white')
graph1.tick_params(axis='y',color='white')
#changes the ticks that mark numbers on the x and y axis

#changes the color of
graph1.spines["top"].set_color('w')
graph1.spines["left"].set_color('w')
graph1.spines["bottom"].set_color('w')
graph1.spines["bottom"].set_color('w')
#changes the color of the box that contains the graph

graph2 = fig.add_subplot(2,2,2)

graph2.plot(x2,y2,'blue',linewidth=3.5)

graph2.tick_params(axis='x',color='white')
graph2.tick_params(axis='y',color='white')

graph2.spines["top"].set_color('w')
graph2.spines["left"].set_color('w')
graph2.spines["bottom"].set_color('w')
graph2.spines["bottom"].set_color('w')

graph3 = fig.add_subplot(2,1,2)

graph3.plot(x3,y3,'cyan',linewidth=3.5)

graph3.tick_params(axis='x',color='white')
graph3.tick_params(axis='y',color='white')

graph3.spines["top"].set_color('w')
graph3.spines["left"].set_color('w')
graph3.spines["bottom"].set_color('w')
graph3.spines["bottom"].set_color('w')

pt.show()
