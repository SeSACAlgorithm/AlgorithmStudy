from collections import deque
from pprint import pprint

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
n, m = map(int, input().split())

road_map = [list([0]*m) for _ in range(n)]

# 방문 예정지
queue = deque()
# 방문지 -> ** 갱신되면 안되는 값이기 때문에 for문 밖에서 선언 **
visited = set()

# 지도 생성
maps = [list(map(int, input().split())) for _ in range(n)]

# 출발지 탐색
for r in range(n):
    for c in range(m):
        if maps[r][c] == 2:
            queue.append((0, r, c))
            break
    if queue:
        break

# 탐색 -> 방문 반복 / 방문이 불가능할때까지
while queue:
    cnt, r, c = queue.popleft()

    if maps[r][c] == 2:
        road_map[r][c] = 0
    else:
        road_map[r][c] = cnt

    for d in range(4):
        nr, nc = r + dr[d], c + dc[d]

        # 지도 범위를 벗어나거나, 못가거나, 이미 방문한 곳이면 넘어감.
        if not (0 <= nr < n and 0 <= nc < m) or maps[nr][nc] == 0 or (nr, nc) in visited:
            continue

        queue.append((cnt+1, nr, nc))
        visited.add((nr, nc))

# 방문할 수 없는 구역 -> maps 에선 1 인데 road_map 에선 0(가지 않았음) 
# => -1 갈 수 있는 길이지만 갈 수 있는 방법이 없었음
for i in range(n):
    for j in range(m):
        if maps[i][j] == 1 and road_map[i][j] == 0:
            road_map[i][j] = -1

for i in road_map:
    for j in i:
        print(j, end=' ')
    print()


