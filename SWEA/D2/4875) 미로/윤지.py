from collections import deque

# 델타 탐색 세팅
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

# 그래프 입력 정보 받음
for t in range(1, int(input())+1):
    N = int(input())
    maze = [list(map(int,  input())) for _ in range(N)]
    
    # 방문 예정지
    stack = deque()
    # 방문지
    visited = set()

    # 출발지 찾기
    for r in range(N):
        for c in range(N):
            if maze[r][c] == 2: 
                # 나 여기서 출발할거야. 출발예정지의 좌표 스택에 저장
                stack.append((r, c))
                break
    
    # 값 초기화
    ans = 0
    
    while stack:
        ## 방문 ##
        r, c = stack.pop()      # pop 시키는 게 방문임
        visited.add((r, c))     # 방문 완료된 좌표 저장, 다시 방문 안하는 거 확인용

        # 3이면 도착지 종료 -> 탈출가능 미로
        if maze[r][c] == 3:
            ans = 1
            break
        
        # 3 아니면 계속 돌면서 탐색
        ## 탐색 ##
        # 델타 탐색 -> x좌표 -1, 1 / y좌표 -1, 1 씩 어디든 움직일 수 있음
        for d in range(4):
            # 다음에 방문할 수 있는 좌표 셋팅
            nr, nc = r + dr[d], c + dc[d]

            # 갈 수 있는 좌표가 (1)갈 수 있는 범위일 때 (2)방문 안 한 곳일 때 (3)벽이 아닐 때 => 해당 좌표 방문 예정지임
            if 0 <= nr < N and 0 <= nc < N and (nr, nc) not in visited and maze[nr][nc] != 1:
                stack.append((nr, nc))

    print(f"#{t} {ans}")
