def tmp_key(arr):
    return arr[1], arr[0]

N = int(input())
arr = []

for _ in range(N):
    A, B = map(int, input().split())
    arr.append((A, B))

arr.sort(key = tmp_key)

cnt = 0
end_time = 0

for a, b in arr:
    if a >= end_time:
        cnt += 1
        end_time = b

print(cnt)
