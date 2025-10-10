
def solution(T):
	n=int(input())
	l=list(map(int,input().split()))
	cnt=0
	s=set()
	for i in l:
		if i in s:
			s.remove(i)
		else:
			s.add(i)
		cnt=max(cnt,len(s))
	print(cnt)
TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)