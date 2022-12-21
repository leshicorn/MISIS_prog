n, m = map(int, input().split())
e = {i: [] for i in range(1, n+1)}
cnt = 0
for i in range(m):
    v1, v2 = map(int, input().split())
    vmin = min(v1, v2)
    vmax = max(v1, v2)
    e[vmin].append(vmax)

for i in range(1, n + 1):
    du = set(e[i])
    for j in du:
        if e[i].count(j) >= 2:
            cnt += 1
    
print(cnt)