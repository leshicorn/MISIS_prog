n, m = map(int, input().split())
a = []
for _ in range(m):
    a += list(map(int, input().split()))
print(a.count(int(input())))