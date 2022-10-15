#Python3.

#Importing termcolor module for Coloring the text in the terminal
from termcolor import colored

#Declaring Login function without any parameter
def login():
    #
    creditNum = int(input("Enter your number which is greater than 9 Digits: "))
    creditNuminStr = str(creditNum)
    creditNumLen = len(creditNuminStr)
            
    if creditNumLen >= 10:        
        #The below code call the inputCredit function and save returned two values in the respective variable.
        creditNum, creditNuminString = inputCredit(creditNum)    
        
        #In the below code the credit info received by variable is passed to validateCheck for the validation purpose.
        validateCheck(creditNum, creditNuminString)
    else:
        print(colored("\nThe Number you have provided is not valid.","red"))


#Decraling inpurCredit function which is used just to make your number looks in  a cool way, (Not Necessary).
def inputCredit(creditNum):
    creditNum = creditNum
    creditNuminStr = str(creditNum)
    creditNumLen = len(creditNuminStr)
    creditNuminString =''

    j = 0
    k = 4
    
    for i in range(round((len(creditNuminStr)+1)/4)):
        creditNuminString +=creditNuminStr[j:k] + ' '
            
        j = j + 4    
        k = k + 4
    print(colored("\n\t The number you have provided is: "+ creditNuminString +"\n ","yellow"))
    return creditNuminStr, creditNuminString


#Declaring validateCheck function which is the core block of this algorithm, Everything happens inside this block so please have a look. 
def validateCheck(creditnumber, creditNuminString):
    creditnumber = str(creditnumber)
    credit = []

    for i in range(len(creditnumber)):
        credit.append(int(creditnumber[i]))
    

    creditRev = credit[::-1]

    oddInd= [creditRev[i] for i in range(0,len(credit),2)]
    evenInd = [creditRev[i] for i in range(1,len(creditRev),2)]

    eleOfEvenInd = [evenInd[i] * 2 for i in range(len(evenInd))]

    elementOfEvenInd = []

    for i in range(len(eleOfEvenInd)):
        elementvalue = len(str(eleOfEvenInd[i]))

        if (elementvalue == 1):
            elementOfEvenInd.append(eleOfEvenInd[i])
        else:
            elementOfEvenInd.append(eleOfEvenInd[i]-9)    

    totalValue = oddInd + elementOfEvenInd

    totalValues = sum(totalValue)
    #print(sumOfOdd)
    modOfValue = totalValues % 10


    if (modOfValue == 0):
        print (colored("\t The provided number "+creditNuminString+" is a valid number.\n","green"))
    else:
        print (colored("\t The provided number " +creditNuminString+" is not a valid number.\n","red"))

#Initializing the First function Login.
login()


