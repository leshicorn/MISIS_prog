p = 10 ** 9 + 9

def fast_power(a, n : int) -> int:
    global p
    if n == 0:
        return 1
    if n % 2 == 0:
        return fast_power(a * a % p, n / 2) % p
    else:
        return (a * fast_power(a, n - 1)) % p


n = int(input())
for i in range(n):
    a = int(input())
    x = fast_power(a, p - 2)
    print(x)
