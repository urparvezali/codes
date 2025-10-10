s=[_ for _ in input().split('/') if _]

ans=[]

for _ in s:
	ans.append('/')
	ans.append(_)

for _ in ans:
	print(_,end='')
if not ans:
	print('/')