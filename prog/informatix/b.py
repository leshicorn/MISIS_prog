n = int(input())
res = 0
for i in range(n):
    a = list(map(int, input().split()))
    res += a[i]
if res > 0:
    print("YES")
else:
    print("NO")

