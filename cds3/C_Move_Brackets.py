

def solution(T):
	n=int(input())
	s=input()
	mn=0
	cnt=0
	for c in s:
		if c=='(':
			cnt+=1
		else:
			cnt-=1
			mn=min(mn,cnt)
	print(-mn)



TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)