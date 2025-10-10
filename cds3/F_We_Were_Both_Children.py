

def solution(T):
	n=int(input())
	tl=list(map(int,input().split()))
	l=[]
	for i in tl:
		if i<=n: l.append(i)
	print(l)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)