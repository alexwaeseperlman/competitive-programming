import random
n = 100000
print(n, n)
for i in range(n):
    print(random.randint(1, n), end=' ')
print()
for i in range(n):
    l = random.randint(1, n)
    r = random.randint(l, n)
    print(l, r)
