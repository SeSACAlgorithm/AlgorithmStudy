N = int(input())

A_arr = list(map(int, input().split()))

dp = A_arr[:]

for i in range(1, N):
        for j in range(i):
            if A_arr[j] < A_arr[i]:
                dp[i] = max(dp[i], dp[j] + A_arr[i])

print(max(dp))

