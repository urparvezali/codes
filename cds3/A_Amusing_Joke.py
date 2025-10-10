a=list(input())
a.extend(list(input()))
c=list(input())
a.sort()
c.sort()
if a==c:
	print("YES")
else:
	print("NO")