from random import randint
print(100)
for i in range(100):
    print(100, 100)
    for j in range(100):
        for k in range(100):
            print(randint(0, 1000000), end=' ')
        print()

