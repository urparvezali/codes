
from math import gcd
def solution(T):
	n=int(input())
	if n%2==0:
		print(n//2,n//2-1,1)
	else:
		print((n-3)//2,(n-3)//3*2,1)

TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)