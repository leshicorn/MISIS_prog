n = int(input())
g = []
used = [0]*n

def dfs(v):
    used[v] = 1
    for u in g[v]:
        if used[u] == 1 or dfs(u):
            return 1
    used[v] = 2
    return 0

flag = 0
for i in range(n):
    a = list(map(int, input().split()))
    g.append([j for j in range(n) if a[j]])
for i in range(n):
    if not used[i] and dfs(i):
        flag = 1
        break
print(flag)