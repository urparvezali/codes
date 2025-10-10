n=int(input())

l=['' for _ in range(2*n+1)]
c=0
for i in range(n+1):
	for j in range(n-i):
		l[c]=l[c]+'  '
	for j in range(i+1):
		l[c]=l[c]+str(j)+' '
	for j in range(i-1,-1,-1):
		l[c]=l[c]+str(j)+' '
	c+=1
for i in range(n):
	for j in range(i+1):
		l[c]=l[c]+'  '
	for j in range(n-i):
		l[c]=l[c]+str(j)+' '
	for j in range(n-i-2,-1,-1):
		l[c]=l[c]+str(j)+' '
	c+=1
for i in l:
	print(i[0:-1])