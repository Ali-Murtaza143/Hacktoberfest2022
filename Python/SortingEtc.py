a=[int(x) for x in input()]
print(a)
def bubblesort(x):
    for i in range(len(x)-1):
        for j in range(len(x)-i-1):
            if x[j]>x[j+1]:
                x[j],x[j+1]=x[j+1],x[j]
    return x
def insertionsort(x):
    for i in range(len(x)):
        j=i-1
        while(j>0 and x[j]>x[j+1]):
            x[j],x[j+1]=x[j+1],x[j]
            j-=1
    return x
def selectionsort(x):
    for i in range(len(x)):
        mini=i
        for j in range(i,len(x)):
            if x[mini]>x[j]:
                mini=j
        x[i],x[mini]=x[mini],x[i]
    return x
def mergesort(a):
    if len(a)>1:
        mid=len(a)//2
        L=a[:mid]
        R=a[mid:]
        mergesort(L)
        mergesort(R)
        i=j=k=0
        while i<len(L) and j<len(R):
            if L[i]<=R[j]:
                a[k]=L[i]
                i+=1
            elif L[i]>=R[j]:
                a[k]=R[j]
                j+=1
            k+=1
        while(i<len(L)):
            a[k]=L[i]
            i+=1
            k+=1
        while(j<len(R)):
            a[k]=R[j]
            j+=1
            k+=1

def quicksort(x):
    if(len(x)<1):
        return x
    l,u=[],[]
    pivot=x.pop()
    for i in x:
        if i<=pivot:
            l.append(i)
        else:
            u.append(i)
    return quicksort(l)+[pivot]+quicksort(u)

print(quicksort(a))


