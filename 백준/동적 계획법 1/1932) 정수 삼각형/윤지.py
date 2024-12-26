n = int(input())
triangle = [list(map(int, input().split())) for _ in range(n)]

dp = triangle

for i in range(n - 2, -1, -1):  
    for j in range(i + 1):  
        dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1])


print(dp[0][0])
