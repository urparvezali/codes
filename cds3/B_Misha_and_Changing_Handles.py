

q=int(input())

d={}
l=[]
for _ in range(q):
    a,b=input().split()
    if a in d.values():
        for i in d:
            if d[i]==a:
                d[i]=b
                break
    else:
        d[a]=b
print(len(d))
for i,j in d.items():
    print(i,j)