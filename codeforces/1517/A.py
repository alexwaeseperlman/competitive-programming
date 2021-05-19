from math import log10, ceil
t = int(input())

def solve():
    n = int(input())
    count = n // 2050

    if count * 2050 != n:
        print(-1)
        return

    total = 0
    while count > 0:
        total += count % 10
        count //= 10
    print(total)

for i in range(t): solve()
