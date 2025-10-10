for _ in range(int(input())):
	h=[0]+[int(p) for p in input()]
	while max(h)>=5:
		p=h.index(max(h))
		h[p:]=[0]*(abs(len(h)-p))
		h[p-1]+=1

	print(int(''.join([str(g) for g in h])))