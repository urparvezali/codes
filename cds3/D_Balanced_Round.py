


def solution(T):
	n,k=map(int,input().split())
	l=list(map(int,input().split()))
	l.sort()
	cnt=0
	mx=0
	for i in range(0,n-1):
		if l[i+1]-l[i]<=k:
			cnt+=1
			mx=max(cnt,mx)
		else:
			cnt=0
	if n==1:
		print(0)
		return
	print(n-mx-1)
			

TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)