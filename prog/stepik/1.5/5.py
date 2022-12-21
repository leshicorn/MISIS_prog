import sys
sys.setrecursionlimit(1000000)

n, m = map(int, input().split())
g = {x: [] for x in range(n)}
res = []
used = [0] * n
fnd = False

def dfs(u, v):
    global res
    global fnd
    used[u] = 1
    if v == u:
        fnd = True
        return
    for i in sorted(g[u]):
        if not used[i]:
            dfs(i, v)
            if fnd:
                res += [i+1]
                return

for _ in range(m):
    a, b = map(int, input().split())
    g[b - 1] = g.get(b - 1, []) + [a - 1]
    g[a - 1] = g.get(a - 1, []) + [b - 1]
u, v = map(int, input().split())

dfs(u - 1, v - 1)
if u != v and fnd:
    res += [u]
    print(*res[::-1])
else:
    print('no solution')