from collections import deque

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    maze = [list(map(int,  input())) for _ in range(N)]

    # 최단 거리를 구하는 문제 -> BFS -> QUEUE 사용
    queue = deque()
    visited = set()


    for r in range(N):
        for c in range(N):
            if maze[r][c] == 2: #출발지 찾기
                queue.append((-1, r, c))
                break

    ans = 0
    while queue:
        # 방문
        cnt, r, c = queue.popleft()
        visited.add((r, c))

        # 도착지면 종료 -> 도착까지의 거리 리턴
        if maze[r][c] == 3:
            ans = cnt
            break

        # 탐색
        # 델타 탐색
        for d in range(4):
            nr, nc = r + dr[d], c + dc[d]

            # 범위를 벗어날 때, 방문 안한 곳을 때, 벽이 아닐 때
            if 0 <= nr < N and 0 <= nc < N and (nr, nc) not in visited and maze[nr][nc] != 1:
                # 좌표 외에, 방문을 하면서 지나간 거리를 큐에 담음
                queue.append((cnt + 1, nr, nc))
                visited.add((nr, nc))

    print(f'#{test_case} {ans}')
    
