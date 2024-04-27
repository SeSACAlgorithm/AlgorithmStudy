from pprint import pprint

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y, num):
    # 현재 좌표 값, 실제 값 담긴 스택 선언
    stk = [(x, y, num)]

    # 스택이 빌 때까지 순회 (만들어진 숫자가 6이라면 멈춤)
    while stk:
        # 그 좌표에 방문
        x, y, num = stk.pop()

        # num 길이가 6자리면 집합에 포함시키고 멈춤
        if len(num) == 6:
            numbers.add(num)
            continue

        # 사방탐색하여 갈 수 있는 좌표일 경우를 탐색
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]

            # 범위에 있다면 그 좌표로 갈 수 있음
            if 0 <= nx < 5 and 0 <= ny < 5:
                # 다음 방문할 좌표, 현재까지 만들어진 숫자 + 다음 좌표의 숫자 값
                stk.append((nx, ny, num + arr[nx][ny]))


arr = [list(map(str, input().split())) for _ in range(5)]

# 세팅
# 만들어질 수 있는 수 저장할 배열 선언, 중복 방지
numbers = set()

# 배열을 모두 돌면서 순회
for i in range(5):
    for j in range(5):
        # 숫자 시작되는 첫 값 : arr[i][j]
        dfs(i, j, arr[i][j])

print(len(numbers))
