from collections import deque

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def solution(maps):
    answer = 0

    n, m = len(maps), len(maps[0])
    answer = -1
    # 방문 예정지, 방문지 선언
    queue = deque()
    visited = set()

    # 출발지 = 0, 0 / 도착지 = n,m
    queue.append((1, 0, 0))

    while queue:
        # 방문
        cnt, r, c = queue.popleft()
        # 시간 제한에 걸림. 생략
        #visited.add((r, c))

        # 도착지(n-1, m-1) 이면 멈춤
        if r == n-1 and c == m-1:
            answer = cnt
            break

        # 델타 탐색
        for d in range(4):
            # 다음 좌표
            nr, nc = r + dr[d], c + dc[d]

            # 벽(0) 아니고, 범위 포함, 방문안한 경우에만 append
            if (0 <= nr < n and 0 <= nc < m) and maps[nr][nc] != 0 and (nr, nc) not in visited:
                queue.append((cnt + 1, nr, nc))
                visited.add((nr, nc))

    return answer
