a, b = [int(i) for i in input().split(' ')]
a = bin(a)[2:]
b = bin(b)[2:]

good = lambda a, b: (b.replace(a, "", 1) == ((len(b) - len(a)) * '1'))
check = a == b
check = check or good(a+'1', b)
check = check or good((a+'1')[::-1], b)

while a[-1] == '0': a = a[:-1]

check = check or good(a,b)
check = check or good(a[::-1],b)

if check: print("YES")
else: print("NO")
