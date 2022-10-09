def threeSum(a):
    """
    Finds 3-Numbers which sum upto Zero
    """
    a.sort()
    f=[]
    for i in range(len(a)-2):
        if i==0 or (i>0 and a[i]!=a[i-1]):
            l=i+1
            h=len(a)-1
            s=0-a[i]
            z=[]
            while l<h:
                print(f,i,l,h)
                if a[l]+a[h]==s:
                    f.append([a[i],a[l],a[h]])
                    while l<h and a[l]==a[l+1]:
                        l+=1
                    while l<h and a[h]==a[h-1]:
                        h-=1

                    l+=1
                    h-=1
                elif a[l]+a[h]<s:
                    l+=1
                else:
                    h-=1
    return f 
arr=[-1,0,2,-1,-4]

print(threeSum(arr))