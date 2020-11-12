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
        temp=1
        while((b[j]**temp)<=n):
            temp=temp+1
        c.append(b[j]**(temp-1))
    pdt=1
    for j in c:
        pdt=pdt*j
    a.append(pdt)
for k in a:
    print(k)
