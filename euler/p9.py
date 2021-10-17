for n in range(100):
    for m in range(n, 100):
        a = pow(m, 2) - pow(n, 2)
        b = 2 * m * n
        c = pow(m, 2) + pow(n, 2)
        if (a + b + c == 1000):
            print(a, b , c)
            print(a * b * c)
            break
