from collections import deque
from pprint import pprint
import math

# x값 감소 -> y값 증가 -> x증가 -> y감소
# 0번째 인덱스 2번 반복, 1번째 인덱스 2번 반복, 2번째 인덱스 2번 반복, 3번째 인덱스 2번 반복 ...
dir_array = [[-1, 0], [0, 1], [1, 0], [0, -1]]

N = int(input())
number = int(input())

# 0판 만듬
arr = [[0]*N for _ in range(N)]

# 시작 점 중간
start = round(N // 2)
x = start
y = start

arr[x][y] = 1

# 숫자 insert 시작
n = 2

while n < N:
    # 0 -> 같은 방향 1번 / 1-> 같은 방향 2번 / 2-> 같은 방향 3번 ... 증가
    for i in range(0, 2*N):
        for j in range(0, int(i / 2) + 1):
            # i는 값이 같으니까 현재 같은 방향으로 이동하고 있음
            nx, ny = x + dir_array[i % 4][0], y + dir_array[i % 4][1]
            # 범위에 해당, 숫자가 아직 안넣어진 경우에 증가하며 값 넣음
            if 0 <= nx < N and 0 <= ny < N and arr[nx][ny] == 0:
                arr[nx][ny] = n
                n += 1
                x, y = nx, ny

ans_x = ""
ans_y = ""

for a in range(len(arr)):
    for b in range(len(arr[a])):
        print(f"{arr[a][b]} ", end= "")

        if arr[a][b] == number:
            ans_x = a
            ans_y = b
    print("")

print(f"{ans_x+1} {ans_y+1}")

