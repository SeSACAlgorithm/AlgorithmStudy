from itertools import combinations

N, M = map(int, input().split())
arr = []
for _ in range(M):
    arr.append(tuple(map(int, input().split())))

tmp = set()

for a, b in arr:
    tmp.add((a, b))
    tmp.add((b, a))

cnt = 0

for i in range(1, N - 1):
        for j in range(i + 1, N):
            for k in range(j + 1, N + 1):
                if (i, j) not in tmp and (j, k) not in tmp and (i, k) not in tmp:
                    cnt += 1


print(cnt)
