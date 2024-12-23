N = int(input())

dp = [float('inf')] * (N + 1)
dp[0] = 0

for i in range(1, N + 1):
    j = 1
    while j * j <= i:
        dp[i] = min(dp[i], dp[i - j * j] + 1)
        j += 1

print(dp[N])
