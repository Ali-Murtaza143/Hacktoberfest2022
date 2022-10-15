'''Chef is playing a card game with his friend Rick Sanchez. He recently won against Rick's grandson Morty; however, Rick is not as easy to beat. The rules of this game are as follows:

The power of a positive integer is the sum of digits of that integer. For example, the power of 1313 is 1+3 = 41+3=4.
Chef and Rick receive randomly generated positive integers. For each player, let's call the integer he received final power.
The goal of each player is to generate a positive integer such that its power (defined above) is equal to his final power.
The player who generated the integer with fewer digits wins the game. If both have the same number of digits, then Rick cheats and wins the game.
You are given the final power of Chef P_CP 
C
​
  and the final power of Rick P_RP 
R
​
 . Assuming that both players play optimally, find the winner of the game and the number of digits of the integer he generates.  '''
 
# solution:

t= int(input())
for i in range(t):
    c,d = map(int,input().split())
    flag1 = 0
    flag2 = 0
    cs = c 
    ds = d
    while c>0:
        flag1+=1 
        c=int(c//10)
    while d>0:
        flag2+=1 
        d = int(d//10)
    
    if flag1 == flag2:
        if (cs//9) < (ds//9):
            if cs%9 == 0:
                print(0,cs//9)
            else:    
                print(0,int(cs//9)+1)
        elif (ds//9) <= (cs//9):
            if ds%9==0:
                print(1,ds//9)
            else:    
                print(1,int(ds//9)+1)
    elif flag1>flag2:
        if ds%9==0:
            print(1,ds//9)
        else:    
            print(1,int(ds//9)+1)
    elif flag1<flag2:
        if cs%9 == 0:
            print(0,cs//9)
        else:    
            print(0,int(cs//9)+1)
