from collections import deque
from pprint import pprint

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def BFS(y, x):
    # 방문예정지, 방문지 선언
    queue = deque()
    #visited = set()

    # 시작하는 길을 방문 예정지에 넣음
    queue.append((y, x))

    while queue:
        # 방문, 좌표 값을 0으로 바꿔서 다신 그 길을 갈 수 없게...
        y, x = queue.popleft()

        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]

            # 이 배추밭을 방문 했나, 다음 좌표가 범위에 있나, 갈 수 있는 길인가(1) => 통과하면 APPEND
            if (0 <= ny < N and 0 <= nx < M) and maps[ny][nx] == 1: #and (nx, ny) not in visited:
                queue.append((ny, nx))
                maps[ny][nx] = 0


for tc in range(int(input())):
    M, N, K = map(int, input().split())

    # 0 판 생성
    maps = [[0]*M for _ in range(N)]

    # 배추 갯수만큼 돌아
    for _ in range(K):
        # 좌표 입력 받음, 좌표에 배추 심음
        r, c = map(int, input().split())

        # 좌표 입력 받을 때, x, y 순서 확인
        maps[c][r] = 1

    ans = 0

    # 배추 심을 수 있는 길만 BFS
    for x in range(N):
        for y in range(M):
            if maps[x][y] == 1:
                # BFS 돌면서 갈 수 있는 길을 탐색
                BFS(x, y)
                ans += 1
    print(ans)

