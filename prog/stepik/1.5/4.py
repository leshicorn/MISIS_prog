n, k = map(int, input().split())

if k == 0:
    print(n)
elif k == 1:
    print(1)
else:
    if k <= n:
        print(k // 2 + 1)
    else:
        if k >= n * 2:
            print(n)
        else:
            print(k - n - 1 + (n - (k - n) - 1) // 2 + 1)