for s in [*open(0)][1:]:
		n = int(s)
		print(s,end='')
		# print('YNEOS'[n&(n-1)==0::2])