def	solution(s):
	up=0
	lo=0
	dig=0
	c=0
	for i in s:
		if i.isupper():
			up+=1
		if i.islower():
			lo+=1
		if i.isdigit():
			dig+=1
		if up>0 and lo>0 and dig>0:
			c+=1
			up=0
			lo=0
			dig=0
	print(c)


while True:
	try:
		s = input()
	except EOFError:
		break
	solution(s)