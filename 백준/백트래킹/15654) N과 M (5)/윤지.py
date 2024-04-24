from collections import deque
from pprint import pprint

N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

def dfs(depth):
    # 종료 조건
    if depth == M:
        print(*ans)
        return

    # 배열 돌면서 정답으로 선택한 값인지 탐색
    # M : 배열 길이
    for i in range(N):
        # 방문하지 않은 곳에만
        if not chk[i]:

            ans[depth] = arr[i]
            # 방문 체크
            chk[i] = 1
            dfs(depth + 1)

            # *다른 값 선택했을 경우도 출력해야함으로 방문 초기화*
            chk[i] = 0

# 정답이 들어가는 (출력될) list 선언
ans = [0*M for _ in range(M)]
# 방문 표시할 list 선언
chk = [0*N for _ in range(N)]

dfs(0)



