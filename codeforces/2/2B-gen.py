from random import randint
print(1000)
for i in range(1000):
    for j in range(1000):
        print(2**randint(0, 15)*5**randint(0,10) * (randint(0, 100000)), end=' ')
    print()
