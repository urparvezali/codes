
from collections import deque


def lengthOfLongestSubstring(s:str):
	s=list(s)
	st=deque()
	mx=0
	for i in s:
		if i in st:
			while i in st:
				st.popleft()

		st.append(i)
		mx=max(mx,len(st))
	return mx

s=input()
print(lengthOfLongestSubstring(s))