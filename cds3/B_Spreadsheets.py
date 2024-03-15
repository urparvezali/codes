def solution(T):
	s=str(input())
	alp=0
	for i in s:
		if i.isalpha():
			alp+=1
	if alp==2 and s.count('R')==1 and s.count('C')==1 and s.index('R')+2<=s.index('C'):
		t=list(s.split('C'))
		c=int(t[-1])
		r=int(t[0][1:])
		t=str()
		while c:
			car=c%26
			c//=26
			if car!=0:
				t=chr(64+car)+t
			else:
				t='Z'+t
				c-=1
		print(t,end='')
		print(r)
	else:
		c=str()
		for i in range(len(s)):
			if not s[i].isalpha():
				c=s[:i]
				r=int(s[i:])
				break
		j=len(c)
		col=0
		for i in range(len(c)):
			col+=pow(26,i)*(ord(c[j-i-1])-64)
		print('R',end='')
		print(r,end='')
		print('C',end='')
		print(col)



TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)


"""
	10/2 0
	5/2  1
	2/2  0
	1/2  1



"""