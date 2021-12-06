import cmath
import math
def fft(coef, inv=False):
    if len(coef) == 1: return coef

    n = 1
    while n < len(coef):
        n *= 2
    coef += [0] * (n-len(coef))
    n=len(coef)

    vals = [0] * n
    a, b = fft(coef[::2], inv=inv), fft(coef[1::2], inv=inv)

    xn, x = cmath.exp(-(2 * math.pi * 1j)/n), 1
    if inv:
        xn = 1/xn;

    for i in range(n//2):
        vals[i] = a[i] + x*b[i]
        vals[i+n//2] = a[i] - x*b[i]
        if inv:
            vals[i] /= 2
            vals[i+n//2] /= 2
        x *= xn

    return vals

def polynomial_product(a, b):
    target = len(a)+len(b)
    a += [0] * (target-len(a))
    b += [0] * (target-len(b))

    out = []
    for l, r in zip(fft(a), fft(b)):
        out.append(l*r)

    # remove zero padding
    out = [round(i.real) for i in fft(out, inv=True)]
    last = 0
    for i in range(len(out)):
        if out[i] != 0: last = i
    return out[:last+1]

def polynomial_exp(a, n):
    out = [1]
    x = a
    i = 1
    while i <= n:
        if n&i: out = polynomial_product(out, x)
        x = polynomial_product(x, x)
        i <<= 1

    return out

print(*polynomial_exp([1, 1], 20))


