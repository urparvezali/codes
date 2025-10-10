n = int(input())
a = [int(i) for i in input().split(" ")]
a.sort(reverse=True)
ans = 0
summe = 0
while summe <= (sum(a)/2):
    summe += a[ans]
    ans += 1
print(ans)