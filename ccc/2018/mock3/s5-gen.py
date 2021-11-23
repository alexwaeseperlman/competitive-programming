import random
N=10000
print(N)

for i in range(N):
    c = random.randint(0, 7)
    if c == 0 or c == 1:
        print(['ADD', 'ADDRANGE'][c], random.randint(1, 2000000), random.randint(1, 2000000))
    elif 2 <= c <= 5:
        print(['BUYAMT', 'BUYLOW', 'BUYHIGH', 'COST'][c-2], random.randint(1, 1000000000000))
    else:
        print(['NUMCONES', 'TOTALCOST'][c-6])

