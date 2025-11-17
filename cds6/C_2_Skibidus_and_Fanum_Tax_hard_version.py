import sys


def can_sort_array(test_cases):
    results = []
    for n, m, a, b in test_cases:
        a.sort()
        b.sort()

        # Transform a[i] using b[j] greedily
        for i in range(n):
            a[i] = b[-1] - a[i]  # Maximize small values

        if sorted(a) == a:
            results.append("YES")
        else:
            results.append("NO")

    sys.stdout.write("\n".join(results) + "\n")


if __name__ == "__main__":
    t = int(sys.stdin.readline().strip())
    test_cases = []

    for _ in range(t):
        n, m = map(int, sys.stdin.readline().split())
        a = list(map(int, sys.stdin.readline().split()))
        b = list(map(int, sys.stdin.readline().split()))
        test_cases.append((n, m, a, b))

    can_sort_array(test_cases)
