n = int(input())
ans = "YES"
g= [[0]*n for _ in range(n)]

for i in range(n):
    lst = list(map(int, input().split()))
    for j in range(n):
        g[i][j] = lst[j]

for h in range(n):
    for k in range(n):
        if g[h][k] != g[k][h]:
            ans = "NO"
        if g[h][h] !=0:
            ans = "NO"


print(ans)
