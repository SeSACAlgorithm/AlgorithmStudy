from collections import deque
from pprint import pprint

dx = [-1, 1, 0 ,0, -1, 1, -1, 1]
dy = [0, 0, -1, 1, -1, 1, 1, -1]

n = int(input())

bomb_map = [list(map(str, input())) for _ in range(n)]
current_map = [list(map(str, input())) for _ in range(n)]

ans = [list([]*n) for _ in range(n)]

fail = False

for x in range(n):
    for y in range(n):
        # 지뢰가 없으면서 열린칸 -> 숫자가 있어야 함
        if bomb_map[x][y] == '.' and current_map[x][y] == 'x':
            cnt = 0
            for d in range(8):
                nx, ny = x + dx[d], y + dy[d]
                #print(f"nx : {nx} ny : {ny}")
                if ( 0 <= nx < n and 0 <= ny < n ) and bomb_map[nx][ny] == '*':
                    cnt += 1
            ans[x].append(cnt)
        # 열린 칸이 지뢰면 지뢰 모두 표시
        elif bomb_map[x][y] == '*' and current_map[x][y] == 'x':
            ans[x].append('*')
            fail = True
        else:
            if fail == True and bomb_map[x][y] == '*':
                ans[x].append('*')
            else:
                ans[x].append('.')

if fail == True:
    for a in range(len(ans)):
        for b in range(len(ans[a])):
            if bomb_map[a][b] == '*':
                ans[a][b] = '*'


for a in range(len(ans)):
    for b in range(len(ans[a])):
        print(ans[a][b], end = "")
    print("")
