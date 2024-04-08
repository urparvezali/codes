def solution(T):
	n = int(input())
	v = []
	for _ in range(n):
		x, y = map(int, input().split())
		v.append((x, y))
	
	v.sort(key=lambda x: x[1])
	
	ans = 0
	st = set()
	
	for p in v:
		ans += len(st) - len([x for x in st if x < p[0]])
		st.add(p[0])
	
	print(ans)

TT = int(input())
for T in range(1, TT + 1):
	solution(T)
	