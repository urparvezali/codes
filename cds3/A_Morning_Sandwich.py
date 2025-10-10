

""" def dfs(n,vs,g):
	if vs[n]:
		return
	vs[n]=True
	print(n)
	for i in g[n]:
		dfs(i,vs,g) """


def solution(T):
	b,c,h=map(int,input().split())
	if(b>c+h+1):
		print(c+h+1+c+h)
	else:
		print(b+b-1)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)