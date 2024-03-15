



def solution(T):
    n=input()
    s=input()
    if s.count('0')>s.count('1'):
        print("YES")
    elif '01' in s or '10' in s:
        print("YES")
    else:
        print("NO")


TT=1
TT=int(input())
for T in range(1,TT+1):
    solution(T)