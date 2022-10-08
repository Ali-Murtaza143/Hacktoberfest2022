
from turtle import *
import colorsys as cls
bgcolor("black")
pensize(3)
speed(0)        
n,h=100,0
goto(80,40)
for i in range(90):
        h+=1/n
        color(cls.hsv_to_rgb(h,1,0.8))
        lt(250)
        fd(i*2)
        rt(40)
        backward(i*3)
        circle(60,90)
hideturtle()
done()
