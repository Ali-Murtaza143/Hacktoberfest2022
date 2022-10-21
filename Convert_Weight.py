weight = int(input('weight: '))
unit = input('(L) bs or (K) kg : ')

if unit.upper() == 'L':
    converted = weight * 0.45
    print(f'You are {converted} kilos ')
else:
    converted = weight / 0.45
    print(f'You are {converted} pounds ')
