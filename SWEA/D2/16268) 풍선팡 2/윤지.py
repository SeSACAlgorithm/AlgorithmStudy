from collections import deque
from pprint import pprint

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

T = int(input())

for t in range(1, T+1):
    N, M = map(int, input().split())
    baloons = [list(map(int, input().split())) for _ in range(N)]

    max = 0
    for x in range(N):
        for y in range(M):
            tmp = 0
            tmp += baloons[x][y]
            for d in range(4):
                nx, ny = x + dx[d], y + dy[d]

                if 0 <= nx < N and 0 <= ny < M:
                    tmp += baloons[nx][ny]

            if max <= tmp:
                max = tmp

    print(f"#{t} {max}")
