A, B, C = map(int, input().split())

if (A + B + C) % 3 != 0:
    print(-1)
else:
    target = (A + B + C) // 3
    ops = abs(A - target) + abs(B - target) + abs(C - target)
    print(ops)
