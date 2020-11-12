t=int(input())
a=[]
for a0 in range(t):
    n=int(input())
    b=[]
    c=[]
    for num in range(1, n + 1):   
       if num > 1:
           for i in range(2, num):
               if (num % i) == 0:
                   break
           else:               
               b.append(num)
    for j in range(len(b)):
        tmp=1
        while((b[j]**tmp)<=n):
            tmp=tmp+1
        c.append(b[j]**(tmp-1))
    prod=1
    for j in c:
        prod=prod*j
    a.append(prod)
for k in a:
    print(k)
