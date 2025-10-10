def solution(T):
	n,k=map(int,input().split())

	cnt=0
	for i in range(n,0,-1):
		b=n
		a=i
		c=0
		while True:
			# print(a,b)
			[a,b]=[b-a,a]
			if b<0:
				break
			c+=1
		if c>=k:
			cnt+=1
		# print(c)
	print(cnt)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)