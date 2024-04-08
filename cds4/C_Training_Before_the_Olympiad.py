



def solution(T):
	n=int(input())
	a=list(map(int,input().split()))
	a.sort()
	print(*a)

TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)