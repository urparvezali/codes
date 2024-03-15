
def vo(ch):
	if ch=='a' or ch=='e':
		return True
	return False


def solution(T):
	n=int(input())
	s=input()
	ans=list()

	for i in range(len(s)-1,-1,-1):
		if s[i]!='*' and vo(s[i]):
			if i==len(s)-1:
				if vo(s[i]):
					ans.append(s[i-1:i])
				else:
					ans.append(s[i-2:i])
			if i>0 and not vo(s[i-1]):
				ans.append(s[i-1:i+1])
			else:
				ans.append(s[i:i+1])
				s[i]='*'
				s[i+1]='*'
					

			


	print(ans)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)