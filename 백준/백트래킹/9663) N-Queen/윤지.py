from pprint import pprint
from collections import deque

def dfs(depth):
    global ans
    # 종료 조건 : 끝까지 다 내려간 경우
    if depth == N:
        ans += 1
        return

    # 중간에 배치할 수 없는 경우 return
    # 탐색 -> N X N 배열 에서 둘 수 있는지 없는지 확인해 보는 것
    for idx in range(N):
        # 위아래 체크배열 확인
        if updown_chk[idx] or right_chk[depth - idx] or left_shk[depth + idx]:
            continue
        # 방문 표기
        # 오른쪽 대각선 depth - idx 가 일정
        # 왼쪽 대각선 depth - idx 가 일정
        updown_chk[idx] = True
        right_chk[depth - idx] = True
        left_shk[depth + idx] = True

        dfs(depth+1)

        updown_chk[idx] = False
        right_chk[depth - idx] = False
        left_shk[depth + idx] = False


N = int(input())
# 경우의 수
ans = 0

# 체스판 생성
arr = [[]*N for _ in range(N)]

# 상하 방문지, 오른쪽 대각선 방문지, 왼쪽 대각선 방문지 체크 배열 생성
updown_chk = [False for _ in range(N)]
right_chk = [False for _ in range(2*N-1)]
left_shk = [False for _ in range(2*N-1)]

dfs(0)

print(ans)
