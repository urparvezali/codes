

def solution(T):
    t=input()
    n=int(t[1])
    s=t[0]

    for i in range(65+32,65+8+32):
        if(chr(i)+str(n)==t):
            continue
        print(chr(i)+str(n))
    for i in range(1,9):
        if(s+str(i)==t):
            continue
        print(s+str(i))


TT=1
TT=int(input())
for T in range(1,TT+1):
    solution(T)