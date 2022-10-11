from symbol import parameters
import pywebio
from pywebio.input import input, FLOAT
from pywebio.output import *
import math
def add():
    x = input("Enter the first number: ", type=FLOAT)
    y = input("Enter the second number: ", type=FLOAT)
    s=x+y
    put_markdown("<h3>Result of addition</h3>")
    put_text(s)

def subtract():
    x = input("Enter the first number: ", type=FLOAT)
    y = input("Enter the second number: ", type=FLOAT)
    s=x-y
    put_markdown("<h3>Result of Subtraction</h3>")
    put_text(s)

def mul():
    x = input("Enter the first number: ", type=FLOAT)
    y = input("Enter the second number: ", type=FLOAT)
    s=x*y
    put_markdown("<h3>Result of Multiplication</h3>")
    put_text(s)

def div():
    x = input("Enter the Dividend: ", type=FLOAT)
    y = input("Enter the Divisor: ", type=FLOAT)
    if y==0:
        put_markdown("<h5>The Divisor Cannot be Zero</h5>")
    else:   
        s=x/y
        put_markdown("<h3>Result of Division</h3>")
        put_text(s)

def exponent():
    x = input("Enter the Base: ", type=FLOAT)
    y = input("Enter the Exponent: ", type=FLOAT)
    s=x**y
    put_markdown("<h3>Result of Calculation</h3>")
    put_text(s)

def logarithm():
    x = input("Enter the Argument (The number whose log has to be found): ", type=FLOAT)
    y = input("Enter the Base: ", type=FLOAT)
    s=math.log(x,y)
    put_markdown("<h3>Result of Calculation</h3>")
    put_text(s)

def modulo():
    x = input("Enter the Dividend: ", type=FLOAT)
    y = input("Enter the Divisor: ", type=FLOAT)
    s=x%y
    put_markdown("<h3>Result of Calculation</h3>")
    put_text(s)

if __name__ == '__main__':
    put_markdown("<h3>Enter your choice from the following options: </h3>")
    put_html("<h4>1. Addition<br>2. Subtraction<br>3. Multiplication<br>4. Division<br>5. Exponents<br>6. Logarithm<br>7. Modulo division<br>0. Exit</h4>")
    while True:
        x = input("Input your choice", type=FLOAT)
        if x==1:
            add()
        elif x==2:
            subtract()
        elif x==3:
            mul()
        elif x==4:
            div()
        elif x==5:
            exponent()
        elif x==6:
            logarithm()
        elif x==7:
            modulo()
        elif x==0:
            put_markdown("<h3>Thank you for using the calculator :D</h3>")
            break
        else:
            put_markdown("<h3>Please enter a valid value!!</h3>")
            