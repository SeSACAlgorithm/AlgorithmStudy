N, K = map(int, input().split())

coins = []
ans = 0

for _ in range(N):
    coin = int(input())
    coins.append(coin)

coins.sort(reverse=True)

for c in coins:
    if K >= c:
        ans += K // c
        K %= c

print(ans)
