import turtle

from random import *

from turtle import *

penup()

goto(-140,140) #positioning the pen

for sp in range(15): #loop for creating the lines labelled with numbers

  speed(10)

 #setting the speed

  write(sp)

 #writing the int

  right(90)

 #setting right at 90 degrees

  forward(10)

 #forward at 10 units

  pendown()

 #ready to draw

  forward(150)

 #forward at 150 units

  penup()

 #not ready to draw

  backward(160)

 #back at 160 units

  left(90)

 #left set at 90 degrees

  forward(20)

 #forward at 20 units

omm = Turtle() #inheriting the turtle

omm.color('green') #setting the color to green for the first turtle

omm.shape('turtle') #setting the shape to "turtle"

omm.penup() #not ready to draw

omm.goto(-160,100) #positioning the turtle

omm.pendown() #ready todraw

biswa = Turtle() #inheriting another turtle

biswa.color('red') #setting the color og the turtle to red

biswa.shape('turtle') #declaring the shape of the turtle to "turtle"

biswa.penup() #not ready to draw

biswa.goto(-160,80) #positioning

biswa.pendown() #ready to draw

satyam = Turtle() #inheriting the last turtle

satyam.color('blue') #setting the color of the turtle as "blue"

satyam.shape('turtle') #declaring the shape of the turtle

satyam.penup() #not ready to draw

satyam.goto(-160,60) #positioning

satyam.pendown() #ready

for turn in range(100): #loop for the racew

  omm.forward(randint(1,5)) #setting the speed randomly with the "random" module

  biswa.forward(randint(1,5)) #setting the speed randomly with the "random" module

  satyam.forward(randint(1,5)) #setting the speed randomly with the "random" module

turtle.done()
