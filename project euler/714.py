import math
import itertools

def binToDec(n):
    out = 0
    while n:
        out *= 10
        out += n & 1
        n >>= 1
    return out

def duodigit():
    printed = set()
    maxMask, mask, ones = 0, 0, 0
    while True:
        mask += 1
        if mask & (mask - 1) == 0 and mask != 0 and mask > maxMask:
            maxMask = mask
            mask = 0
            ones = ones * 10 + 1

        bMask = binToDec(mask)
        aMask = ones - bMask

        for a, b in itertools.product(range(10), repeat=2):
            out = aMask * a + bMask * b
            if out not in printed: yield out
            printed.add(out)

def D(n):
    out = [math.inf] * n

    solved = 0
    for i in duodigit():
        if i == 0: continue
        if solved == n: return out

        for j in range(n):
            if i % (j + 1) == 0 and out[j] > i: 
                out[j] = i
                solved += 1
                print('solved', j + 1)

    return out



print(D(5000))
