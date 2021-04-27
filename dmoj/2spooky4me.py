N, L, S = [int(i) for i in input().split(' ')]

difference_array = []
for i in range(N):
    a, b, s = [int(i) for i in input().split(' ')]
    difference_array.append((a, s))
    difference_array.append((b + 1, -s))

difference_array = sorted(difference_array, key=lambda x: x[0])

acc = 0
p = 0

total = difference_array[0][0]

difference_array.append((L, 0))

for i in range(len(difference_array) - 1):
    acc += difference_array[i][1]
    if acc >= S: continue
    total += difference_array[i + 1][0] - difference_array[i][0]

print(total)
