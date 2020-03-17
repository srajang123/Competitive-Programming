n=int(input())
a=input().strip()
b=input().strip()
k=int(input())
c=""
for i in range(n-1):
    c=a+b+b
    a=b
    b=c
if len(c)>=k:
    print(c[k-1])
else:
    print(-1)