

from collections import defaultdict
from itertools import permutations
from math import ceil, sqrt


TT = 1
TT = int(input())
map = defaultdict(int)

for i in range(1, 1000):
	s = str(i*i)
	l = list(s)
	l.sort()
	if l[0] == '0':
		continue
	s = ""
	for i in l:
		s += i
	map[s] += 1
mx=0
num=""
for i,j in map.items():
	if mx<j:
		mx=j
		num=i
st=set()


for x in permutations(num):
	s = ""
	for c in x:
		s += c
	n = int(s)
	if sqrt(n) == ceil(sqrt(n)):
		st.add(n)

# print(*st)



for T in range(1, TT+1):
	numbers = int(input())
	for i in st:
		if(numbers==0):
			break
		numbers-=1
		print(i)