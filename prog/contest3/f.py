divisor = 10 ** 6 + 3

def fact(n : int) -> int:
    global divisor
    ans = 1
    for i in range(1, n + 1):
        ans *= i
        ans = ans % divisor
    return ans % divisor

def factmod(n, p):
        res = 1
        while n > 1:
            res = (res * (p - 1 if int(n / p) % 2 else 1)) % p
            for i in range(2, n % p + 1):
                res = (res * i) % p  
            n = int(n / p)
        return res % p

n = int(input())
print(fact(n),end=' ') 
print(factmod(n, divisor))