# def plus_and_split(a, b, c, d, divisor : int) -> int:
#     ((a % divisor * d % divisor + b % divisor * c % divisor) / (b % divisor * d % divisor)) % divisor

inp = (input().split(' '))
a, b, c, d = (int(inp[0]), int(inp[1]), int(inp[2]), int(inp[3]))
divisor = 10 ** 9 + 7
a = a % divisor
b = b % divisor
c = c % divisor
d = d % divisor
chisl = (a * d) % divisor + (b * c) % divisor
znam = (b * d) % divisor
res = (chisl / znam)
print(int(res))