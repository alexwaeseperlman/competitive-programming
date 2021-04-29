T = int(input())

for i in range(T):
    n, m, k = [int(i) for i in input().split(' ')]
    print("yes" if (m - 1) + m * (n-1) == k else "no")
