a,b,c=map(int,input().split())

dtr=b**2-4*a*c
if dtr>0:
	print(2)
	y=(-b+sqrt(dtr))/2/a
	x=(-b-sqrt(dtr))/2/a
	print(x)
	print(y)
elif not dtr:
	print(1)
	print((-b)/2/a)
else:
	print(-1)