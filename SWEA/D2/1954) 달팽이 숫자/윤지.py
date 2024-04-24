from collections import deque
from pprint import pprint

T = int(input())

# y값 증가 -> x값 증가 -> y감소 -> x감소
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
for t in range(T):
    num = int(input())

    # 0으로 채워진 배열 생성
    arr = [[0]* num for _ in range(num)]

    # 0, 0부터 채워야함
    x = 0
    y = -1
    # ex ) 3*3 = 9 개의 숫자가 배열에 들어감
    for n in range(0, num*num):

        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]

            # 범위에 포함, 배열이 0일 경우에만 값 넣음
            if ( 0 <= nx < num and 0 <= ny < num) and arr[nx][ny] == 0:
                arr[nx][ny] = n + 1
                x, y = nx, ny
                break

    # 츌력
    print(f"#{t+1}")
    for i in range(num):
        for j in range(num):
            print(f"{arr[i][j]} ", end = "")
        print("")
