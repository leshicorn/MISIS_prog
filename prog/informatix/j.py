def f():
    s = input()
    n, m = map(int, s.split())
    st = set()
    for _ in range(m):
        s = input()
        a, b = map(int, s.split())
        t = min(a, b), max(a, b)
        if t not in st:
            st.add(t)
        else:
            break
    if len(st) == m:
        print('NO')
    else:
        print('YES')

f()