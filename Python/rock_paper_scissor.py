'''Winning Rules of the Rock, Paper and Scissor game as follows:
-Rock vs Paper->Paper wins
-Rock vs Scissor->Rock wins
-Paper vs Scissor->Scissor wins'''
import random
while True:
	print("Enter choice \n 1)Rock \n 2)Paper \n 3)Scissor \n")
	user_choice = int(input("User turn : "))
	while user_choice > 3 or user_choice < 1:
		user_choice = int(input("Enter valid input : "))
	if user_choice == 1 :
		user_choice_name = 'Rock'
	elif user_choice == 2 :
		user_choice_name = 'Paper'
	else :
		user_choice_name = 'Scissor'
	print("user choice is: " + user_choice_name)
	print("\nNow its computer turn.......")
	comp_choice = random.randint(1, 3)
	while comp_choice == user_choice:
		comp_choice = random.randint(1, 3)
	if comp_choice == 1:
		comp_choice_name = 'Rock'
	elif comp_choice == 2:
		comp_choice_name = 'Paper'
	else:
		comp_choice_name = 'Scissor'
	print("Computer choice is : " + comp_choice_name)
	print()
	print("---" + user_choice_name + " V/s " + comp_choice_name + "---")
	if user_choice == comp_choice :
		print("It's a draw")
		result = "Draw"
	print()
	if((user_choice == 1 and comp_choice == 2) or
	(user_choice == 2 and comp_choice ==1 )):
		print("*Paper wins*")
		result = "Paper"
	elif((user_choice == 1 and comp_choice == 3) or
	(user_choice == 3 and comp_choice == 1)):
		print("*Rock wins*")
		result = "Rock"
	else:
		print("*Scissor wins*")
		result = "Scissor"
	print()
	if result == "Draw" :
		print("********Its a tie********")
	if result == user_choice_name:
		print("********User wins********")
	else:
		print("********Computer wins********")
	print()
	ans = input("Do you want to play again ? ")
	ans = ans.lower()
	if ans == "yes" :
	    continue
	elif ans == "no" :
	    break
	else :
	    print("wrong input!!..")
print("\nThanks for playing")
