for _ in list(open(0))[1:]:
	n,k=map(int,_.split())
	print("NO" if k**2>n or n%2!=k%2 else "YES")