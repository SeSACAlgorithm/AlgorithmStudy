import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

tmp = [[0] * (N + 1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N+1):
        tmp[i][j] = arr[i - 1][j - 1] + tmp[i - 1][j] + tmp[i][j - 1] - tmp[i - 1][j - 1]

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    ans = (tmp[x2][y2]
             - tmp[x1 - 1][y2]
             - tmp[x2][y1 - 1]
             + tmp[x1 - 1][y1 - 1])
    print(ans)
