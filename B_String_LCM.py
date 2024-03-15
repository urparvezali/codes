
from math import lcm
def solution(T):
    s, t = input(), input()
    ls, lt = len(s), len(t)
    lc = lcm(ls,lt)
    print([-1, s*(lc//ls)][s*(lc//ls) == t*(lc//lt)])



TT=int(input())
for T in range(1,TT+1):
	solution(T)