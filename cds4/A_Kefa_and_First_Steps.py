



def solution(T):
	n=int(input())
	l=list(map(int,input().split()))

	mx,c,p=0,0,0
	for i in l:
		if i>=p:
			c+=1
			mx=max(c,mx)
		else:
			c=1
			p=i
		p=i
	print(mx)


TT=1
# TT=int(input())
for T in range(1,TT+1):
	solution(T)