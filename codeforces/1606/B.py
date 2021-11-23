import math
t = int(input())

for i in range(t):
    n, k = [int(i) for i in input().split(' ')]
    s = 0
    t = 1
    while t < n and t < k:
        t *= 2
        s += 1

    print(s + (n-t+k-1)//k)


