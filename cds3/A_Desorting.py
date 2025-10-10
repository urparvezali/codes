
from math import floor


def solution(T):
	n=int(input())
	l=list(map(int,input().split()))

	mi=1000000000000000000000
	for i in range(n-1):
		if l[i+1]-l[i]<0:
			print(0)
			return
		elif l[i+1]-l[i]==0:
			mi=1
		elif (l[i+1]-l[i])%2==0:
			mi=min(mi,1+(l[i+1]-l[i])//2)
		else:
			mi=min(mi,1+floor((l[i+1]-l[i])/2))
	print(mi)



TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)