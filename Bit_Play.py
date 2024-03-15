md=1000000007
def solution(T):
	n=int(input())
	l=list(map(int,list(input())))
	if n==1:
		print(0)
		return
	ans=0
	for i in range(2,n,2):
		hoice=False
		k=0
		if (l[i-2]|l[i-1]==l[i]):
			hoice=True
			k+=1
		if (l[i-2]&l[i-1]==l[i]):
			hoice=True
			k+=1
		if (l[i-2]^l[i-1]==l[i]):
			k+=1
			hoice=True
		if hoice==False:
			ans=0
			break
		if ans==0 and i==2:
			ans+=k
		else:
			ans=(ans*k)%md
	print(ans)

TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)