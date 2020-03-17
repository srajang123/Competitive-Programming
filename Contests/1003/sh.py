l=[]
s=input()
n=0
for i in s:
    if i<='9' and i>='0':
        n=n*10+int(i)
    elif n>0:
        l.append(n)
        n=0
if n>0:
    l.append(n)
if len(l)>0:
    print(s)
    s=0
    for x in l:
        print(x,end=" ")
        s=s+x
    print("\n",s)
else:
    print(s+" has no digits")

#Output 1:
12c15ca12
12 15 12 
 39
#Output 2:
abcdef has no digits