T = int(input())

for _ in range(T):
    n = int(input())
    sticker = []

    for _ in range(2):
        sticker.append(list(map(int, input().split())))

    # 예외
    if n == 1:
        print(max(sticker[0][0], sticker[1][0]))
        continue

    # 초기화
    dp = [[0] * n for _ in range(2)]
    dp[0][0], dp[1][0] = sticker[0][0], sticker[1][0]
    dp[0][1], dp[1][1] = sticker[0][1] + dp[1][0], sticker[1][1] + dp[0][0]

    # 점화식
    for i in range(2, n):
        dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2])
        dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2])

    print(max(dp[0][n - 1], dp[1][n - 1]))
