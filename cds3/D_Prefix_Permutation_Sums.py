

def solution(T):
	n = int(input())
	a, s, l = list(map(int, input().split())), set(range(1, n + 1)), -1
	if a[0] in s: s.remove(a[0])
	else: l = a[0]
	for i in range(1, n - 1):
		d = a[i] - a[i - 1]
		if d in s:
			s.remove(d)
		elif l == -1:
			l = d
		else:
			print("NO")
			return

	if l == -1: r =  (n + 1) * n // 2; print("YES" if     -(- r + a[n - 2]) == sum(s) else "NO")
	else:
		print("YES" if sum(s) == l else "NO")


TT=1
TT=int(input())
for T in range(1,TT+1):
	solution(T)