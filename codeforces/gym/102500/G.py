from fractions import Fraction
import math

n, k = [int(i) for i in input().split(' ')]
combs = []
for i in range(1, n-k+2):
    combs.append(Fraction(math.comb(n-i, n-k-i+1), math.comb(n, n-k)))
    if combs[-1] < Fraction(1, 10000000000): break


s = [Fraction(i) for i in input().split(' ')]

o = [Fraction(0) for i in range(n)]

for c in range(len(combs)):
    for i in range(n):
        o[i] += combs[c] * s[i-c]

m = sum(o) / 100

for i in range(n):
    print('{:0.12f}'.format(float(o[i] / m)), end=' ')
print()

