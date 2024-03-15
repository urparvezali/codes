



from curses.ascii import islower, isupper


def solution(T):
    s=input()
    t=s.reverse()
    print(s)
    ans=""
    cap,sm=0,0
    for c in t:
        if c=='b':
            sm+=1
            continue
        if c=='B':
            cap+=1
            continue
        if cap and isupper(c):
            cap-=1
            continue
        if sm and islower(c):
            sm-=1
            continue
        # ans+=c
    print(ans)

TT=1
TT=int(input())
for T in range(1,TT+1):
    solution(T)