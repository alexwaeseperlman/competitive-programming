# Calculate the probability of rolling a sum within a certain range using N, F-sided dice
n, a, b = [int(i) for i in input().split(' ')]

dp = [([0] * (n * 6+1)) for i in range(n+1)]

for i in range(1, 6*n+1):
    dp[1][i] = min(i, 6)

for i in range(2, n+1):
    for j in range(0, n*6+1):
        dp[i][j] = dp[i][max(j-1, 0)] - dp[i-1][max(j-6-1, 0)] + dp[i-1][max(j-1, 0)]


print("{:.6f}".format((dp[n][b]-dp[n][a-1])/(6**n)))
