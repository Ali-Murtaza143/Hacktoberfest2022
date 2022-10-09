#Create a class Stack with instance variable items initialized to an empty list.
class Stack:
    def __init__(self):
        self.items = []
 
    def is_empty(self):
        return self.items == []
 #Define methods push, pop and is_empty inside the class Stack.
    def push(self, data):
        self.items.append(data)
 
    def pop(self):
        return self.items.pop()
 
 #Prompt the user for a string and push all the characters to a stack
s = Stack()
text = input('Please enter the string: ')
 
for character in text:
    s.push(character)
 
#Construct the reversed string by popping characters from the stack.
reversed_text = ''
while not s.is_empty():
    reversed_text = reversed_text + s.pop()
 #Deterime whether the string is palindromic by comparing the two strings
if text == reversed_text:
    print('The string is a palindrome.')
else:
    print('The string is not a palindrome.')
