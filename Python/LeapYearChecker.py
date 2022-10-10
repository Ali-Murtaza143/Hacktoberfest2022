#python program to check if a year is a leap year or not

year = int(input('enter year'))
if year % 400 == 0:
  print('it is a leap year')
elif year % 4 == 0:
  print('it is a leap year')
elif year % 100 == 0:
  print('not a leap year')
else:
  print('not a leap year')
