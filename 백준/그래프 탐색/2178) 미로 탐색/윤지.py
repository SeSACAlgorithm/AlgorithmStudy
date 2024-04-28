from pprint import pprint
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())

arr = [list(map(int, input())) for _ in range(N)]

# 기본 셋팅
queue = deque()     #방문 예정지
visited = set()     #방문지
ans = 1

# 시작 방문 예정지 설정
queue.append((0, 0, ans))

# 방문 예정지가 빌 때까지 loop
while queue:
    # 방문
    x, y, ans = queue.popleft()

    # 종료 조건
    if x == N-1 and y == M-1:
        print(f"{ans}")
        break

    for d in range(4):
        nx, ny = x + dx[d], y + dy[d]

        # 갈수 있는 경로만 탐색
        if 0 <= nx < N and 0 <= ny < M and arr[nx][ny] == 1 and (nx, ny) not in visited:
            queue.append((nx, ny, ans+1))
            
            # 여기에서 방문 표기 해야 함 -> 시간초과 방지
            visited.add((nx, ny))

