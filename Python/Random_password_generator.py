#Password Generator Project
import random
import string 

lower = list(string.ascii_lowercase)
upper = list(string.ascii_uppercase)
both = (upper + lower)
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("""
𝒲𝑒𝓁𝒸𝑜𝓂𝑒 𝓉𝑜 𝓉𝒽𝑒 𝒫𝓎𝒫𝒶𝓈𝓈𝓌𝑜𝓇𝒹 𝒢𝑒𝓃𝑒𝓇𝒶𝓉𝑜𝓇
""")

nr_letters= int(input("How many letters?: "))
if nr_letters > 0:
    while(1):
        case = input("\nFor lowercase - l, For uppercase - u, For both - b: ").lower()
        if case == 'l' or case == 'u' or case == 'b':
            break;
        else:
            print("Type only l or u or p letter\n")
        
nr_symbols = int(input(f"\nHow many symbols?: "))
nr_numbers = int(input(f"\nHow many numbers?: "))

letters_pass=[]
symbols_pass=[]
numbers_pass=[]

for x in range(nr_letters):
    if case == 'l':
        random.shuffle(lower)
        letters_pass += random.choice(lower)
    elif case == 'u':
        random.shuffle(upper)
        letters_pass += random.choice(upper)
    else:
        random.shuffle(both)
        letters_pass += random.choice(both)
   
  
for y in range(nr_symbols):
    random.shuffle(symbols)
    symbols_pass += random.choice(symbols)
  
for z in range(nr_numbers):
    random.shuffle(numbers)
    numbers_pass+= random.choice(numbers)

password=letters_pass+symbols_pass+numbers_pass

random.shuffle(password)

print(f"\nYour new password is : {''.join(password)}")
