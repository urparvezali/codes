
def solution(T):
    n=int(input())
    a=list(map(int,input().split()))
    st=set()
    t=2
    while t<10**17:
        for j in range(n):
            st.add(a[j]%t)
            if len(st)>2:
                break
        if len(st)==2:
            break
        else:
            st.clear()
        t*=2
    print(t)

TT=1
TT=int(input())
for T in range(1,TT+1):
    solution(T)