

def solution(T):
	n=int(input())
	mx=0
	win=-1
	for _ in range(n):
		a,b=map(int,input().split())
		if a<=10 and b>mx:
			mx=max(mx,b)
			win=_
	print(win+1)



TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)