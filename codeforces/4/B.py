d, s = [int(i) for i in input().split(' ')]

days = []
maxs = []
t = 0
for i in range(d):
    a, b = [int(i) for i in input().split(' ')]
    days.append(a)
    maxs.append(b)
    t += a

i = 0
while t < s and i < len(days):
    added = min(s - t, maxs[i] - days[i])
    days[i] += added
    t += added
    i += 1

if t == s:
    print("YES")
    print(' '.join(map(str, days)))
else: print("YES" if s < 0 else "NO")
