



def solution(T):
	n=int(input())
	s=input()

	ans=0
	st=set()
	for i in range(len(s)-1):
		st.add(s[i+1:])
		st.add(s[i]+s[i+2:])
		for j in range(i,len(s)):
			st.add(s[i]+s[j+2:])
	print(len(st)+1)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)