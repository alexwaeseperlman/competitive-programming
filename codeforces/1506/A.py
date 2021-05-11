t = int(input())

for i in range(t):
    rows, cols, x = [int(i) for i in input().split(' ')]
    x -= 1

    r, c = x % rows, x // rows
    print(r * cols + c + 1)
