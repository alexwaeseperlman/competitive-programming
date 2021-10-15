from itertools import combinations
t = int(input())

def solve():
    n = int(input())
    days = [set(), set(), set(), set(), set()]
    for i in range(n):
        selected = [int(i) for i in input().split()]
        for j in range(5):
            if selected[j]: days[j].add(i)
    for a, b in combinations(days, 2):
        inter = a.intersection(b)
        if len(a-b) <= n//2 and len(a-b) + len(inter) >= n//2 and len(a.union(b)) == n:
            print("YES")
            return
    print("NO")


for i in range(t):
    solve()
