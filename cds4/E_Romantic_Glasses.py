
def solution(T):
	n=int(input())
	l=list(map(int,input().split()))
	for i in range(2,n+1):
		for j in range(n-i+1):
			subarr=l[j:j+i]
			if sum(subarr[0::2])==sum(subarr[1::2]):
				print("YES")
				return
	print("NO")


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)