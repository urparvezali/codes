

def solution(T):
	n,m=map(int,input().split())
	x=input()
	s=input()
	c=0

	while s not in x:
		x=x+x
		c+=1
		if len(x)>3*len(s) and c>5:
			print(-1)
			return
	print(c)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)