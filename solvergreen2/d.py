

v=list(set(map(int,input().split())))
z=[]
temp=[]
for i in range(len(v)-1):
    if(i==len(v)-2):
        if v[i]+1==v[i+1]:
            temp.append(v[i])
            temp.append(v[i+1])
            z.append(temp)
        else:
            temp.append(v[i])
            z.append(temp)
            z.append([v[i+1]])
        break
    if v[i]+1==v[i+1]:
        temp.append(v[i])
    else:
        temp.append(v[i])
        z.append(temp)
        temp=[]

for i in z:
    if len(i)==1:
        if z.index(i)==len(z)-1:
            print(i[0],end=' ')
            break
        print(i[0],end=', ')
    else:
        print(i[0],end='-')
        if z.index(i)==len(z)-1:
            print(i[-1],end=' ')
            break
        print(i[-1],end=', ')