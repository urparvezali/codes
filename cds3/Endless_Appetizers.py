

from math import ceil


def solution(T):
	x,y,r=map(int,input().split())
	print(ceil((x+r/30)/y))

TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)