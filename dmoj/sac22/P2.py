import math
from decimal import Decimal
L, H, W = [int(i) for i in input().split(' ')]
D = int(input())

print(Decimal(L*H*W) - Decimal(H)*Decimal(math.pi) * Decimal(D)**2 / Decimal('4.0'))
