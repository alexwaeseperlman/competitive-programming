from fractions import Fraction
from decimal import Decimal, getcontext

getcontext().prec = 100

def choose(n, k):
    out = 1
    j = 1
    for i in range(n-k+1, n+1):
        out *= i
        if j <= k: out //= j
        j += 1
    
    return out

wins = 0
for i in range(432, 1001):
    wins += choose(1000, i)

print('{:.12f}'.format(Decimal(wins)/Decimal(2**1000)))
