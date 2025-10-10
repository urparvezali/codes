

from collections import deque


def solution(T):
	s=input()
	l=deque()
	srtd=1
	cnter=0
	for i in s:
		if i!='0' and i!='1':
			l.appendleft(i)
		elif i=='1':
			if srtd==0:
				cn=0
				for j in l:
					if j=='-':
						cn-=1
						if cn<0:
							srtd=1
							break
					else:
						cn+=1
				if cn>=0:
					print("NO")
					return
			srtd=1
			l.clear()
		elif i=='0':
			if srtd==1:
				if l.count('+')<=l.count('-'):
					print("NO")
					return
			srtd=0
			l.clear()
	print("YES")



TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)