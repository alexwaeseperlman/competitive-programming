scores, values = {}, []
winner, max_score = "", 0

n = int(input())

for i in range(n):
    row = input().split(' ')
    name, score = row[0], int(row[1])

    scores[name] = score + scores.get(name, 0)

    values.append((name, scores[name]))

m = max(scores.values())

for name, score in values:
    if score >= m and scores[name] == m:
        print(name)
        break
