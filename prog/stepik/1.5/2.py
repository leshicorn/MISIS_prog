import sys
sys.setrecursionlimit(100000)

def dfs(v,g):
    global used
    if v not in used:
        used.add(v)
        for i in g[v]:
            dfs(i,g)
            
n,m = map(int,input().split())
d = {i: [] for i in range(1,n+1)}
for i in range(m):
    x,y = map(int,input().split())
    d[x].append(y)
    d[y].append(x)
dd = set(range(1,n+1))
a = []
while len(dd):
    used = set()
    dfs(dd.pop(),d)
    a.append(sorted(used))
    dd -= used
print(len(a))
for i in sorted(a):
    print(len(i))
    print(*i,'')