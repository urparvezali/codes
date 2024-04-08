from itertools import groupby


n=int(input())
l=filter(lambda s: s!=' ',input())
grouped=groupby(l)

a=[]
for key,group in grouped:
    a.append(list(group))

ans=0
for i in range(len(a)-1):
    ans=max(ans,2*min(len(a[i]),len(a[i+1])))

print(ans)