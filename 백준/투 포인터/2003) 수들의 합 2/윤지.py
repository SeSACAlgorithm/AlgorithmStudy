N, M = map(int, input().split())

arr = list(map(int, input().split()))

start = 0
tmp, ans = 0, 0

for i in range(N):
    tmp += arr[i]

    while tmp > M and start <= i:
        tmp -= arr[start]
        start += 1

    if tmp == M:
        ans += 1

print(ans)
