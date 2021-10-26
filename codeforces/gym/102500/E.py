from decimal import Decimal, getcontext
getcontext().prec = 5
t1, t2, t3, t4 = sorted([Decimal(i) for i in input().split(' ')])
t = Decimal(input())

if t >= ((t2 + t3 + t4) / Decimal('3.0')):
    print('infinite')
else:
    n = Decimal('3.0') * t - t2 - t3

    if n >= t1: print('{:0.2f}'.format(n))
    elif t >= (t1+t2+t3)/Decimal('3.0'): print('{:0.2f}'.format(t1))
    else: print('impossible')
