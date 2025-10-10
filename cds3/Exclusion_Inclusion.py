


from itertools import accumulate, product


def solution(T):
	n=int(input())
	l=list(map(int,input().split()))
	l.sort(reverse=True)
	nl=list(accumulate(l))
	nl.reverse()
	for i in nl:
		print(i,end=' ')
	print()


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)