cnt = int(input())

arr = []
ans = 0

for i in range(cnt):
    arr.append(int(input()))

if cnt == 1:
    print(arr[0])
else:
    dp = [0] * cnt
    dp[0] = arr[0]
    dp[1] = arr[0] + arr[1]
    if cnt > 2:
        dp[2] = max(arr[0] + arr[2], arr[1] + arr[2])
        for i in range(3, cnt):
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i])

    print(dp[-1])
