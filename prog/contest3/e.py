divisor = 10 ** 6 + 7

def smart_diff(a : int, b : int) -> int:
    return ((a % divisor) ** 2 % divisor - (b % divisor) ** 2 % divisor) % divisor

inp = (input().split(' '))
a, b = int(inp[0]), int(inp[1])
print(smart_diff(a, b))