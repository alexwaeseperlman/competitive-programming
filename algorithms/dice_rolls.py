# Calculate the probability of rolling a sum within a certain range using N, F-sided dice
N_DICE = int(input('How many dice? '))
FACES = int(input('How many faces? '))
MIN = int(input('What is the min roll? '))
MAX = int(input('What is the max roll? '))

if MAX > N_DICE * FACES or MAX < 0 or MIN > MAX or MIN < 0:
    print("Can't roll between",MIN, MAX, "with those dice")
    exit()

dp = [([0] * (N_DICE * FACES+1)) for i in range(N_DICE+1)]

for i in range(1, FACES*N_DICE+1):
    dp[1][i] = min(i, FACES)

for i in range(2, N_DICE+1):
    for j in range(0, N_DICE*FACES+1):
        dp[i][j] = dp[i][max(j-1, 0)] - dp[i-1][max(j-FACES-1, 0)] + dp[i-1][max(j-1, 0)]


print("There are", "{:.4E}".format(dp[N_DICE][MAX]-dp[N_DICE][MIN-1]), "ways to roll the numbers between", "{:}-{:}".format(MIN, MAX), "(inclusive) with", N_DICE, "d-" + str(FACES) + ". That is a probability of", "{:.2%}".format((dp[N_DICE][MAX]-dp[N_DICE][MIN-1])/(FACES**N_DICE)))
