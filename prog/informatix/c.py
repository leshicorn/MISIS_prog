n = int(input())
summ = 0
for i in range(n):
    a = list(map(int, input().split()))
    summ += sum(a)
print(summ // 2)
