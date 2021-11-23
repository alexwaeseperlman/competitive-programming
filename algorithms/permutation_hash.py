import math

# Returns the number of permutations that are lexicographically less than or equal to p
# e.g. 1, 2, 3, 4 <= 1, 3, 2, 4
#      1, 2, 4, 3
#      1, 3, 2, 4
# Therefore p([1, 3, 2, 4]) == 3

def h(p, arr=[]):
    if len(p) == 0: return 1
    out = (max(0, p[0] - sum(j < p[0] for j in arr) - 1)) * math.factorial(len(p)-1)
    out += h(p[1:], arr + [p[0]])
    return out

print(h([int(i) for i in input().split(' ')]))

