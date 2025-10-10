l=input()[:-1]
l=list(l.split('+'))
ans=0
for i in l:
    if '-' not in i:
        ans+=int(i)
    elif '-' in i:
        for j in i.split('-'):
            ans-=int(j)
        ans+=2*int(i.split('-')[0])

print(ans)