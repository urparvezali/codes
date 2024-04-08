ucons="BCDFGHJKLMNPQRSTVWXYZ"
scons="bcdfghjklmnpqrstvwxyz"
uvow="AEIOU"
svow="aeiou"




s = list(input())

for c in range(len(s)):
	if s[c]==' ':
		continue
	if s[c].isdigit():
		if s[c]=='9':
			s[c]='0'
		else:
			s[c]=str(int(s[c])+1)
	elif s[c].isupper():
		idx1=uvow.find(s[c])
		if idx1 != -1:
			if s[c]=='U':
				s[c]='A'
			else:
				s[c]=uvow[idx1+1]
		else:
			if s[c]=='Z':
				s[c]='B'
			else:
				idx2=ucons.find(s[c])
				s[c]=ucons[idx2+1]
	else:
		idx1=svow.find(s[c])
		if idx1 != -1:
			if s[c]=='u':
				s[c]='a'
			else:
				s[c]=svow[idx1+1]
		else:
			if s[c]=='z':
				s[c]='b'
			else:
				idx2=scons.find(s[c])
				s[c]=scons[idx2+1]
for c in s:
	print(c,end='')
print()