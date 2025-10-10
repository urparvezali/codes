from itertools import groupby

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ma = {}
    for i, j in groupby(a):
        ma[i] = max(ma.get(i, 0), len(list(j)))

    mb = {}
    for i, j in groupby(b):
        mb[i] = max(mb.get(i, 0), len(list(j)))

    maxi = 0
    for i in ma:
        maxi = max(maxi, ma.get(i, 0) + mb.get(i, 0))

    for i in mb:
        maxi = max(maxi, ma.get(i, 0) + mb.get(i, 0))

    print(maxi)