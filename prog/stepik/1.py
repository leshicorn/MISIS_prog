n, m = map(int, input().split())
d = {}
for i in range(1, n):
    for j in range(i + 1, n + 1):
        s = str(i) + str(j)
        d[s] = 0
for i in range(m):
    a, b = map(int, input().split())
    if a > b:
        b, a = a, b
    k = str(a) + str(b)
    d[k] += 1
    ans = 0
for i in d:
    if d[i] >= 2:
        ans += 1
print(ans)