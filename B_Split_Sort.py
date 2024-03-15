

def is_sorted(lst):
	for i in range(len(lst) - 1):
		if lst[i] > lst[i + 1]:
			return False
	return True

def solution(T):
	n=int(input())
	l=list(map(int,input().split()))
	if is_sorted(l):
		print(0)
		return
	sorted_part = []
	unsorted_part = []
	
	for i in range(len(l) - 1):
		if l[i] <= l[i + 1]:
			sorted_part.append(l[i])
		else:
			sorted_part.append(l[i])
			unsorted_part = l[i + 1:]
			break
	else:
		sorted_part.append(l[-1])
	
	print(sorted_part,unsorted_part)


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)