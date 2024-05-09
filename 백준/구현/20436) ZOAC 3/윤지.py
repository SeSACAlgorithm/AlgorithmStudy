from collections import deque
from pprint import pprint

SL, SR = map(str, input().split())

strings = list(map(str, input()))

keyboard = [['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'],
            ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'],
            ['z', 'x', 'c', 'v', 'b', 'n', 'm']]

dist = 0
left_x, left_y = 0, 0
right_x, right_y = 0, 0

# 처음 손들의 위치를 찾기
for x in range(len(keyboard)):
    for y in range(len(keyboard[x])):
        if keyboard[x][y] == SL:
            left_x, left_y = x, y
        if keyboard[x][y] == SR:
            right_x, right_y = x, y

for i in range(len(strings)):
    tmp = strings[i]

    for x in range(len(keyboard)):
        for y in range(len(keyboard[x])):
            # 문자 위치를 찾고
            if keyboard[x][y] == tmp:
                # 왼 손이 쓰여야하는 상태라면
                if (x < 2 and y < 5) or (x == 2 and y < 4):
                    dist += abs(left_x - x) + abs(left_y - y)
                    left_x, left_y = x, y
                    dist += 1
                    break

                # 오른 손이 쓰여야하는 상태에서
                elif (x < 2 and y >= 5) or (x == 2 and y >= 4):
                    dist += abs(right_x - x) + abs(right_y - y)
                    right_x, right_y = x, y
                    dist += 1
                    break

print(dist)
