t = int(input()) #number of testcases
for _ in range(t): #loop for testcase
    s = int(input())
    arr = input().strip().split() #to split a single line white spaced multiple inputs into arr
    for i in range(s):
        for j in range(i,s+1): #for grouping
            for k in range (i,j): #iterating through a particular group
                print(arr[k]+" ",end="")
            print()
