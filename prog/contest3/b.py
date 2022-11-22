def fast_power(a, n : int) -> int:
    if n == 0:
        return 1
    if n % 2 == 0:
        return fast_power(a * a, n / 2)
    else:
        return a * fast_power(a, n - 1)

print(fast_power(float(input()), int(input())))