n = int(input())

s = 0
for i in range(n):
    p, v, t = [int(i) for i in input().split(' ')]

    s += (p + v + t) > 1
print(s)
