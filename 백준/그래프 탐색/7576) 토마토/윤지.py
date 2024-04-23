from collections import deque
from pprint import pprint

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

M, N = map(int, input().split())
tomotoes = [list(map(int, input().split())) for _ in range(N)]

# 익은 토마토를 넣을 큐
queue = deque()

# 익은 토마토가 있는지 탐색
for x in range(N):
    for y in range(M):
        if tomotoes[x][y] == 1:
            days = 0
            queue.append((days, x, y))

while queue:
    # 방문
    days, r, c = queue.popleft()

    for d in range(4):
        nr, nc = r + dr[d], c + dc[d]
        # print(f"{ny} {nx} {d}")

        # 토마토가 0이고, 범위에 벗어나지 않을 경우에만 익을 수 있음
        if (0 <= nr < N and 0 <= nc < M) and tomotoes[nr][nc] == 0:
            queue.append((days + 1, nr, nc))
            #print(f"*{nr} {nc}")
            tomotoes[nr][nc] = 1
        ans = days

for x in range(N):
    for y in range(M):
        if tomotoes[x][y] == 0:
            ans = -1

print(ans)
