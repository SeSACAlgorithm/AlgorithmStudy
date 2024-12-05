N = int(input())
answer = 0
front, end = 1, 1
tmp_sum = 1

while front <= N:
    # 조건 일치
    if tmp_sum == N:
        answer += 1
        tmp_sum -= front
        front += 1
    elif tmp_sum < N:
        end += 1
        tmp_sum += end
    else:
        tmp_sum -= front
        front += 1

print(answer)
