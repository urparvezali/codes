

n=int(input())
v=list(map(int,input().split()))
ans=0
for i in range(len(v)):
    if v[i]>0:
        ans+=v[i]-1
        v[i]=1
    elif v[i]<0:
        ans+=-1-v[i]
        v[i]=-1
if v.count(-1)&1 and v.count(0)==0:
    print(ans+2)
elif v.count(-1)&1:
    print(ans+v.count(0))
else:
    print(ans+v.count(0))