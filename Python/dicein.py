import random
import os

def roll(sides=6):
	lempardadu = random.randint(1,sides)
	return lempardadu

def main():
	putar = True
	while putar:
		tanya = str(input('\nwant to roll the dice? [y/n]'))
		if tanya.lower() != 'n':
			dadu = roll()
			print('Your dice in: ', os.system(f"toilet {dadu}"))
		else:
			putar = False
	print('\nThanks for playing')

main()
