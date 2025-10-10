
def solution(T):
	s=input()

	st=set()

	tmp="abcdefghijklmnopqrstuvwxyz"
	f=0
	for c in s:
		if c in st:
			continue
		elif c not in st and tmp[f]!=c:
			print("NO")
			return
		else:
			st.add(c)
			f+=1
	print("YES")
		

TT=1
# TT=int(input())
for T in range(1,TT+1):
	solution(T)