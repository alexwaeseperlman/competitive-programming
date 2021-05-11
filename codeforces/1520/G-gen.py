from random import randint

print(2000, 2000, 1)
for i in range(2000):
    for j in range(2000):
        print(max(randint(-100, 100), -1), end=" ")
    print()

