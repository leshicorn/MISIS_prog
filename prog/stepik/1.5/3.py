# import sys
# sys.setrecursionlimit(100000)

n, m = map(int, input().split())
g = {x: [] for x in range(n)}
res = []
used = [0]*n

def dfs(v):
    global res
    res += [v+1]
    used[v] = 1
    for i in g[v]:
        if not used[i]:
            dfs(i)

for _ in range(m):
    a, b = map(int, input().split())
    g[b-1] = g.get(b-1, []) + [a-1]
dfs(0)
print(*sorted(res))