N = int(input())
arr = [int(input()) for _ in range(N)]
arr.sort(reverse=True)

ans = 0

for i in range(len(arr)):
    ans = max(ans, arr[i] * (i + 1))

print(ans)




