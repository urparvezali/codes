a=int(input())
b=int(input())
c=a+b

a=str(a)
b=str(b)
c=str(c)

na=str()
nb=str()
nc=str()

for i in a:
    if i!='0':
        na+=i
for i in b:
    if i!='0':
        nb+=i
for i in c:
    if i!='0':
        nc+=i
        
if int(na)+int(nb)==int(nc):
    print('YES')
else:
    print('NO')