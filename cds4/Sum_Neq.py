def solve():
    n = int(input())
    v = list(map(int, input().split()))

    s = set(v)

    if n == 4:
        if v[0] + v[1] == v[2] + v[3]:
            print("NO")
        else:
            print("YES")
        return

    if len(s) == 1:
        print("NO")
    else:
        print("YES")



t = int(input())
for _ in range(t):
    solve()
