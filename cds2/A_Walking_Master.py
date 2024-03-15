def	solution():
	x,y,a,b=map(int,input().split())
	if (b < y) or (x+b-y) < a:
		print(-1)
	else:
		print((b-y)+abs((x+b-y)-a))

t=int(input())
while t>0:
	solution()
	t-=1