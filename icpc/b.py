def check_triangle(a, b, c):
    if a + b > c and a + c > b and b + c > a:
        return 1
    return 0
def check_mas(mas):
    cnt = 0
    for i in range(4):
        for j in range(i, 4):
            if mas[i] != mas[j]:
                cnt += 1
    if cnt == 6:
        return 1
    return 0
            

def f(a, b, c, d):
    mas = []
    for x1 in (a, b, c, d):
        mas.append(x1)
        for x2 in (a, b, c, d):
            mas.append(x2)
            for x3 in (a, b, c, d):
                mas.append(x3)
                for x4 in (a, b, c, d):
                    mas.append(x4)
                    if (check_mas(mas) == 1):
                        if (check_triangle(x1, x3, x2 + x4) == 1 and x1/x2 == x3/x4):
                            print("x1:",x1, "x2:",x2, "x3:",x3, "x4:",x4)
                            print(1)
                            return        
    print(0)
    return


a = int(input())
b = int(input())
c = int(input())
d = int(input())

f(a, b, c, d)

#print(check_triangle(2, 4, 6))