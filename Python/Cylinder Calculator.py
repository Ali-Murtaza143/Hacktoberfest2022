#define phi
phi=22/7

#input the height and radian
height = float(input('Height of cylinder: '))
radian = float(input('Radius of cylinder: '))

#formula cylinder
volume = phi * radian * radian * height
sur_area = ((2*phi*radian) * height) + ((phi*radian**2)*2)

#output
print("")
print("Volume is: ", volume)
print("")
print("Surface Area is: ", sur_area)
input()
