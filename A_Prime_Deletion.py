
def solution(T):
	n=input()
	l=['11', '13', '17', '19', '23', '29', '31', '37', '41', '43', '47', '53', '59', '61', '67', '71', '73', '79', '83', '89', '97']

	ans=''
	for i in l:
		cnt=0
		for j in n:
			if j==i[cnt]:
				cnt+=1
				if cnt==2:
					print(i)
					return

	print(-1)

TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)