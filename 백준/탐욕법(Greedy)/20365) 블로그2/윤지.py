N = int(input())

strings = list(input())

cur_b = strings[0]
red_b = 0
blue_b = 0

# 연속된 블록 수
if cur_b == 'R':
    red_b += 1
else:
    blue_b += 1

for i in range(1, N):
    if strings[i] != cur_b:
        cur_b = strings[i]
        if cur_b == 'R':
            red_b += 1
        else:
            blue_b += 1

# 최소 작업 횟수 계산
print(min(red_b, blue_b) + 1)
