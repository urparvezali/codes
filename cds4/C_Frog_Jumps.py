
from itertools import groupby


def solution(T):
	l=[i for i in groupby(input())]
	print(l)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)