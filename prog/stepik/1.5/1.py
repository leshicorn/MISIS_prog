# import sys
# sys.setrecursionlimit(100000)

n, m = map(int, input().split())
g = {i:[] for i in range(1, n+1)}
for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

visited = set()
def dfs(u):
    visited.add(u)
    for v in g[u]:
        if v not in visited:
            dfs(v)

dfs(1)
print(len(visited))
print(*visited)