
def solution(T):
	n=int(input())
	l=sorted(map(int,input().split()))
	j=0
	for i in range(n-1,0,-1):
		print(l[j],end=' ')
		j+=i
	print(l[-1])
TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)