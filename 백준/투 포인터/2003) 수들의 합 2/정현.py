import sys
input = sys.stdin.readline

N, M = map(int, input().split())
a = list(map(int, input().split()))

left = 0
right = 0
cnt = 0

while left <= right and right <= N:
    num = a[left:right]
    sum_num = sum(num)

    if sum_num == M:
        cnt += 1
        right += 1

    elif sum_num < M:
        right += 1

    else:
        left += 1

print(cnt)
