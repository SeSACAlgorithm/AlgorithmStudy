dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def solution(dirs):
    answer = 0

    # 현재위치 : 원점
    x, y = 5, 5
    
    # 방문 경로 저장 (중복 제거)
    visited = set()

    d = 0
    for i in range(len(dirs)):
        if dirs[i] == 'R':
            d = 0
        elif dirs[i] == 'L':
            d = 1
        elif dirs[i] == 'U':
            d = 3
        elif dirs[i] == 'D':
            d = 2

        nx, ny = x + dx[d], y + dy[d]
        if 0 <= nx < 11 and 0 <= ny < 11 :
            # 이전에 지나가지 않은 경로일 경우만 추가, 역방향 제외
            if (x, y, nx, ny) not in visited and (nx, ny, x, y) not in visited:
                visited.add((x, y, nx, ny))
            x, y = nx, ny

    answer = len(visited)
    return answer
