from fractions import Fraction

t = int(input())

for i in range(t):
    print(Fraction(int(input()), 100).denominator)
