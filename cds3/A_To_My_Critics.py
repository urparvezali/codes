

def solution(T):
	l=list(map(int,input().split()))
	l.sort(reverse=True)
	if l[0]+l[1]>=10:
		print("YES")
	else:
		print("NO")


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)