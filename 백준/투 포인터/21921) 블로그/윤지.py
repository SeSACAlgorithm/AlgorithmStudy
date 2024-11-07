N, X = map(int, input().split())

arr = list(map(int, input().split()))

cur_sum = sum(arr[:X])
max_sum = cur_sum
cnt = 1

for i in range(X, N):
    cur_sum += arr[i] - arr[i-X]

    if cur_sum > max_sum:
        max_sum = cur_sum
        cnt = 1
    elif cur_sum == max_sum:
        cnt += 1

if max_sum != 0:
    print(max_sum)
    print(cnt)
else:
    print('SAD')
