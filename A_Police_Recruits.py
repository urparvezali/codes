n = int(input())
p = 0
c = 0
l = list(map(int, input().split()))
for x in l:
    if (x < 0):
        if (p > 0):
            p -= 1
        else:
            c += 1
    else:
        p += x

print(c)
