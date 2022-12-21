n, m = map(int, input().split())
g = {}
used = [0]*n

def dfs(v, p):
    used[v] = 1
    for u in g[v]:
        if u != p and (used[u] == 1 or dfs(u, v)):
            return 1
    used[v] = 2
    return 0

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a] = g.get(a, []) + [b]
    g[b] = g.get(b, []) + [a]

if g and dfs(0, -1) or (n > 1 and min(used) == 0):
    print('NO')
else:
    print('YES')
