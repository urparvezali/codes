
def solution(T):
	n=int(input())
	d=n//2020
	c=n%2020

	if d>=1 and c<=d:
		print("YES")
	else:
		print("NO")



TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)