



def solution(T):
    s=str(input())
    
    for i in range(len(s)//2,0,-1):
        if s[i]!='0' and int(s[0:i])<int(s[i:len(s)]):
            print(s[0:i],s[i:len(s)])
            return
    print(-1)

TT=1
TT=int(input())
for T in range(1,TT+1):
    solution(T)