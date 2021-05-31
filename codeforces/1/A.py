n, m, a = [int(i) for i in input().split(' ')]

print(((n + a - 1) // a) * ((m + a - 1) // a))
