from decimal import Decimal, getcontext
getcontext().prec = 100

import math

a = Decimal(1)
target = (Decimal(2)/(Decimal("1.9999"))-1)
i = Decimal(0)
l4 = Decimal(4)
oh = Decimal("0.5")
oq = Decimal("1.5")
while a > target:
  a *= (i*i + oq*i + oh) / (i*i + 2*i + 1)
  i += 1
  if i % 1000000 == 0: print(i, 2/(a+1))

print(i)
