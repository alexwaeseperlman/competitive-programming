import random as r
N = 100000
Q = 100000
print(N)
for i in range(N):
    print(r.randint(1, 2000000000), end=' ')
print()

print(Q)
for i in range(Q):
    l = r.randint(1, N)
    e = r.randint(l, N)
    print(l, e)
