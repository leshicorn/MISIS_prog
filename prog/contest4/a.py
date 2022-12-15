limit = int(input())
a = [0, 1, 1]
for i in range (limit-1):
    a.append(sum(a[-3:]))
 
print(a[-1])