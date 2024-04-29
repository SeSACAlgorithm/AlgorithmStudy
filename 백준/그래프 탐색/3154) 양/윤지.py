from collections import deque
from pprint import pprint

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(r, c):
    # 양, 늑대 변수 셋팅(구역 내)
    tmp_sheep = 0
    tmp_wolf = 0

    # 누적 값 전역 변수 처리
    global tot_sheep
    global tot_wolf

    # 방문 예정지가 없을 때까지 반복
    while(queue):
        # 방문
        x, y = queue.popleft()

        # 이때, 시작부터 양 혹은 늑대일 경우 처리
        if board[x][y] == 'o':
            tmp_sheep += 1
        elif board[x][y] == 'v':
            tmp_wolf += 1
        board[x][y] = '#'

        # 탐색
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]

            # 다음 좌표가 범위 안에 있고, 벽이 아닐 경우에 방문 예정지로 넣음
            if 0 <= nx < R and 0 <= ny < C and board[nx][ny] != '#': 
                if board[nx][ny] == 'o':
                    tmp_sheep += 1
                elif board[nx][ny] == 'v':
                    tmp_wolf += 1

                # 다시 읽으면 안되니까 길 막음, 막으므로 방문처리 안해도됨
                board[nx][ny] = '#'

                queue.append((nx, ny))

    # 양이 많으면 양 수 누적, 늑대가 많으면 늑대 수 누적
    if tmp_sheep > tmp_wolf:
        tot_sheep += tmp_sheep
    else:
        tot_wolf += tmp_wolf


R, C = map(int, input().split())

board = [list(input()) for _ in range(R)]

# 초기 셋팅
queue = deque()
tot_sheep, tot_wolf = 0, 0

for r in range(R):
    for c in range(C):
        if board[r][c] != '#':
            queue.append((r, c))
            bfs(r, c)

print(f"{tot_sheep} {tot_wolf}")
